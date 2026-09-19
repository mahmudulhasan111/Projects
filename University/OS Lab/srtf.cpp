// shortest remaining time first

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Process {
    int id, at, bt, rt, ct, tat, wt;
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
        p[i].rt = p[i].bt;
    }

    int completedCount = 0, currentTime = 0, minRT = INT_MAX, shortest = -1;
    bool found = false;

    while (completedCount < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].at <= currentTime && p[i].rt > 0 && p[i].rt < minRT) {
                minRT = p[i].rt;
                shortest = i;
                found = true;
            }
        }

        if (!found) {
            currentTime++;
            continue;
        }

        p[shortest].rt--;
        minRT = p[shortest].rt == 0 ? INT_MAX : p[shortest].rt;

        if (p[shortest].rt == 0) {
            completedCount++;
            found = false;
            p[shortest].ct = currentTime + 1;
            p[shortest].tat = p[shortest].ct - p[shortest].at;
            p[shortest].wt = p[shortest].tat - p[shortest].bt;
        }
        currentTime++;
    }

    cout << "\nID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &x : p) {
        cout << "P" << x.id << "\t" << x.at << "\t" << x.bt << "\t" 
             << x.ct << "\t" << x.tat << "\t" << x.wt << "\n";
    }
    return 0;
}