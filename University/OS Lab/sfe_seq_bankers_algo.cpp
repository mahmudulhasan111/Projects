#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    vector<vector<int>> allocation(n, vector<int>(m));
    vector<vector<int>> maxNeed(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));

    vector<int> available(m);
    vector<int> work(m);
    vector<int> finish(n, 0);
    vector<int> safeSequence;

    cout << "Enter Allocation Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> allocation[i][j];
        }
    }

    cout << "Enter Max Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> maxNeed[i][j];
        }
    }

    cout << "Enter Available Resources:\n";
    for(int j = 0; j < m; j++) {
        cin >> available[j];
        work[j] = available[j];
    }

    // Need = Max - Allocation
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            need[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }

    while(safeSequence.size() < n) {
        bool found = false;

        for(int i = 0; i < n; i++) {

            if(finish[i] == 1)
                continue;

            bool canFinish = true;

            for(int j = 0; j < m; j++) {
                if(need[i][j] > work[j]) {
                    canFinish = false;
                    break;
                }
            }

            if(canFinish) {
                for(int j = 0; j < m; j++) {
                    work[j] += allocation[i][j];
                }

                finish[i] = 1;
                safeSequence.push_back(i);
                found = true;
            }
        }

        if(!found) {
            cout << "\nSystem is in UNSAFE state.\n";
            return 0;
        }
    }

    cout << "\nSystem is in SAFE state.\n";

    cout << "Safe Sequence: ";

    for(int i = 0; i < n; i++) {
        cout << "P" << safeSequence[i];

        if(i != n - 1)
            cout << " -> ";
    }

    cout << endl;

    return 0;
}