#include "../include/Scheduler.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

void Scheduler::fcfs(std::vector<Process>& processes) {
    std::sort(processes.begin(), processes.end(), [](Process& a, Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;
    for (auto& p : processes) {
        p.startTime = std::max(currentTime, p.arrivalTime);
        currentTime = p.startTime + p.burstTime;
        p.completionTime = currentTime;
        p.turnaroundTime = p.completionTime - p.arrivalTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;
    }
}

void Scheduler::sjf(std::vector<Process>& processes) {
    int currentTime = 0, completed = 0, n = processes.size();
    std::vector<bool> isDone(n, false);

    while (completed < n) {
        int idx = -1, minBurst = 1e9;

        for (int i = 0; i < n; ++i) {
            if (!isDone[i] && processes[i].arrivalTime <= currentTime && processes[i].burstTime < minBurst) {
                minBurst = processes[i].burstTime;
                idx = i;
            }
        }

        if (idx != -1) {
            auto& p = processes[idx];
            p.startTime = currentTime;
            p.completionTime = currentTime + p.burstTime;
            p.turnaroundTime = p.completionTime - p.arrivalTime;
            p.waitingTime = p.turnaroundTime - p.burstTime;
            currentTime = p.completionTime;
            isDone[idx] = true;
            completed++;
        } else {
            currentTime++;
        }
    }
}

void Scheduler::roundRobin(std::vector<Process>& processes, int timeQuantum) {
    int currentTime = 0;
    std::vector<Process*> queue;
    for (auto& p : processes) {
        p.remainingTime = p.burstTime;
    }

    int idx = 0;
    while (true) {
        bool done = true;
        for (auto& p : processes) {
            if (p.remainingTime > 0) {
                done = false;
                if (p.arrivalTime <= currentTime) {
                    int execTime = std::min(timeQuantum, p.remainingTime);
                    if (p.startTime == -1)
                        p.startTime = currentTime;
                    currentTime += execTime;
                    p.remainingTime -= execTime;
                    if (p.remainingTime == 0) {
                        p.completionTime = currentTime;
                        p.turnaroundTime = p.completionTime - p.arrivalTime;
                        p.waitingTime = p.turnaroundTime - p.burstTime;
                    }
                } else {
                    currentTime++;
                }
            }
        }
        if (done) break;
    }
}

void Scheduler::printTable(const std::vector<Process>& processes) {
    std::cout << "PID\tArrival\tBurst\tStart\tCompletion\tWaiting\tTurnaround\n";
    for (const auto& p : processes) {
        std::cout << p.pid << "\t" << p.arrivalTime << "\t" << p.burstTime << "\t"
                  << p.startTime << "\t" << p.completionTime << "\t\t"
                  << p.waitingTime << "\t" << p.turnaroundTime << "\n";
    }
}

void Scheduler::exportToCSV(const std::vector<Process>& processes, const std::string& filename) {
    std::ofstream file(filename);
    file << "PID,Arrival,Burst,Start,Completion,Waiting,Turnaround\n";
    for (const auto& p : processes) {
        file << p.pid << "," << p.arrivalTime << "," << p.burstTime << ","
             << p.startTime << "," << p.completionTime << ","
             << p.waitingTime << "," << p.turnaroundTime << "\n";
    }
    file.close();
}
