#include <stdio.h> 
#include <stdlib.h> 
#define MAX 10 
typedef struct 
{ 
 int pid; // Process ID 
 int burst_time; // Burst time 
 int waiting_time; // Waiting time 
 int turnaround_time; // Turnaround time 
} Process; 
void calculateWaitingTime(Process processes[], int n) 
{ 
 processes[0].waiting_time = 0; 
 for (int i = 1; i < n; i++) 
{ 
 processes[i].waiting_time = processes[i-1].waiting_time + processes[i 1].burst_time; 
 } 
} 
void calculateTurnaroundTime(Process processes[], int n) 
{  for (int i = 0; i < n; i++) 
{ 
 processes[i].turnaround_time = processes[i].waiting_time +  processes[i].burst_time; 
 } 
} 
void printProcesses(Process processes[], int n) 
{ 
 printf("PID\tBurst Time\tWaiting Time\tTurnaround Time\n");  
for (int i = 0; i < n; i++)
 { 
 printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time,  processes[i].waiting_time, processes[i].turnaround_time); 
 } 
} 
void roundRobinScheduling(Process processes[], int n, int quantum)
 {  int remaining_time[n]; 
 for (int i = 0; i < n; i++)
 remaining_time[i] = processes[i].burst_time; 
 int t = 0; 
 while (1) 
{ 
 int done = 1; 
 for (int i = 0; i < n; i++) 
{ 
 if (remaining_time[i] > 0) 
{ 
 done = 0; 
 if (remaining_time[i] > quantum)
 { 
 t += quantum; 
 remaining_time[i] -= quantum; 
 } else 
{ 
 t += remaining_time[i]; 
 processes[i].waiting_time = t - processes[i].burst_time;  remaining_time[i] = 0; 
 } 
 } 
 } 
 if (done == 1) 
 break; 
 } 
} 
void feedbackQueueScheduling(Process processes[], int n, int quantum[], int  num_levels) { 
 for (int i = 0; i < num_levels; i++) 
{ 
 printf("\nRunning processes in queue level %d with quantum %d:\n", i+1,  quantum[i]); 
 roundRobinScheduling(processes, n, quantum[i]); 
 calculateTurnaroundTime(processes, n); 
 printProcesses(processes, n); 
 } 
} 
int main()
 { 
 int n, num_levels; 
 printf("Enter the number of processes: "); 
 scanf("%d", &n);
 Process processes[MAX]; 
 for (int i = 0; i < n; i++) 
{ 
 processes[i].pid = i+1; 
 printf("Enter burst time for process %d: ", i+1); 
 scanf("%d", &processes[i].burst_time); 
 } 
 printf("Enter the number of queue levels: "); 
 scanf("%d", &num_levels); 
 int quantum[num_levels]; 
 for (int i = 0; i < num_levels; i++) 
{ 
 printf("Enter time quantum for level %d: ", i+1); 
 scanf("%d", &quantum[i]); 
 } 
 feedbackQueueScheduling(processes, n, quantum, num_levels); 
 return 0; 
} 
