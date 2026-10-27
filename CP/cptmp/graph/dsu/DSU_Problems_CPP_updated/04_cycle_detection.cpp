/*
Problem 4: Cycle Detection in an Undirected Graph
Level: Medium
Topic: DSU

Problem Description:
Given an undirected graph with n vertices and m edges, determine whether
the graph contains a cycle.

Input:
n m
u1 v1
u2 v2
...
um vm

Output:
Print CYCLE if the graph contains a cycle; otherwise print NO CYCLE.

Constraints:
1 <= n <= 2 * 10^5
0 <= m <= 2 * 10^5
1 <= u, v <= n

Sample Input:
4 4
1 2
2 3
3 4
4 1

Sample Output:
CYCLE

Approach:
For every edge (u, v), if u and v are already in the same component,
this edge closes a cycle. Otherwise, merge their components.

Note:
This standard DSU method assumes an undirected graph and detects a cycle
when processing the given edge list.

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

void solve()
{
    int n,m;
    cin>>n>>m;
    forn(i,1,n+1) make_set(i);
    bool cycle=false;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        if(find(u)==find(v)) cycle=true;   // already connected -> this edge closes a cycle
        else Union(u,v);
    }
    cout<<(cycle?"CYCLE":"NO CYCLE")<<endl;
}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;  (single test case)
    while(t--) solve();
    return 0;
}