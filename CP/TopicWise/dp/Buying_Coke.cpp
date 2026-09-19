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
int n, one, five, ten;
int dp[155][155][52];
int total;
int coke(int m,  int f , int t)
{
   
    
     if(m==0) return dp[m][f][t]= 0;
    
    if(dp[m][f][t]!=-1) return dp[m][f][t];
    int ans=MOD;
    int used_amount=(n-m)*8;
    int o=total-used_amount-f*5-t*10;


    if(o>=8)  ans=min(ans,coke(m-1, f, t)+8);
    if(f>=2)   ans=min(ans,coke(m-1, f-2, t)+2);
    if(t>=1)  ans=min(ans, coke(m-1, f, t-1)+1);
    if(f>=1 && o>=3)  ans=min(ans, coke(m-1, f-1, t)+4);
    if(t>=1 && o>=3)  ans=min(ans, coke(m-1, f+1, t-1)+4);
    return dp[m][f][t]=ans;
}
void solve()
{
    
    memset(dp, -1, sizeof(dp));
    cin >> n >> one >> five >> ten;
    total= one+5*five+10*ten;
    cout << coke(n , five, ten)<< endl;

}

int main()
{
    fast_io;
    
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}