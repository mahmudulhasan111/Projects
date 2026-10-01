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
const int MOD = 1e9+7;

ll binpow(ll a,ll b){ll res=1;a%=MOD;while(b>0){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modinv(ll a){return binpow(a,MOD-2);}
ll fact(ll n){ll r=1;for(ll i=1;i<=n;i++)r=(r*i)%MOD;return r;}
ll nPr(ll n,ll r){if(r>n)return 0;ll res=1;for(ll i=0;i<r;i++)res=(res*(n-i))%MOD;return res;}
ll nCr(ll n,ll r){if(r>n)return 0;if(r>n-r)r=n-r;ll res=1;for(ll i=1;i<=r;i++)res=res*(n-r+i)/i;return res;}
int n,k;
const int MAXN=200005;
vector<int> prime_divisors[MAXN];
int dp[MAXN];
 
void precompute(){
    for(int i=2;i<MAXN;++i){
        if(prime_divisors[i].empty()){
            for(int j=i;j<MAXN;j+=i){
                prime_divisors[j].push_back(i);
            }
        }
    }
}

ll f(int m)
{
    if(m<=k) return 0;
    if(dp[m]!=-1) return dp[m];
    ll res=INT_MAX;
    for(auto z:prime_divisors[m])
    {
        res=min(res*1LL, 1LL+z*f(m/z));
    }
    return dp[m]=res;


}
void solve()
{
    
    cin >> n >> k;
    vi a(n);
    forn(i,0,n) cin >> a[i];
    memset(dp,-1,sizeof(dp));
    ll ans=0;
    for(auto x:a)
    {
        ans+=f(x);
    }
    cout << ans << endl;


}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    precompute();
    while(t--) solve();
    return 0;
}