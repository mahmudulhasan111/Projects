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

vector<vi> arr;
vector<vll> dp;

ll func(int i, int j)
{
    // Base case
    if(i == 0)
        return arr[0][j];

    // Already calculated
    if(dp[i][j] != -1)
        return dp[i][j];

    if(j == 0)
    {
        return dp[i][j] =
            arr[i][j] + max(func(i - 1, 1), func(i - 1, 2));
    }

    if(j == 1)
    {
        return dp[i][j] =
            arr[i][j] + max(func(i - 1, 0), func(i - 1, 2));
    }

    if(j == 2)
    {
        return dp[i][j] =
            arr[i][j] + max(func(i - 1, 0), func(i - 1, 1));
    }

    return 0;
}
void solve()
{
    int n;
    cin >> n;

    arr.resize(n, vi(3));
    dp.resize(n, vll(3, -1));

    forn(i, 0, n)
    {
        forn(j, 0, 3)
        {
            cin >> arr[i][j];
        }
    }

    ll ans = max({
        func(n - 1, 0),
        func(n - 1, 1),
        func(n - 1, 2)
    });

    cout << ans << endl;
}

void solve2()
{
    int n;
    cin >> n;
    vector<vi> arr(n, vi(3));
    vector<vll> dp(n, vll(3,0));
     forn(i,0,n)
    {
        forn(j,0,3)
        {
            cin >> arr[i][j];
        }
       
    }

    //  forn(i,0,n)
    // {
    //     forn(j,0,3)
    //     {
    //         cout << arr[i][j]<< " ";
    //     }
    //     cout << endl;
    // }

    dp[0][0]=arr[0][0];
    dp[0][1]=arr[0][1];
    dp[0][2]=arr[0][2];

    forn(i,1,n)
    {
        forn(j,0,3)
        {
            
            if(j==0) dp[i][j]=arr[i][j]+max(dp[i-1][1],dp[i-1][2]);
            if(j==1) dp[i][j]=arr[i][j]+max(dp[i-1][0],dp[i-1][2]);
            if(j==2) dp[i][j]=arr[i][j]+max(dp[i-1][1],dp[i-1][0]);
        }
    }
    ll ans=max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
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