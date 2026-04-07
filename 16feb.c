#include <stdio.h>
#include <limits.h>

int main(void) {
    int n;

    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int at[n], bt[n], ct[n], tat[n], wt[n];
    int completed[n];

    // Initialize completed array
    for (int i = 0; i < n; i++) {
        completed[i] = 0;
    }

    // Input Arrival Time and Burst Time
    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    int time = 0, done = 0;
    float total_wt = 0, total_tat = 0;

    printf("\nGantt Chart:\n");

    while (done < n) {
        int min_bt = INT_MAX;
        int idx = -1;

        // Find process with minimum burst time among arrived processes
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && completed[i] == 0) {
                if (bt[i] < min_bt) {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            // Process found
            printf("| P%d ", idx + 1);
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            total_wt += wt[idx];
            total_tat += tat[idx];
            completed[idx] = 1;
            done++;
        } else {
            // CPU Idle: Jump to the next closest arrival time to save cycles
            int next_arrival = INT_MAX;
            for (int i = 0; i < n; i++) {
                if (completed[i] == 0 && at[i] < next_arrival) {
                    next_arrival = at[i];
                }
            }
            printf("| Idle ");
            time = next_arrival; 
        }
    }
    printf("|\n");

    // Display results
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}