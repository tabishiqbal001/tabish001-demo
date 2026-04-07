#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], rt[n],ct[n], tat[n], wt[n], response[n];
    bool started[n];
    for(int i = 0; i < n; i++) {
        cout << "\nProcess " << i+1 << " Arrival Time: ";
        cin >> at[i];
        cout << "Process " << i+1 << " Burst Time: ";
        cin >> bt[i];

        pid[i] = i + 1;
        rt[i] = bt[i];
        started[i] = false;
    }

    int completed = 0, time = 0,shortest = -1,min_bt = 1e9;
    while(completed < n) {
        shortest = -1;
        min_bt = 1e9;
        for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(rt[i] < min_bt) {
                    min_bt = rt[i];
                    shortest = i;
                }
            }
        }

        if(shortest == -1) {
            time++;
            continue;
        }

        if(!started[shortest]) {
            response[shortest] = time - at[shortest];
            started[shortest] = true;
        }

        rt[shortest]--;
        time++;

        if(rt[shortest] == 0) {
            completed++;
            ct[shortest] = time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
        }
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for(int i = 0; i < n; i++) {
        cout << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << tat[i] << "\t"
             << wt[i] << "\t"
             << response[i] << endl;
    }

    return 0;
}