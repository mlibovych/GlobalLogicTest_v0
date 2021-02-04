#include <iostream>
#include <stdexcept>
#include <chrono>
#include <thread>

#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

int getPeriod(int argc, char *argv[]) {
    int  period = 0;

    if (argc != 2) {
        std::cerr << "usage: ./parent period" << std::endl;
        exit(1);
    }
    try {
        period = std::stoi(argv[1]);
    }
    catch (std::exception& ex) {
        std::cerr << "period should be an integer" << std::endl;
        exit(1);
    }
    if (period < 1 || period > 1000) {
        std::cerr << "period should be in range between 1 and 1000 ms << std::endl;" << std::endl;
        exit(1);
    }
    return period;
}

int main(int argc, char *argv[]) {   
    int period = getPeriod(argc, argv); //get delay
    int *intPtr = static_cast<int *> (mmap(NULL, 256, PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS, -1, 0)); //init shared memory
    
    std::cout << "Hi, I am parent process" << std::endl;
    *intPtr = 0;
    while (1) {
        pid_t pid, wpid;
        int status;

        pid = fork(); //start new proc
        if (pid == 0) {
            std::cout << "Hi, I am child process" << std::endl;
            while (1) {
                std::cout << (*intPtr)++ << std::endl; //increase counter
                std::this_thread::sleep_for(std::chrono::milliseconds(period)); //delay
            }
            exit(EXIT_FAILURE);
        }
        else if (pid < 0) {
            perror("fork error");
        }
        else {
            do {
                wpid = waitpid(pid, &status, WUNTRACED); //wate until child proc terminated
            }
            while (!WIFEXITED(status) && !WIFSIGNALED(status));
        }
    }
    return 0;
}