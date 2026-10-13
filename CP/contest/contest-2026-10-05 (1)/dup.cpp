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
    // if()

    if(n<10)
    {
        cout << n << endl; return;
    }
    map<int,set<int>>mp;
    mp[1]={1,2,3,4,5,6,7,8,9,0};
    mp[2]={2,5,8,3,6,9,0};
    mp[3]={3,6,9}; mp[4]={4,7,5,8,6,9,0};
    mp[5]={5,6,8,9,0};
    mp[6]={6,9};
    mp[7]={7,8,9,0};
    mp[8]={0,8,9}; 
    mp[9]={9};
    mp[0]={0};

    int x=n/10;
    
    int z=x%10;
    set<pair<int,int>> st;
    
    for(auto p:mp[z])
    {
        int num=x*10+p;
        int diff=abs(num-n);
        st.insert(make_pair(diff,num));

    }
    x--;
    z=x%10;
     for(auto p:mp[z])
    {
        int num=x*10+p;
        int diff=abs(num-n);
        st.insert(make_pair(diff,num));

    }
    int ans=0;
    for(auto [x,y]:st)
    {
        ans=y;
        break;
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