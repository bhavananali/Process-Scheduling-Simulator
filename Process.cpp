#include "include/Process.hpp"

Process::Process(int pid, int arrival, int burst)
    : pid(pid), arrivalTime(arrival), burstTime(burst), remainingTime(burst),
      completionTime(0), waitingTime(0), turnaroundTime(0), startTime(-1) {}
