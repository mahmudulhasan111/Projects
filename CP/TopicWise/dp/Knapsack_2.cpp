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
ll INF=1e9;
void solve()
{
    int n,w;
    cin >> n >> w;
    vll wt(n+1),val(n+1);
    ll totalval=0;
    forn(i,1,n+1)
    {
        cin >> wt[i] >> val[i]; 
        totalval+=val[i];
    }
    vector<vll>dp(n+1,vll(totalval+1,INF));

    dp[0][0]=0;
    forn(i,1,n+1)
    {
        forn(j,0,totalval+1)
        {
            if(val[i]<=j)
            {
                dp[i][j]=min(wt[i]+dp[i-1][j-val[i]],dp[i-1][j]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    ll ans=0;
    forn(i,1,totalval+1)
    {
        if(dp[n][i]<=w)
        {
            ans=i;
        }
    }
    cout << ans << endl;

}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}