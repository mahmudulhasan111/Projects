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
const int N = 500;
vector<long long > all_Primes;

void sieve(){
    vector<bool> prime(N+1,true);

    prime[0]=prime[1]=false;

    for(int i=2;i*i<=N;i++){
        if(prime[i]){
            for(int j=i*i;j<=N;j+=i){
                prime[j]=false;
            }
        }
    }

    for(int i=2;i<=N;i++){
        if(prime[i]){
            all_Primes.push_back(i);
        }
    }
}

ll power_in_fact(ll n,ll p){
    ll c=0;
    while(n){n/=p; c+=n;} return c;
}
void solve()
{
    int n,k;

    while(cin >> n >> k)
    {
        ll ans=1;
        for(auto p:all_Primes)
        {
            if(p>n) break;

            ll x=power_in_fact(n,p), y=power_in_fact(k,p), z=power_in_fact(n-k,p);
            ll res=x-y-z;
            if(res>=1) ans*=(res+1);
            
        }
        cout << ans << endl;
    }
}

int main()
{
    fast_io;
    int t=1;
    sieve();
    // cin>>t;
    while(t--) solve();
    return 0;
}