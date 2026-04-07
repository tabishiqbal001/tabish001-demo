#include <iostream>
using namespace std;

struct Process {
    int pid, at, bt, priority, ct, tat, wt;
    bool completed;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process p[n];

    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "Enter AT, BT, Priority for P" << p[i].pid << ": ";
        cin >> p[i].at >> p[i].bt >> p[i].priority;
        p[i].completed = false;
    }

    int time = 0, completed = 0;

    while(completed < n) {
        int idx = -1;
        int highest_priority = 9999;

        for(int i = 0; i < n; i++) {
            if(p[i].at <= time && !p[i].completed) {
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
            p[idx].completed = true;
            completed++;
        } else {
            time++;
        }
    }

    cout << "\nPID\tAT\tBT\tP\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++) {
        cout << "P" << p[i].pid << "\t" << p[i].at << "\t"
             << p[i].bt << "\t" << p[i].priority << "\t"
             << p[i].ct << "\t" << p[i].tat << "\t"
             << p[i].wt << endl;
    }
    return 0;

}