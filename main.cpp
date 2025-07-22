#include "../include/Scheduler.hpp"
#include <iostream>
#include <vector>

int main() {
    std::vector<Process> processes = {
        Process(1, 0, 5),
        Process(2, 1, 3),
        Process(3, 2, 8),
        Process(4, 3, 6)
    };

    std::cout << "Running FCFS Scheduling...\n";
    Scheduler::fcfs(processes);
    Scheduler::printTable(processes);
    Scheduler::exportToCSV(processes, "fcfs.csv");

    std::cout << "\nRunning SJF Scheduling...\n";
    Scheduler::sjf(processes);
    Scheduler::printTable(processes);
    Scheduler::exportToCSV(processes, "sjf.csv");

    std::cout << "\nRunning Round Robin Scheduling...\n";
    Scheduler::roundRobin(processes, 2);
    Scheduler::printTable(processes);
    Scheduler::exportToCSV(processes, "rr.csv");

    return 0;
}
