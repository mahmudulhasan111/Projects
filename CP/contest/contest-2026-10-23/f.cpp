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
const int INF = 1e9+7;
int N=3e5+1;
// ll binpow(ll a,ll b){ll res=1;a%=MOD;while(b>0){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
// ll modinv(ll a){return binpow(a,MOD-2);}
// ll fact(ll n){ll r=1;for(ll i=1;i<=n;i++)r=(r*i)%MOD;return r;}
// ll nPr(ll n,ll r){if(r>n)return 0;ll res=1;for(ll i=0;i<r;i++)res=(res*(n-i))%MOD;return res;}
// ll nCr(ll n,ll r){if(r>n)return 0;if(r>n-r)r=n-r;ll res=1;for(ll i=1;i<=r;i++)res=res*(n-r+i)/i;return res;}
int n;
vll a,dp;
vector<vll> divisors;
ll f(ll target)
{
    if(target==1) return 0;
    
    if(dp[target]!=-1) return dp[target];
    ll cnt=INF;
   for(auto x:divisors[target])
   {
    cnt=min(cnt,1LL+f(target/x));
   }
    return dp[target]=cnt;

}
void solve()
{
    cin >> n;
    a.assign(n,0);
    dp.assign(n+1,-1);
    divisors.assign(n+1,vll());
    vll present(n+1,0);
    bool one=false;
    forn(i,0,n)
    {
        cin >> a[i];
        present[a[i]]=1;
        if(a[i]==1) one=true;

    }
   

    forn(i,2,n+1)
    {
        if(!present[i]) continue;
        for(int j=i;j<=n;j+=i)
        {
            divisors[j].pb(i);
        }
    }
    vll ans;
    ans.pb(one?1:-1);
    forn(i,2,n+1)
    {
       ll res=f(i);
       ans.pb(res>=INF?-1:res);
    }
    for(auto x:ans)
    {
        cout << x << " ";
    }
    cout << endl;



}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}