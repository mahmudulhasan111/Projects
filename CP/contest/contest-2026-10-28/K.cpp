#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define ll long long
#define vll vector<ll>
#define endl '\n'

const int MOD = INT_MAX;

ll m, n;
vll dp;

// ১-প্যারামিটারের পারফেক্ট রিকার্সিভ ফাংশন
ll f(ll i) {
    if (i == 0) return 1;
    if (dp[i] != -1) return dp[i];

    // m-ary partition এর স্ট্যান্ডার্ড রিকার্সন লজিক
    if (i % m == 0) {
        return dp[i] = (f(i - 1) + f(i / m)) % MOD;
    } else {
        return dp[i] = f(i - 1) % MOD;
    }
}

void solve() {
    ll k;
    cin >> k >> m >> n;
    
    dp.assign(n + 1, -1);
    cout << k << " " << f(n) << endl;
}

int main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
