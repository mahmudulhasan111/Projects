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
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;   // range LCM → initial value = 1
}
ll c=1;
void solve()
{
    ll n, m;
    cin >> n >> m;
    ll danger=0;
    vll a(m);
    forn(i,0,m)
    {
        cin >> a[i];
        //danger+=n/a[i];
    }

    for (int mask = 1; mask < (1LL << m); mask++){
    // cout << mask << " -> ";
        ll l=1;
        for (int k = 0; k < m; k++) {
        
            if (mask & (1LL << k)){
                // cout << 1 << " ";
                l=lcm(l,a[k]);


            }
       
        }
        ll z= __builtin_popcountll(mask);

        ll cnt=n/l;
        if(z&1) 
        danger+=cnt;
        else danger-=cnt;
    }
    cout << "Case " << c<< ": "<< n - danger << endl;
    c++;
}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}