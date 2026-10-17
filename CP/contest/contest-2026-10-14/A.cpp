#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define rep(i, j, n) for(int i = j; i < (n); i++)
#define popcnt(x) __builtin_popcountll(x)
#define nl "\n"
#define ld long double
#define vld vector<ld>
#define F first
#define pb push_back
#define S second
#define mem(a,b) memset(a,b,sizeof(a)) //shudu 0 & -1
#define gcd(a,b) __gcd(a,b)
#define lcm(x, y) x *(y / gcd(x, y))
#define all(a) (a).begin(), (a).end()
int dx[4] = {-1, 1, 0, 0}; int dy[4] = {0, 0, -1, 1};
const int M = 1e9+7, N = 1e6+5, inf = 1e18;

#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define dbg(...)
#define dbgA(...)
#endif

template<typename T> void print(const T& a) { cout << a << "\n"; }
template<typename T> void print(const set<T>& v){ for (auto& x : v) cout << x << " "; cout << "\n"; }
template<typename T, typename... Args>
void print(const T& first, const Args&... rest){ cout << first; ((cout << ' ' << rest), ...); cout << '\n'; }
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void fazle() {
    int n; cin >> n;

    vector<array<int, 3>> a(n);

    rep ( i, 0, n ) {
        cin >> a[i][1] >> a[i][0];
        a[i][2] = i;
    }
    sort(all(a));
    set<int> ans;

    int last = 0, mn = inf, ind = -1;
    rep ( i, 0, n ) {
        if ( last < a[i][1] ) {
            ans.insert(a[i][2] + 1);
            last = a[i][0];
            mn = a[i][1];
            ind = a[i][2] + 1;
        }
        else if ( mn > a[i][1] ) {
            ans.erase(ind);
            ind = a[i][1] + 1;
            ans.insert(ind);
            last = a[i][0];
        }
        //else if ( )
    }

    print(ans.size());
    print(ans);
    
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen ("input1.txt", "r", stdin);
    freopen ("output1.txt", "w", stdout);
#endif
    fast;
    int T; T = 1;
    //cin >> T;
    rep ( tc, 1, T+1 ) fazle();
}