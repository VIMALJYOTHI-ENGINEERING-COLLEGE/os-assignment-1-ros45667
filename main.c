#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct
{
    int arrival_time;
    int burst_time;
    int priority;
    int completion_time;
    int tat;
    int waiting_time;
} process;

int main(void)
{
    int n;
    printf("Enter the number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid input\n");
        return 1;
    }

    process *list = (process *)malloc(n * sizeof(process));
    if (list == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    bool *process_completed = (bool *)malloc(n * sizeof(bool));
    if (process_completed == NULL)
    {
        printf("Memory allocation failed\n");
        free(list);
        return 1;
    }

    // Input: AT BT Priority
    for (int i = 0; i < n; i++)
    {
        printf("P%d (AT BT Priority): ", i + 1);
        if (scanf("%d %d %d", &list[i].arrival_time, &list[i].burst_time, &list[i].priority) != 3)
        {
            printf("Invalid input\n");
            free(list);
            free(process_completed);
            return 1;
        }
        process_completed[i] = false;
    }

    int current_time = 0;
    int completed = 0;

    while (completed < n)
    {
        int idx = -1;
        int min_priority = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (!process_completed[i] && list[i].arrival_time <= current_time)
            {
                // Lower number = higher priority
                if (list[i].priority < min_priority)
                {
                    min_priority = list[i].priority;
                    idx = i;
                }
            }
        }

        if (idx == -1)
        {
            current_time++; // CPU idle
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

    float total_wt = 0.0f, total_tat = 0.0f;

    printf("\nWaiting Time:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d %d\n", i + 1, list[i].waiting_time);
        total_wt += list[i].waiting_time;
    }

    printf("\nTurnaround Time:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d %d\n", i + 1, list[i].tat);
        total_tat += list[i].tat;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    free(list);
    free(process_completed);
    return 0;
}
