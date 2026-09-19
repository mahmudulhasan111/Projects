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
// vll dp(1e5,-1);
// ll f(ll x)
// {
//     if(x==MOD ) return dp[x]=0;
//     if(2*x>MOD) return dp[x]=MOD-x;
    
//     if(dp[x]!=-1) return dp[x];

//     ll x1=INT_MAX,y1=INT_MAX;
//     if(2*x<=MOD) x1=f(2*x)+1;
//     if(x+1<=MOD) y1=f(x+1)+1;

//     return dp[x]=min(x1,y1);
// }
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;   // range GCD → initial value = 0
}

// LCM function
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;   // range LCM → initial value = 1
}

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    forn(i,0,n) cin >> a[i];

    vll ans(n);

    forn(i,0,n)
    {
        ll x=1e5;
        forn(j,0,100)
        {
            ll k=a[i]+j;
            ll y=lcm(k,MOD);
            x=min(x,(y/(k))+j);
        }
        ans[i]=x;

            
            
      
    }
    for(auto z:ans) cout << z << " " ;
    cout << endl;
}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}