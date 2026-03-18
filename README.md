[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/C6LvhTtM)
# Preemptive Priority CPU Scheduling (priority.c)

## Description
This project implements **Preemptive Priority CPU Scheduling** in C.  
In this scheduling algorithm, the CPU is assigned to the process with the **highest priority**.  
If a new process arrives with a **higher priority**, it **preempts** the currently running process.

In this implementation:
- **Higher numeric value = Higher priority**
- The scheduler checks at every time unit to determine the highest priority process available.

## Input Format

n
PID1 AT1 BT1 PR1
PID2 AT2 BT2 PR2
...
PIDn ATn BTn PRn


Where:
- **n** – number of processes  
- **PID** – process ID  
- **AT** – arrival time  
- **BT** – burst time  
- **PR** – priority  

## Sample Input

5
P1 0 5 2
P2 1 3 4
P3 2 4 1
P4 3 2 3
P5 4 6 5


## Sample Output

Waiting Time:
P1 5
P2 6
P3 14
P4 8
P5 0
Turnaround Time:
P1 14
P2 9
P3 18
P4 10
P5 6
Average Waiting Time: 7.40
Average Turnaround Time: 11.40


## Performance Metrics

**Turnaround Time (TAT)**  

TAT = Completion Time - Arrival Time


**Waiting Time (WT)**  

WT = Turnaround Time - Burst Time


## Compilation
Use the following command to compile the program:


gcc priority.c -o priority


## Execution
Run the program using:


./priority


Then provide the input in the required format.

## Files in the Project
- `priority.c` – C program implementing preemptive priority scheduling  
- `autograde.json` – JSON file for automated testing  
- `README.md` – Project documentation

## Author
Operating Systems Lab – CPU Scheduling Assignment
