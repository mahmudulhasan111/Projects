#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define int long long
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define endl '\n'
#define forn(i, a, b) for(int i = a; i < b; i++)
#define rev(i, a, b) for(int i = a; i >= b; i--)
const int MOD = 1e9+7;


void solve()
{
    int n, k; cin >> n >> k;
    vector<array<int, 3>> a(n);
    
    for ( int i = 0; i < n; i++ ) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    vector<int> dp(n, k);

    for ( int i = 0; i < n; i++ ) {
        int d = a[i][0];
        
    }

}

signed main()
{
    fast_io;
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}