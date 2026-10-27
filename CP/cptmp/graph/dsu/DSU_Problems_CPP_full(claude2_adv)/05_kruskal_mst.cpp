/*
Problem 5: Minimum Spanning Tree (Kruskal's Algorithm)
Level: Medium
Topic: DSU + Greedy

Problem Description:
Given a connected, undirected, weighted graph, find the total weight of
its minimum spanning tree (MST).

Input:
n m
u1 v1 w1
u2 v2 w2
...
um vm

Output:
Print the total weight of the MST.

Constraints:
1 <= n <= 2 * 10^5
n - 1 <= m <= 2 * 10^5
1 <= u, v <= n
0 <= w <= 10^9
The graph is connected.

Sample Input:
4 5
1 2 1
2 3 2
3 4 3
1 4 10
1 3 5

Sample Output:
6

Approach:
Sort edges by increasing weight. Add an edge only when its endpoints
belong to different components. Stop after selecting n - 1 edges.

Time Complexity: O(m log m + m * alpha(n))
Space Complexity: O(n + m)
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

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<Edge> edges(m);
    for(auto &e:edges) cin>>e.u>>e.v>>e.w;

    sort(all(edges),[](const Edge &a,const Edge &b){ return a.w<b.w; });

    forn(i,1,n+1) make_set(i);
    ll total=0;
    int selected=0;
    for(auto &e:edges)
    {
        if(find(e.u)!=find(e.v))
        {
            Union(e.u,e.v);
            total+=e.w;
            selected++;
            if(selected==n-1) break;
        }
    }
    cout<<(selected==n-1?total:-1)<<endl;
}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;  (single test case)
    while(t--) solve();
    return 0;
}