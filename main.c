#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct
{
 int arrival_time;
 int burst_time;
 int completion_time;
 int tat;
 int waiting_time;
} process;
int main(void)
{
 int n = 0;
 printf("Enter the number of processes: ");
 scanf("%d", &n);
process *list = (process *)malloc(n * sizeof(process));
 for (int i = 0; i < n; i++)
 {
 printf("P%d ", i + 1);
 scanf("%d %d", &list[i].arrival_time, &list[i].burst_time);
 }
 int current_time = 0;
 int completed = 0;
 bool *process_completed = (bool *)malloc(n * sizeof(bool));
 for (int i = 0; i < n; i++) process_completed[i] = false;
 while (completed < n)
 {
 int idx = -1;
 int min_burst = 1e9;
 for (int i = 0; i < n; i++)
 {
 if (!process_completed[i] && list[i].arrival_time <= current_time)
 {
 if (list[i].burst_time < min_burst)
 {
min_burst = list[i].burst_time;
 idx = i;
 }
 }
 }
 if (idx == -1)
 {
 current_time++;
 }
 else
 {
 current_time += list[idx].burst_time;
 list[idx].completion_time = current_time;
 list[idx].tat = list[idx].completion_time - list[idx].arrival_time;
 list[idx].waiting_time = list[idx].tat - list[idx].burst_time;
 process_completed[idx] = true;
 completed++;
 }
 }
 float total_wt = 0, total_tat = 0;
printf("\nWaiting Time:\n");
 for (int i = 0; i < n; i++)
 {
 printf("P%d %d\n", i + 1, list[i].waiting_time);
 total_wt += list[i].waiting_time;
 }
 printf("Turnaround Time:\n");
 for (int i = 0; i < n; i++)
 {
 printf("P%d %d\n", i + 1, list[i].tat);
 total_tat += list[i].tat;
 }
 printf("Average Waiting Time: %.2f\n", total_wt / n);
 printf("Average Turnaround Time: %.2f\n", total_tat / n);
 free(list);
 free(process_completed);
 return 0;
}
