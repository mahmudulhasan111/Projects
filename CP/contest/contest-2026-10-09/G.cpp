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
const int M = 1e9+7, N = 1e5+5, inf = 1e18;

#ifndef ONLINE_JUDGE
#undef int
// #include "template.cpp"
#define int long long
#else
// #define debug(...)
// #define debugArr(...)
#endif

template<typename T> void print(const T& a) { cout << a << "\n"; }
template<typename T> void print(const vector<T>& v){ for (auto& x : v) cout << x << " "; cout << "\n"; }
template<typename T, typename... Args>
void print(const T& first, const Args&... rest){ cout << first; ((cout << ' ' << rest), ...); cout << '\n'; }
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


map<int,int> spf_Factor2(int N){
    map<int,int> cnt;

    for(int i = 2; i * i <= N; i++){
        while(N % i == 0){
            cnt[i]++;
            N /= i;
        }
    }

    if(N > 1) cnt[N]++;

    return cnt;
}

void fazle() {
    int n; cin >> n;
    int ans = n*(n+1)/2;
    // ans %= M;

    if ( n == 1 ) {
        print(1);
        return;
        
    }

    // ans = ( n*(n+1)/2 * ans ) %M;
    ans=(ans%M * ans%M)%M;

    int sub = 0;

    for ( int i = 2; i <= n; i++ ) {
        // for ( int j = i; j <= n; j += i) {

        //     sub += ( i*j);
        //     sub %= M;
        //     if( i != j ) {
        //         sub += ( i*j );
        //         sub %= M;
        //     }
        //     debug(sub);
            
        // }

        int g=0;
        map<int, int> mp = spf_Factor2(i);
        for ( auto [u, v]: mp ) {
            for ( int k = u; k <= i; k += u )
            {
                 
                sub+=(k*i);
                g=__gcd(u,g);
                sub%M;
            }
        }
           
    }
   // debug(ans, sub);
    ans = ( ans - sub + M )%M;
    print(ans);
}

int32_t main() {
    fast;
    //pre();
    int T; cin >> T; for ( int tc = 1; tc <= T; tc++ )
    fazle ();
}