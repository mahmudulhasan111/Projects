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
    vll v(n);
    forn(i,0,n)
    {
        cin >> v[i];
    }
    vector<vector<ll>> a(n, vector<ll>(m));

    forn(i,0,n)
    {
        forn(j,0,m)
        {
            cin >> a[i][j];

        }
    }
    ll ans=m;
    multiset<ll>ms;
    rev(i,n-1,0)
    {
        forn(j,0,m)
        {
            ms.insert(a[i][j]);
        
            
        }
        ll cnt=0;
        for(auto it=ms.rbegin();it!=ms.rend()  && cnt<m ;it++)
        {
            v[i]-=*it;
            cnt++;
            if(v[i]<=0)
            {
                ans=min(ans,cnt);
            }
            
        }
    }
    cout << ans << endl;

}
void solve2()
{
    int n,m;
    cin >> n >> m;
    vll v(n);
    forn(i,0,n)
    {
        cin >> v[i];
    }
    vector<vector<ll>> a(n, vector<ll>(m));

    forn(i,0,n)
    {
        forn(j,0,m)
        {
            cin >> a[i][j];

        }
    }
    ll ans=m;
    multiset<ll>ms;
    rev(i,n-1,0)
    {
        forn(j,0,m)
        {
            ms.insert(a[i][j]);
            int k=ms.size();
            if(k>m)
            {
                ms.erase(ms.begin());
            }
        
        }
        ll cnt=0;
        for(auto it=ms.rbegin();it!=ms.rend() ;++it)
        {
            v[i]-=*it;
            cnt++;
            if(v[i]<=0)
            {
                ans=min(ans,cnt);
            }
            
        }
    }
    cout << ans << endl;

}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}