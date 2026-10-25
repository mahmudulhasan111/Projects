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

// ll a,b;
// ll getDivisors(ll n) {
//     // vector<ll> divisors;
//     ll cnt=0;
//     for(ll i = 1; i * i <= n; i++) {
//         if(n % i == 0) {
//             if(i>=b) cnt++;
//             // if(i != n / i)
//             //     divisors.push_back(n / i);
//         }
//     }


//     return cnt;
// }
ll c=1;
// void solve()
// {
    
//     cin >> a >> b;
//     ll ans=getDivisors(a);
    
//     cout <<"Case "<< c<< ": " <<  ans << endl;
//     c++;
// }
const int N = 2e6+5;
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
map<ll, int> spf_factor_large(ll n) {
    map<ll, int> cnt;
    for (ll p : all_Primes) {
        if (p * p > n) break;
        if (n % p == 0) {
            while (n % p == 0) {
                cnt[p]++;
                n /= p;
            }
        }
    }
    if (n > 1) cnt[n]++;
    return cnt;
}


ll count_div(ll n){
    auto mp=spf_factor_large(n);
    ll r=1;
    for(auto [p,c]:mp) r*=(c+1);
    return r;
}

void solve()
{
    ll a,b;
    cin >> a >> b;
    if(b*b>a)
    {
        cout <<"Case "<< c<< ": " <<  0 << endl;
         c++;
         return;
    }

    ll total_pairs=count_div(a)/2;
    ll invalid_pair=0;
    forn(i,1,b)
    {
        if(a%i==0) invalid_pair++;
    }
    ll ans=total_pairs-invalid_pair;
    cout <<"Case "<< c<< ": " <<  ans << endl;
    c++;

}

int main()
{
    fast_io;
    int t=1;
    sieve();
    cin>>t;
    while(t--) solve();
    return 0;
}