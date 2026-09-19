#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'

const int MOD = 1e9+7;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> coin(n);
    for (int i = 0; i < n; i++) cin >> coin[i];

    // 1D DP Table
    vector<int> dp(x + 1, 0);
    dp[0] = 1; // Base case: 1 way to form sum 0

    // Iterative Loop: O(N * X) time, O(X) memory
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= x; j++) {
            dp[j] = (dp[j] + dp[j - coin[i]]) % MOD;
        }
    }

    cout << dp[x] << endl;
}

int main()
{
    fast_io;
    int t = 1;
    while (t--) solve();
    return 0;
}