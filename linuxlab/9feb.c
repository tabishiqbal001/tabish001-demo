#include<stdio.h>

int main() {
    int n = 5;
    int at[5] = {0, 1, 2, 3, 4};   // Arrival Time
    int bt[5] = {7, 5, 1, 2, 3};   // Burst Time
    int ct[5], tat[5], wt[5];
    int completed[5] = {0, 0, 0, 0, 0};

    int time = 0, done = 0, min_bt, idx;

    while (done < n) {
        min_bt = 9999;
        idx = -1;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && completed[i] == 0) {
                if (bt[i] < min_bt) {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            completed[idx] = 1;
            done++;
        } else {
            time++;
        }
    }
    
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    return 0;
}