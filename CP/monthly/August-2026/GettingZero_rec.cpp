#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define endl '\n'
#define forn(i, a, b) for(int i = a; i < b; i++)
#define rev(i, a, b) for(int i = a; i >= b; i--)
const ll MOD = 32768;

ll binpow(ll a,ll b){ll res=1;a%=MOD;while(b>0){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modinv(ll a){return binpow(a,MOD-2);}
ll fact(ll n){ll r=1;for(ll i=1;i<=n;i++)r=(r*i)%MOD;return r;}
ll nPr(ll n,ll r){if(r>n)return 0;ll res=1;for(ll i=0;i<r;i++)res=(res*(n-i))%MOD;return res;}
ll nCr(ll n,ll r){if(r>n)return 0;if(r>n-r)r=n-r;ll res=1;for(ll i=1;i<=r;i++)res=res*(n-r+i)/i;return res;}
ll n;
vll a;
vector<vll> dp;

ll f(ll x,ll cnt)
{
    x %= MOD;
    if (x == 0) return cnt;
    if(cnt>=15) return dp[x][cnt]=15;
    if (dp[x][cnt] != -1) return dp[x][cnt];

    ll ans = INT_MAX;
    ans = min(ans, f((x + 1) % MOD,cnt+1));
    ans = min(ans, f((2 * x) % MOD,cnt + 1));
    
    return dp[x][cnt] = ans;
}

void solve()
{
    cin >> n;
    a.resize(n);
    dp.assign(MOD,vll(16,-1));

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cout << f(a[i],(ll)0) << " ";
    }
    cout << endl;
}

int main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}