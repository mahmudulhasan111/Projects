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
string a,b,c;
vector<vll> dp;
// ll f(ll i, ll j)
// {
//     if(dp[i][j]!=-1) return dp[i][j];
//     if(i==a.size())
//     {
//         if(j==b.size()) return dp[i][j]=0;

//         return dp[i][j]=f(i, j+1)+(b[j]!=c[i+j]);
//     }
//     if(j==b.size())
//     {
//         return dp[i][j]=f(i+1,j)+(a[i]!=c[i+j]);
//     }

//     ll takeA= f(i+1, j)+(a[i]!=c[i+j]);
//     ll takeB=f(i,j+1)+(b[j]!=c[i+j]);
//     return dp[i][j]=min(takeA, takeB);
// }

// void solve()
// {
    
//     cin >> a >> b >> c;
//     ll n=a.size(), m=b.size();
//     dp.assign(n+1,vll(m+1,-1));
//      f(0,0);
//      cout << dp[0][0] << endl; 





// }
void solve()
{
    
    cin >> a >> b >> c;
    ll n=a.size(), m=b.size();
    dp.assign(n+1,vll(m+1,0));
    
     
    rev(i,n,0)
    {
        rev(j,m, 0)
        {
            if(i==n && j==m){
                 dp[i][j]=0; continue;
            }

            if(i==n) dp[i][j]=dp[i][j+1]+(b[j]!=c[i+j]);
            else if(j==m) dp[i][j]=dp[i+1][j]+(a[i]!=c[i+j]);
            else dp[i][j]=min(dp[i+1][j]+(a[i]!=c[i+j]),dp[i][j+1]+(b[j]!=c[i+j]));

        }
    }
    cout << dp[0][0] << endl;




}


int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}