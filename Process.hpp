#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <string>

class Process {
public:
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    int startTime;

    Process(int pid, int arrival, int burst);
};

#endif
