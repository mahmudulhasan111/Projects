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

int n, m; 
vector<vector<bool>> grid_visited;
vector<vector<int>> grid_dist;
vector<vector<pii>> grid_parent;
vector<pair<int,int>> direction = {{-1,0}, {1,0}, {0,-1}, {0,1}};
vector<string> grid;
// Boundary Check Function
bool valid(int r, int c) {
    if ((r < 0 || r >= n || c < 0 || c >= m)  ) return false;
    if (grid[r][c]=='#') return false;
    return true;
}


void grid_dfs(int r, int c) {
    grid_visited[r][c] = true;

    for (auto [dr, dc] : direction) {
        int nr = r + dr;
        int nc = c + dc;

        if (valid(nr, nc) && !grid_visited[nr][nc]) {
            grid_parent[nr][nc] = {r, c};
            grid_dfs(nr, nc);
        }
    }
}

void solve()
{
   
    cin >> n >> m;
    grid_visited.assign(n, vector<bool>(m, false));
    grid_dist.assign(n, vector<int>(m, -1));
    grid_parent.assign(n, vector<pii>(m, {-1, -1}));

    grid.resize(n);
    forn(i,0,n)
    {
        cin >> grid[i];
    }
    // for(auto x:grid)
    // {
    //     cout << x << endl;
    // }
    // cout << endl;

    forn(i,0,n)
    {
        forn(j,0,m)
        {
            if(grid[i][j]=='B')
            {
                 for (auto [dr, dc] : direction) {
                    int nr = i + dr;
                    int nc = j + dc;

                    if (valid(nr, nc) && grid[nr][nc]=='.') {
                        grid[nr][nc]='#';
                    }
                }
            }
        }
    }

    if(grid[n-1][m-1]!='#') grid_dfs(n-1,m-1);
    bool ok=true;

     forn(i,0,n)
    {
        forn(j,0,m)
        {
            if(grid[i][j]=='B' && grid_visited[i][j])
            {
                ok=false;
            }

            if(grid[i][j]=='G' && !grid_visited[i][j])
            {
                ok=false;
            }
        }
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;


}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}