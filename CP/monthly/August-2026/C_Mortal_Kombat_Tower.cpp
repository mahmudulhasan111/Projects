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
int n;
vi a;
vector<vi> dp;

// int f(int i,int turn)
// {
//     if(i>=n) return dp[i][turn]=0;
//     if(dp[i][turn]!=-1) return dp[i][turn];
//     int mn=INT_MAX;
//     if(!turn)
//     {
        

//         if(i<n && a[i]==0) mn=min(mn,f(i+1,1));
//         if(i<n && a[i]==1) mn=min(mn,f(i+1,1)+1);
//         if(i+1<n && a[i]==0 && a[i+1]==0 ) mn=min(mn, f(i+2,1));
//         if(i+1<n && a[i]==1 && a[i+1]==0 ) mn=min(mn, f(i+2,1)+1);
//         if(i+1<n && a[i]==0 && a[i+1]==1 ) mn=min(mn, f(i+2,1)+1);
//         if(i+1<n && a[i]==1 && a[i+1]==1 ) mn=min(mn, f(i+2,1)+2);

        
//     }

//     else{
        
//         if(i<n) mn=min(mn,f(i+1,0));
//         if(i+1<n) mn=min(mn,f(i+2,0));
      

//     }
//     return dp[i][turn]=mn;
// }
void solve()
{
    cin >> n;
  
    a.assign(n,0);
    forn(i,0,n) cin >> a[i];
    // dp.assign(n+1,vi(2,-1));
    //  f(0,0);
    //  cout << dp[0][0]<< endl; 

     dp.assign(n+1,vi(2,0));
     rev(i,n-1,0)
     {
        forn(j,0,2)
        {
            int mn=INT_MAX;
            if(!j)
            {
                

                if(i<n && a[i]==0) mn=min(mn,dp[i+1][1]);
                if(i<n && a[i]==1) mn=min(mn,dp[i+1][1]+1);
                if(i+1<n && a[i]==0 && a[i+1]==0 ) mn=min(mn, dp[i+2][1]);
                if(i+1<n && a[i]==1 && a[i+1]==0 ) mn=min(mn, dp[i+2][1]+1);
                if(i+1<n && a[i]==0 && a[i+1]==1 ) mn=min(mn, dp[i+2][1]+1);
                if(i+1<n && a[i]==1 && a[i+1]==1 ) mn=min(mn, dp[i+2][1]+2);

                
            }

            else{
                
                if(i<n) mn=min(mn,dp[i+1][0]);
                if(i+1<n) mn=min(mn,dp[i+2][0]);
            

            }
            dp[i][j]=mn;
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