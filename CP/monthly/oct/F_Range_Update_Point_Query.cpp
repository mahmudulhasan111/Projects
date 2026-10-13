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

int dig_sum( ll val)
{
    int sum=0;
    while(val)
    {
        sum+=val%10;
        val/=10;
    }
    return sum;
}

void solve()
{
    int n,q;
    cin >> n >> q;
    vll a(n+1);
    forn(i,1,n+1) cin >> a[i];
    set<int> baki;
    forn(i,1,n+1) baki.insert(i);

    while(q--)
    {
        int type;
        cin >> type;
        if(type==1)
        {
            int l,r;
            cin >> l >> r;
            auto it=baki.lower_bound(l);

            while(it!=baki.end() && *it<=r)
            {
                int sm=dig_sum(a[*it]);
                a[*it]=sm;
                auto it2=baki.upper_bound(*it);
                if(sm<10){
                    baki.erase(it);
                }
                it=it2;
            }           

        }
        else{
            int x;
            cin >> x;
            cout << a[x] << endl;
        }
    }
}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}