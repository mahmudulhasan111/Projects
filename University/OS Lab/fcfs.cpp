#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id, at, bt, ct, tat, wt;
};

bool compareAT(const Process &a, const Process &b) {
    return a.at < b.at;
}

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

    sort(p.begin(), p.end(), compareAT);

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at) currentTime = p[i].at;
        p[i].ct = currentTime + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        currentTime = p[i].ct;
    }

    cout << "\nID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &x : p) {
        cout << "P" << x.id << "\t" << x.at << "\t" << x.bt << "\t" 
             << x.ct << "\t" << x.tat << "\t" << x.wt << "\n";
    }
    return 0;
}