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
    int n;
    cin >> n;
    vll a(n),ans;

    // if(n==1) {
    //     cout << 1 << endl;return;
    // }
    forn(i,0,n)
    {
        cin >> a[i];
    }
    int pos=1;
    auto ok = [&](int x) {
        bool paisi=false;
        forn(i,1,n)
        {
            if(a[i]==x) {paisi=true;pos=i;}
            if(paisi) ans.pb(a[i]);
        }
    };


    
    if(a[0]!=n)
    {
        ok(n);
    }
    else {ok(n-1);}
    int pos2=-1;
    if(pos==n-1)
        rev(i,pos-1,0)
        {
            if(a[i]>=a[0]) ans.pb(a[i]);
            else{
                pos2=i;
                break;
            }
        }
    else{
        ans.pb(a[pos-1]);
        rev(i,pos-2,0)
        {
            if(a[i]>a[0]) ans.pb(a[i]);
            else{
                pos2=i;
                break;
            }
        }
    }
    forn(i,0,pos2+1){
        ans.pb(a[i]);
    }


    for(auto e:ans) cout << e << " ";
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