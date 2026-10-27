/*
Problem 16: Connectivity With Weight Limit (Offline Queries)
Level: Hard
Topic: DSU + Offline sorting
Pattern: sort edges and queries by weight, add edges while weight <= limit
         (LeetCode 1697 / minimum bottleneck path)

Problem Description:
Given a weighted undirected graph with n vertices and m edges, answer q queries
(u, v, x): is there a path from u to v using only edges of weight <= x ?

Input:
n m q
u1 v1 w1
...
um vm wm
u1 v1 x1
...
uq vq xq

Output:
For each query print YES or NO, in the original order.

Constraints:
1 <= n, m, q <= 2 * 10^5
1 <= u, v <= n
0 <= w, x <= 10^9

Sample Input:
4 3 3
1 2 5
2 3 3
3 4 8
1 3 5
1 4 7
1 4 8

Sample Output:
YES
NO
YES

Approach:
Sort edges by weight and queries by limit. Sweep the queries in increasing
limit, uniting every edge with weight <= limit, then test find(u) == find(v).
Store answers by the original query index.

Time Complexity: O((m + q) log(m + q) + (n + m + q) * alpha(n))
Space Complexity: O(n + m + q)
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

struct Edge
{
    int u,v;
    ll w;
};

struct Query
{
    int u,v,id;
    ll x;
};

void solve()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<Edge> e(m);
    for(auto &x:e) cin>>x.u>>x.v>>x.w;
    vector<Query> qs(q);
    forn(i,0,q)
    {
        cin>>qs[i].u>>qs[i].v>>qs[i].x;
        qs[i].id=i;
    }
    sort(all(e),[](const Edge &a,const Edge &b){ return a.w<b.w; });
    sort(all(qs),[](const Query &a,const Query &b){ return a.x<b.x; });
    forn(i,1,n+1) make_set(i);
    vector<char> ans(q,0);
    int p=0;
    for(auto &Q:qs)
    {
        while(p<m && e[p].w<=Q.x)
        {
            Union(e[p].u,e[p].v);
            p++;
        }
        ans[Q.id]=(find(Q.u)==find(Q.v));
    }
    forn(i,0,q) cout<<(ans[i]?"YES":"NO")<<endl;
}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;  (single test case)
    while(t--) solve();
    return 0;
}