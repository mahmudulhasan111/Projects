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
    vll a(n);
    forn(i,0,n)
    {
        cin >> a[i];
    }

    vector<pll> p;
    ll cnt=0;

    forn(i,0,n-1)
    {
        cnt++;
        if(a[i]!=a[i+1])
        {
            p.pb({a[i],cnt});
            cnt=0;
        }
    }
    if(a[n-1]==a[n-2])
    {
        cnt++;
        p.pb({a[n-1],cnt});
    }
    else p.pb({a[n-1],1});
    
    int k=p.size();

    bool add_2=false, add1=false;

    forn(i,1, k)
    {
        if(p[i].second==p[i-1].second)
        {
            cout << k+2 << endl;
            return;
        }
    }

    forn(i,0,n)
    {
        if(p[i].second>=2)
        {
            bool opA=(i>=1 &&(i==1 || p[i].first!=p[i-2].first));
            bool opB= (i<=k-2 && (i==k-2 || p[i].first!=p[i+2].first));

            if(opA || opB) {
                cout << k+1 << endl;
                return;
            }
        }
    }
    cout << k << endl;
    
    

   
}

void solve2(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<pair<int, int>> p;
    int cnt = 1;
    for (int i = 1; i < n; i++){
        if (a[i] == a[i - 1]) {
            cnt++;
        } else {
            p.push_back({a[i-1], cnt});
            cnt = 1;
        }
    }
    p.push_back({a[n-1], cnt});

    int k = p.size();
    bool can_add_2 = false;
    for (int i = 0; i < k - 1; i++){
        if (p[i].second >= 2 && p[i + 1].second >= 2){
            can_add_2 = true;
            break;
        }
    }

    if (can_add_2) {
        cout << k + 2 << "\n";
        return;
    }

    bool can_add_1 = false;
    for (int i = 0; i < k; i++){
        if (p[i].second >= 2) {
            bool optA = (i >= 1) && (i == 1 || p[i - 2].first != p[i].first);
            bool optB = (i <= k - 2) && (i == k - 2 || p[i + 2].first != p[i].first);
            if (optA || optB){
                can_add_1 = true;
                break;
            }
        }
    }

    if (can_add_1) {
        cout << k + 1 << "\n";
    } else {
        cout << k << "\n";
    }
}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve2();
    return 0;
}