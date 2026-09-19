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
vi palldrm;

// Reverse Number
ll reverseNumber(ll n)
{
    ll rev = 0;

    while(n)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    return rev;
}


// Check Number Palindrome
bool isNumberPalindrome(ll n)
{
    return n == reverseNumber(n);
}

void pal()
{
    forn(i,1,40001)
    {
        if(isNumberPalindrome(i)) palldrm.pb(i);
    }
}

 vector<vll> dp;


 void precompute()
 { 
       

   
        forn(i,1,palldrm.size()+1)
        {
            forn(j,1,40001)
            {
                if(palldrm[i-1]<=j)
                {
                    dp[i][j]=   ( dp[i-1][j] +   dp[i][j-palldrm[i-1]] )%MOD;
                }
                else dp[i][j]=dp[i-1][j];
            }
        }

 }
    


void solve()
{
    int n;
    cin >> n;
    int m=0;
   for(auto x:palldrm)
   {
    if(x<=n) m++;
    else break;
   }

   
    ll ans=dp[m][n]%MOD;
    cout << ans << endl;

}

int main()
{
    fast_io;
    
    pal();

     dp.resize(palldrm.size()+1,vll(40001,0));
    forn(i,0,palldrm.size()+1) dp[i][0]=1;


    precompute();
   

    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}