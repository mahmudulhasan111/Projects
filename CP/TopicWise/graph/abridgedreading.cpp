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

const int N = 3e5 + 9, LG = 18;

vector<int> g[N];
int par[N][LG + 1], dep[N], sz[N],path_sum[N];

vi pages;

void dfs(int u, int p = 0)
{
  par[u][0] = p;
  dep[u] = dep[p] + 1;
  sz[u] = 1;
  path_sum[u]=path_sum[p]+pages[u];
  for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1]; //binary lifting 2^3-->4+4
  for (auto v: g[u]) if (v != p) {
    dfs(v, u);
    sz[u] += sz[v];
  }
}

// এই ফাংশনটির কাজ হলো নোড u এবং v-এর সর্বনিম্ন সাধারণ পূর্বপুরুষ (Lowest Common Ancestor) বের করা।
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
  if (u == v) return u;
  for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
  return par[u][0];
}







void solve()
{
    int n,m;
    cin >> n >> m;
    
    pages.resize(n+1);
    forn(i,1,n+1) cin >> pages[i];
    vi in_degree(n+1,0),out_degree(n+1,0),leaves;
    while(m--)
    {
        int u,v;
        cin >> u >> v;
        g[u].pb(v);
        in_degree[v]++;
        out_degree[u]++;
    }
    forn(i,1,n+1) {
        if(in_degree[i]==0) g[0].pb(i);
        if(out_degree[i]==0) leaves.pb(i);
    }
    
    dfs(0,0);
    int n2=leaves.size(),ans=MOD;

    forn(i,0,n2)
    {
        forn(j,i+1,n2)
        {
            int u=path_sum[leaves[i]], v=path_sum[leaves[j]], l=path_sum[lca(leaves[i],leaves[j])];
            int res=u+v-l;
            ans=min(ans, res);
        }
    }
    cout << ans << endl;

}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}