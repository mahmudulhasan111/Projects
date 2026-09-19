#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Process {
    int id, at, bt, ct, tat, wt;
    bool completed = false;
};

int main() {
    int n;
    // cout << "Enter number of processes: ";
    cin >> n;
    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        // cout << "P" << p[i].id << " Arrival & Burst Time: ";
        cin >> p[i].at >> p[i].bt;
    }

    int completedCount = 0, currentTime = 0;
    while (completedCount < n) {
        int minIdx = -1, minBT = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= currentTime && !p[i].completed && p[i].bt < minBT) {
                minBT = p[i].bt;
                minIdx = i;
            }
        }

        if (minIdx == -1) {
            currentTime++;
        } else {
            currentTime += p[minIdx].bt;
            p[minIdx].ct = currentTime;
            p[minIdx].tat = p[minIdx].ct - p[minIdx].at;
            p[minIdx].wt = p[minIdx].tat - p[minIdx].bt;
            p[minIdx].completed = true;
            completedCount++;
        }
    }

    cout << "\nID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &x : p) {
        cout << "P" << x.id << "\t" << x.at << "\t" << x.bt << "\t" 
             << x.ct << "\t" << x.tat << "\t" << x.wt << "\n";
    }
    return 0;
}