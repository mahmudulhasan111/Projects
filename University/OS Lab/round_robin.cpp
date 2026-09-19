#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Process {
    int id, at, bt, rt, ct, tat, wt;
};

bool compareAT(const Process &a, const Process &b) {
    return a.at < b.at;
}

int main() {
    int n, tq;
    // cout << "Enter number of processes & Time Quantum: ";
    cin >> n >> tq;
    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        // cout << "P" << p[i].id << " Arrival & Burst Time: ";
        cin >> p[i].at >> p[i].bt;
        p[i].rt = p[i].bt;
    }

    sort(p.begin(), p.end(), compareAT);
    queue<int> q;
    vector<bool> inQueue(n, false);
    
    int currentTime = p[0].at;
    q.push(0);
    inQueue[0] = true;
    int completedCount = 0;

    while (completedCount < n) {
        if (q.empty()) {
            for (int i = 0; i < n; i++) {
                if (p[i].rt > 0) {
                    q.push(i);
                    inQueue[i] = true;
                    currentTime = max(currentTime, p[i].at);
                    break;
                }
            }
        }

        int curr = q.front();
        q.pop();

        int execTime = min(p[curr].rt, tq);
        p[curr].rt -= execTime;
        currentTime += execTime;

        for (int i = 0; i < n; i++) {
            if (i != curr && p[i].at <= currentTime && p[i].rt > 0 && !inQueue[i]) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (p[curr].rt > 0) {
            q.push(curr);
        } else {
            p[curr].ct = currentTime;
            p[curr].tat = p[curr].ct - p[curr].at;
            p[curr].wt = p[curr].tat - p[curr].bt;
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