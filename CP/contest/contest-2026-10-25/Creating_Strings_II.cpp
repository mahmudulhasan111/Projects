#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
// template <typename T>
// using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
// ll fact(ll n){ll r=1;for(ll i=1;i<=n;i++)r=(r*i)%MOD;return r;}
// ll nPr(ll n,ll r){if(r>n)return 0;ll res=1;for(ll i=0;i<r;i++)res=(res*(n-i))%MOD;return res;}
// ll nCr(ll n,ll r){if(r>n)return 0;if(r>n-r)r=n-r;ll res=1;for(ll i=1;i<=r;i++)res=res*(n-r+i)/i;return res;}

const int MAXN = 1e6;

vector<ll> fact(MAXN + 1), invfact(MAXN + 1);



void init_fact()
{
    fact[0] = 1;
    for(int i = 1; i <= MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    invfact[MAXN] = modinv(fact[MAXN]);
    for(int i = MAXN - 1; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
}

void solve()
{
    string s;
    cin >> s;
    ll n=s.size();
    map<char,ll>f;
    forn(i,0,n)
    {
        f[s[i]]++;
    }
    ll z=1;
    for(auto [x,y]:f)
    {
        z=(z*invfact[y])%MOD;
    }
    ll ans=(fact[n]%MOD*z%MOD)%MOD;
    cout << ans << endl;
}

int main()
{
    fast_io;
    int t=1;
    init_fact();
    // cin>>t;
    while(t--) solve();
    return 0;
}