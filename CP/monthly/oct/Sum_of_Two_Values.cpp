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
    int n, t;
    cin >> n >> t;
    vector<pii> a(n);
    forn(i,0,n) {cin >> a[i].first; a[i].second=i;}
    sort(all(a));

    forn(i,0,n)
    {
        int x=t-a[i].first;
        auto it= upper_bound(all(a),make_pair(x,a[i].second));

        if(it->first==x)
        {
            cout << a[i].second +1<<" " << it->second+1 << endl;
            return;
        }



    }
    cout << "IMPOSSIBLE" <<endl;
}
void solve2()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
      map<int,int>mp;
    forn(i,0,n) {
        cin >> a[i];
        if(mp.count(t-a[i]))
        {
            cout << i+1 <<" "<< mp[t-a[i]]+1 << endl;
            return;
        }
        mp[a[i]]=i;
    }
  
   
    
    
    cout << "IMPOSSIBLE" <<endl;
}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;
    while(t--) solve2();
    return 0;
}