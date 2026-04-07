#include <iostream>
using namespace std;

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], rt[n], ct[n], tat[n], wt[n], response[n];
    bool started[n] = {false};

    for(int i = 0; i < n; i++) {
        cout << "\nProcess " << i+1 << " Arrival Time: ";
        cin >> at[i];
        cout << "Process " << i+1 << " Burst Time: ";
        cin >> bt[i];

        pid[i] = i + 1;
        rt[i] = bt[i];
    }

    cout << "\nEnter Time Quantum: ";
    cin >> tq;

    int completed = 0, time = 0;

    while(completed < n) {
        bool done = true;

        for(int i = 0; i < n; i++) {

            if(at[i] <= time && rt[i] > 0) {

                done = false;

                if(!started[i]) {
                    response[i] = time - at[i];
                    started[i] = true;
                }

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    completed++;

                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                }
            }
        }

        if(done)
            time++;
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