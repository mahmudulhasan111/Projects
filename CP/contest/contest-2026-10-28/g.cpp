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
    int n,m;
    cin >> n >> m;
    vector<vll>v(n,vll(m,0));

    vll xr_row(n),xr_col(m);

    forn(i,0,n)
    {
        forn(j,0,m)
        {
            cin >> v[i][j];
        }
    }

    forn(i,0,n)
    {
        ll xr=0;
        forn(j,0,m)
        {
            xr=xr^v[i][j];
        }
        xr_row[i]=xr;
    }

    forn(j,0,m)
    {
        ll xr=0;
        forn(i,0,n)
        {
            xr=xr^v[i][j];
        }
        xr_col[j]=xr;
    }

    ll ans=0;
    forn(i,0,n)
    {
        ans+=xr_row[i];
    }
    forn(j,0,m)
    {
        ans+=xr_col[j];
    }


    ll mn=LLONG_MAX;
    forn(i,0,n)
    {
        forn(j,0,m)
        {
            ll r=xr_row[i]^v[i][j];
            ll c=xr_col[j]^v[i][j];
            ll z1=ans-xr_row[i]-xr_col[j]+(c^r);
           mn=min(mn,z1);
        }
    }
    cout << mn << endl;
    


}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}


