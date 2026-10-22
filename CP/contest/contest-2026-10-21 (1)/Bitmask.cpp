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

// void solve()
// {
//     string s;
//     cin >> s;
//     ll n;
//     cin >> n;
//     int sz=s.size();

//     vll ans;
   
//     for (int mask = 0; mask < (1 << sz); mask++){
//        bool ok=true;
//         for (int k = 0; k < sz; k++) {
//             if (mask & (1 << k)){
//                 // cout << 1 << " ";
//                 if(s[sz-1-k]=='0') ok=false;

//             }
//             else {
//                 // cout << 0 << " ";
//                 if(s[sz-1-k]==1) ok=false;
//             }
          
//         }
//         if(ok && mask<=n) ans.pb(mask);
//         // cout << '\n';
//     }
//     if(ans.empty()) 
//     {
//         cout << -1 << endl; return;
//     }
//     sort(all(ans));
//     int sz2=ans.size();
//     cout << ans[sz2-1] << endl;
// }
void solve()
{
    string s;
    cin >> s;
    ll n;
    cin >> n;

    reverse(all(s));
    int sz=s.size();
    ll num=0;

    rev(i,sz-1,0)
    {
        if(s[i]=='1') num+=(1ll<<i);
    }
    int b=0;
    rev(i,sz-1,0)
    {
        if(s[i]=='?')
        {
            ll b=(1LL<<i);
            if(b+num<=n) num+=b;
        }
    }
    if(num>n)
    {
        cout << -1 << endl; return;
    }
    cout << num << endl;


}







int main()
{
    fast_io;
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}