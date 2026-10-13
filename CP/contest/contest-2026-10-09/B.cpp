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
    vector<vll> v(n,vll(m,0));
    vll row(n),col(m);

    forn(i,0,n)
    {
        ll rw=0;
        forn(j,0,m)
        {
            cin >> v[i][j];
            if(v[i][j]==0) rw++;
        }
        row[i]=rw;
    }
    forn(i,0,m)
    {
        ll cl=0;
        forn(j,0,n)
        {
            if(v[j][i]==0) 
            cl++;
        }
        col[i]=cl;
    }
    // for ( int i = 0; i < m; i++ ) {
    //     cerr << col[i] << endl;
    // }
     ll ans=0;
    forn(i,0,n)
    {
        if(row[i]==1)
        {
            ll cnt=0;
            forn(j,i+1,n)
            {
                if(row[j]==0) cnt++;
                else break;
            }
            rev(j,i-1,0)
            {
                if(row[j]==0) cnt++;
                else break;
            }
            ans=max(ans,cnt+1);

           // cerr << ans << ' ';
        }
    }
    //cerr << endl;

    
    forn(i,0,m)
    {
        if(col[i]==1)
        {
            ll cnt=0;
            forn(j,i+1,m)
            {
                if(col[j]==0) cnt++;
                else break;
            }
            rev(j,i-1,0)
            {
                if(col[j]==0) cnt++;
                else break;
            }
            ans=max(ans,cnt+1);
            //cerr << ans << ' ';
        }
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