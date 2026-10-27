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
ll n,k;
vector<vector<pii>>v;
vector<vll>dp;
ll dist(pii x,pii y)
{
    return abs(x.first-y.first)+abs(x.second-y.second);
}
ll f(int h,int idx)
{
    if(h==k) return 0;

    if(dp[h][idx]!=-1) return dp[h][idx];
    ll min_cost=INT_MAX;
    forn(i,0,v[h+1].size())
    {
        ll dis=dist(v[h][idx],v[h+1][i]);
        ll total_cost=dis+f(h+1,i);
        min_cost=min(min_cost,total_cost);

    }
    return dp[h][idx]=min_cost;



}
void solve()
{
  
    cin >> n >> k;
    v.assign(k+1,vector<pii>());
    dp.assign(k+1,vll());

    forn(i,0,n)
    {
        forn(j,0,n)
        {
            int x;
            cin >> x;
            v[x].pb({i,j});
        }
    }

    forn(i,1,k+1)
    {
        dp[i].assign(v[i].size(),-1);
    }
    ll ans=LLONG_MAX;
    forn(i,0,v[1].size())
    {
        ans=min(ans,f(1,i));
    }
    cout << ans << endl;

}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}