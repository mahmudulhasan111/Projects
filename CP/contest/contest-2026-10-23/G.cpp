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
vector<vector<int>> adj_list;
vll component_nodes;
vector<bool>visited;
void dfs(int u){
    visited[u] = true;
    component_nodes.push_back(u);
    for (int v : adj_list[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void solve()
{
    int n,m;

   
   
    cin >> n >> m;
    adj_list.assign(n+1, {});
    visited.assign(n+1, false);
    while(m--)
    {
        int grp;
        cin >> grp;
        if(grp==0) continue;
        int fst_user;
        cin >> fst_user;
        forn(i,1,grp)
        {
            int nxt; cin >> nxt;
            adj_list[fst_user].pb(nxt);
            adj_list[nxt].pb(fst_user);
        }
    }
    vll ans(n+1);
    forn(i,1,n+1)
    {
        
        if(!visited[i])
        {
            component_nodes.clear();
            dfs(i);
            int sz=component_nodes.size();
            for(auto x:component_nodes)
            {
                ans[x]=sz;
            }
        }
    }
    forn(i,1,n+1)
    {
        cout << ans[i] << " ";
    }
    cout  << endl;
   
}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}