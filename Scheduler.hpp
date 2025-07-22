#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include "Process.hpp"
#include <vector>
#include <string>

class Scheduler {
public:
    static void fcfs(std::vector<Process>& processes);
    static void sjf(std::vector<Process>& processes);
    static void roundRobin(std::vector<Process>& processes, int timeQuantum);
    static void printTable(const std::vector<Process>& processes);
    static void exportToCSV(const std::vector<Process>& processes, const std::string& filename);
};

#endif
