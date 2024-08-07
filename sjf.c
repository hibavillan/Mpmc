#include <stdio.h>

#define MAX 10

// Function to find the waiting time and turnaround time
void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    int rt[MAX];
    for (int i = 0; i < n; i++) {
        rt[i] = bt[i];
    }
    
    wt[0] = 0; // Waiting time for the first process is 0

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (rt[j] < rt[min_index]) {
                min_index = j;
            }
        }
        // Swap the processes and burst times
        int temp_rt = rt[i];
        rt[i] = rt[min_index];
        rt[min_index] = temp_rt;

        int temp_p = processes[i];
        processes[i] = processes[min_index];
        processes[min_index] = temp_p;

        wt[i] = 0;
        for (int j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findavgTime(int processes[], int n, int bt[]) {
    int wt[MAX], tat[MAX];

    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    // Print the results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];

    // Input burst times
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1; // Process numbers are 1, 2, 3, ..., n
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    findavgTime(processes, n, burst_time);

    return 0;
}
