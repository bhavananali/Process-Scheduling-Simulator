
# 🧠 Process Scheduling Simulator

A modular C++ project that simulates classical **CPU Scheduling Algorithms** used in operating systems. It includes support for both **preemptive** and **non-preemptive** scheduling strategies, and outputs metrics like average waiting time, turnaround time, and a Gantt chart.

---

## 📁 Project Structure

```
Process-Scheduling-Simulator/
│
├── include/
│   ├── Process.hpp         # Class definition for Process
│   └── Scheduler.hpp       # Abstract base class + algorithm declarations
│
├── src/
│   ├── main.cpp            # Entry point and user interaction
│   ├── Process.cpp         # Implementation of Process class
│   └── Scheduler.cpp       # Implementation of scheduling algorithms
```

---

## ⚙️ Features

- ✅ First Come First Serve (FCFS)
- ✅ Shortest Job First (SJF)
- ✅ Shortest Remaining Time First (SRTF)
- ✅ Round Robin (RR)
- ✅ Priority Scheduling (Preemptive & Non-preemptive)

### 🔍 Outputs:
- Gantt Chart
- Average Waiting Time
- Average Turnaround Time

---

## 🚀 How to Build and Run

### 📌 Prerequisites

- C++17 or later
- g++ compiler or any standard C++ compiler
- Linux/macOS/Windows (via WSL or MinGW)

### 🔧 Build

```bash
g++ -std=c++17 -Iinclude src/*.cpp -o scheduler
```

### ▶️ Run

```bash
./scheduler
```

---

## 📊 Sample Output

```
Enter number of processes: 4
Input Process ID, Arrival Time, Burst Time, [Priority]

Select Algorithm:
1. FCFS
2. SJF
3. Round Robin
4. Priority

Gantt Chart:
| P1 | P2 | P3 | ...

Average Waiting Time: 5.25
Average Turnaround Time: 9.50
```

---

## 🛠️ Tech Stack

- **Programming Language**: C++
- **Paradigms**: Object-Oriented Programming (OOP)
- **Standard Library**: STL – Vectors, Queues, Maps
- **Compiler**: g++

---

## 💡 Future Extensions

- Add support for:
  - Multilevel Queue Scheduling
  - Aging for starvation avoidance
  - IO burst simulation
- GUI Frontend using Qt or ImGui
- JSON/CSV Input-Output support
- Real-time simulation with animation

---

## 👩‍💻 Author

**Nali Bhavana**  
M.Tech Artificial Intelligence, IIT  
Roll No: 24AI06013

---

## 📄 License

This project is licensed under the MIT License. Feel free to use, modify, and distribute it for academic or personal learning purposes.

---

## 🔗 Related Projects

- [Linux CPU Scheduler](https://en.wikipedia.org/wiki/Scheduling_(computing))
- [MIT 6.828 OS Labs](https://pdos.csail.mit.edu/6.828/2020/)

---

## 📬 Feedback / Contact

For suggestions or improvements, feel free to raise an issue or contact via GitHub.
