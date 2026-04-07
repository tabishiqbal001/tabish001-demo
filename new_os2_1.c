#include <stdio.h>

struct Process {
    int pid, at, bt, pr, rt, ct, wt, tat;
};

int main() {
    int n = 3;
    struct Process p[3] = {
        {1,0,5,2,5,0,0,0},
        {2,1,3,1,3,0,0,0},
        {3,2,4,3,4,0,0,0}
    };

    int time = 0, completed = 0, min_pr, idx;

    while(completed != n) {
        min_pr = 9999;
        idx = -1;

        for(int i = 0; i < n; i++) {
            if(p[i].at <= time && p[i].rt > 0) {
                if(p[i].pr < min_pr) {
                    min_pr = p[i].pr;
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            p[idx].rt--;
            time++;

            if(p[idx].rt == 0) {
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                completed++;
            }
        } else {
            time++;
        }
    }

    printf("PID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid, p[i].at, p[i].bt, p[i].pr,
            p[i].ct, p[i].tat, p[i].wt);
    }

    return 0;
}