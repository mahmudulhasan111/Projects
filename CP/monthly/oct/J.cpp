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
ll f(vi a)
{
    ll n=a.size(),sum_previous=0;
    ll score=0;
    forn(i,0,n)
    {
        score+=sum_previous-i*a[i];
        sum_previous+=a[i];
    }
    return 2*score;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n,vi(m,0));
    map<int,set<pair<int,int>>>mp;
    forn(i,0,n)
    {
        forn(j,0,m)
        {
            cin >> v[i][j];
            mp[v[i][j]].insert({i,j});
        }
    }
    ll ans=0;
    for(auto [x,y]:mp)
    {
        vi vx,vy;
        for(auto [p,q]:y)
        {
            vx.pb(p); vy.pb(q);
        }
        sort(vx.rbegin(),vx.rend());
        sort(vy.rbegin(),vy.rend());

        ans+=f(vx);
        ans+=f(vy);
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