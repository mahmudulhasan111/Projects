/*
Problem 14: Online Bipartite Check (DSU with Parity)
Level: Hard
Topic: DSU with parity
Pattern: store "same side / different side" relative to the leader;
         an edge inside one component with equal parity = odd cycle

Problem Description:
A graph starts with n isolated vertices. Edges are added one by one. After
each edge, print YES if the graph is still bipartite, otherwise NO.

Input:
n m
u1 v1
...
um vm

Output:
m lines, YES or NO after each edge.

Constraints:
1 <= n, m <= 2 * 10^5
1 <= u, v <= n

Sample Input:
3 3
1 2
2 3
3 1

Sample Output:
YES
YES
NO

Approach:
pr[v] is the parity (0/1) of v relative to parent[v]; with path compression it
becomes the parity relative to the leader. For edge (u, v): if they are in the
same component, the edge is fine only when pr[u] != pr[v]. Otherwise attach one
leader below the other with parity pr[u] ^ pr[v] ^ 1.
Once the graph is not bipartite it stays that way.

Time Complexity: O((n + m) * alpha(n))
Space Complexity: O(n)
*/

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

/*basic DSU without OPTIMIZATION

const int MaxN=1e5+10;
int parent[MaxN];


void make_set(int v)
{
    parent[v]=v;
}

int find(int v)
{
    if(parent[v]=v) return v;
    return find(parent[v]);
}

void Union(int a, int b)
{
    int leader_a=find(a);
    int leader_b=find(b);

    if(leader_a!=leader_b)
    {
        parent[leader_b]=leader_a;
    }

}


*/

//OPTIMIZED DSU Template


const int MaxN=2e5+10;
int parent[MaxN];
int sz[MaxN];

//create set with size
void make_set(int v)
{
    parent[v]=v;
    sz[v]=1;

}

int find(int v)
{
    if(parent[v]==v) return v;
    return parent[v]=find(parent[v]); //path compression
}
//union by size
void Union(int a, int b)
{
    int leader_a=find(a);
    int leader_b=find(b);

    if(leader_a!=leader_b)
    {
        if(sz[leader_a]<sz[leader_b])
        {
            swap(leader_a,leader_b);
        }
        parent[leader_b]=leader_a;        //new leader updated 
        sz[leader_a]+=sz[leader_b];  // updated size of new leader
    }

}

int pr[MaxN];   // parity of v relative to parent[v] (leader has 0)

int find_p(int v)
{
    if(parent[v]==v) return v;
    int r=find_p(parent[v]);
    pr[v]^=pr[parent[v]];   // parent[v] already points to leader here
    return parent[v]=r;
}

// returns false if adding edge (u,v) creates an odd cycle
bool unite_p(int u,int v)
{
    int ru=find_p(u),rv=find_p(v);
    if(ru==rv) return pr[u]!=pr[v];
    if(sz[ru]<sz[rv]) swap(ru,rv);
    parent[rv]=ru;
    pr[rv]=pr[u]^pr[v]^1;
    sz[ru]+=sz[rv];
    return true;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    forn(i,1,n+1) make_set(i);
    bool ok=true;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        if(ok && !unite_p(u,v)) ok=false;
        cout<<(ok?"YES":"NO")<<endl;
    }
}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;  (single test case)
    while(t--) solve();
    return 0;
}