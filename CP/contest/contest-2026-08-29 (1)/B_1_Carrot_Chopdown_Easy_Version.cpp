#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


template <typename T>
struct ordered_multiset {
    ordered_set<pair<T, int>> st;
    int timer = 0;

    
    void insert(T val) {
        st.insert({val, timer++});
    }

   
    void erase(T val) {
        auto it = st.lower_bound({val, 0});
        if (it != st.end() && it->first == val) {
            st.erase(it);
        }
    }

  
    int order_of_key(T val) {
        return st.order_of_key({val, 0});
    }

   
    T find_by_order(int k) {
        if (k < 0 || k >= (int)st.size()) return -1;
        return st.find_by_order(k)->first;
    }

    int size() { return st.size(); }
    bool empty() { return st.empty(); }
};

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

// void solve()
// {
//     int n,m;
//     cin >> n >> m;
//     ordered_multiset<int>oms;
//     forn(i,0,n)
//     {
//         int x;
//         cin >> x;
//         oms.insert(x);
//     }
//     forn(i,1,m)
//     {
//         ll bg=oms.size()-order_of_key(i);
//         ll cnt2x=oms.count(2*i);
//         ans=max(ans, bg+cnt2x);
//     }
//     cout << ans << endl;
// }
void solve()
{
    int n,m;
    cin >> n >> m;
    vll a(n),freq(m+2,0),suffix(m+2,0);
    forn(i,0,n)
    {
        int x;
        cin >> x;
        a[i]=x;
        freq[x]++;
    }
    rev(i,m,0)
    {
        suffix[i]=suffix[i+1]+freq[i+1];
    }
    int ans=0;
    forn(i,1,m+1)
    {
        int z=suffix[i]+freq[i];
        if(2*i<=m) z+=freq[2*i];
        ans=max(ans,z);
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