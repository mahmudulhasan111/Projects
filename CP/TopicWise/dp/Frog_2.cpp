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

void solve()
{
    int n,k;
    cin >> n >> k;

    vll h(n+1), dp(n+1,0);

    forn(i,1,n+1) cin >> h[i];

    dp[1]=0;
    forn(i,2,n+1)
    {
        ll tmp=INT_MAX;
        forn(j,1,k+1)
        {
            if(i>=j+1)
            tmp=min(tmp,dp[i-j]+abs(h[i]-h[i-j]));
        }
        dp[i]=tmp;
    }
    cout << dp[n] << endl;
}




 vll h, dp;
ll frog(int n, int k)
{
    if(n==1) return 0;
    if(dp[n]!=-1) return dp[n];

   
        ll tmp=LLONG_MAX;
        forn(j,1,k+1)
        {
            if(n>=j+1)
            tmp=min(tmp,frog(n-j,k)+abs(h[n]-h[n-j]));
        }
        return dp[n]=tmp;



}

void solve2()
{
    int n,k;
    cin >> n >> k;
    h.resize(n+1); dp.resize(n+1,-1);
    forn(i,1,n+1) cin >> h[i];

    cout << frog(n,k)<< endl;


}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;
    while(t--) solve2();
    return 0;
}