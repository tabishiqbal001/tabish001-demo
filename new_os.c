#include <stdio.h>

struct Process {
    int pid, at, bt, priority, ct, tat, wt;
    int completed;
};

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input
    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter AT BT Priority for P%d: ", p[i].pid);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
        p[i].completed = 0;
    }

    int time = 0, done = 0;

    while(done < n) {
        int idx = -1;
        int highest_priority = 9999;

        for(int i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].completed == 0) {
                if(p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            time += p[idx].bt;
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].completed = 1;
            done++;
        } else {
            time++; // CPU idle
        }
    }

    // Output
    printf("\nPID\tAT\tBT\tP\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].priority, p[i].ct,
               p[i].tat, p[i].wt);
    }

    return 0;
}