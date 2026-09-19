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



  
vector<pii> coin;
int dp[45][305][305];
int s;

int f(int i, int x,int y)
{
    if(x*x+y*y==s*s ) return 0;
    if(x*x+y*y>s*s || i==0) return MOD;
       
    
  
    if(dp[i][x][y] != -1)
        return dp[i][x][y];
    int p=coin[i-1].first, q=coin[i-1].second;

    if(sqrt(x*x+y*y)<= s*s)
    {
        return dp[i][x][y] = min(
            f(i-1,x,y ),                    // skip
            1 + f(i, x-p,y-q)    // take again
        );
    }
    else
    {
        return dp[i][x][y] = f(i-1, x,y);
    }
        
}

  

void solve()
{
    

    int m;
    cin >> m >> s;
    coin.resize(m,{0,0});
   memset(dp,-1,sizeof(dp));
    
    forn(i,0,m)
    {
        cin >> coin[i].first >> coin[i].second;
    }
    int ans= f(m,0,0);
    if(ans>=MOD) cout << "not possible" << endl;
    else cout << ans << endl;

}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}