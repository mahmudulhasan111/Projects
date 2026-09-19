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

vector<vi > dp;
// int lcs(string &s1,string &s2, int n, int m)
// {
//     if(m==0 || n==0) return dp[n][m]=0;
//     if(dp[n][m]!=-1) return dp[n][m];

//     if(s1[n-1]==s2[m-1])
//     {
//         return dp[n][m]=1+lcs(s1,s2, n-1, m-1);
//     }
//     else 
//     {
//         return dp[n][m]=max(lcs(s1,s2, n-1, m),lcs(s1,s2, n,m-1));
//     }

// }
void solve()
{
    string s1,s2;
    cin >> s1 >> s2;
    int n=s1.size(), m=s2.size();
    dp.resize(n+1,vi(m+1,0)); // rec-> -1
    //  lcs(s1,s2, n,m) ;
    //  cout << dp[n][m] << endl;

    forn(i,1,n+1)
    {
        forn(j,1,m+1)
        {
            if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else{
                 dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }



    int i=n, j=m;
    string ans="";
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])
        {
            ans+=s1[i-1];
            i--, j--;
        }
        else 
        {
            if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else j--;
        }
    }
    reverse(all(ans));
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