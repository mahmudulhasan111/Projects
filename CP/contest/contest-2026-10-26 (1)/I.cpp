#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

#ifdef LOCAL
    #include "debug.h"
#else
    #define db(...)
#endif

using namespace std;
//using namespace __gnu_pbds;
#define int long long
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
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
#define rall(a) (a).rbegin(), (a).rend()
#define all(a) (a).begin(), (a).end()
int dx[4] = {-1, 1, 0, 0}; int dy[4] = {0, 0, -1, 1};
const int M = 1e9+7, N = 1e6+5, inf = 1e18;

template<typename T> void print(const T& a) { cout << a << "\n"; }
template<typename T> void print(const vector<T>& v){ for (auto& x : v) cout << x << " "; cout << "\n"; }
template<typename T, typename... Args>
void print(const T& first, const Args&... rest){ cout << first; ((cout << ' ' << rest), ...); cout << '\n'; }
//template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


void fazle() {
    int n, k; cin >> n >> k;

    if ( n == k or k < 5 ) print(-1);
    else if ( k*2 > n ) {
        int d = (k-2)/2, r = k-2;
        //cout << '(';
        rep ( i, 0, n/(k-2) ) {
            rep (j, 0, d ) cout << '(';
            rep (j, 0, d ) cout << ')';
        }
        //cout << ')';
        n -= (n/r)*r;

        db(n, d, r);

        rep ( i, 0, n/2) cout << '(';
        rep ( i, 0, n/2) cout << ')';

        cout << nl;
    }
    else {
        for ( int i = 4; i < k; i += 2 ) {
            if ( i + n%i != k ) {

                rep ( j, 0, n/i ) {
                    rep ( r, 0, i/2 ) cout << '(';
                    rep ( r, 0, i/2 ) cout << ')';
                }
                n -= (n/i)*i;

                rep ( j, 0, n/2 ) cout << '(';
                rep ( j, 0, n/2 ) cout << ')';
                return;
            }
        }

        print(-1);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T; T = 1;
    cin >> T;
    rep ( tc, 1, T+1 ) {
        //cout << "Case " << tc << ": ";
        fazle();
    }
}

