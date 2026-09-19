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
const int MAXN = 2e5 + 5;




void solve()
{
    ll n;
    cin >> n;
    vll a(n+1),s;
    
    forn(i,1,n+1)
    {
        cin >> a[i];
    }

    vll diff(MAXN,0);

    forn(i,1,n+1)
    {
        ll l=min(n,(ll)i*a[i]) , r=min(n,(ll)i*(a[i]+1)-1);
        diff[l]++; diff[r+1]--;
    }
    
    forn(i,1,n+1)
    {
        diff[i]+=diff[i-1];
    }
    forn(i,0,n)
    {
        if(diff[i]==0) s.pb(i);
    }
    cout << s.size() << endl;
    for(auto x:s) cout << x << " ";
    cout << endl;
  
}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}