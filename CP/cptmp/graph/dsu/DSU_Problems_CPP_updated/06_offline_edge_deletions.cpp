/*
Problem 6: Offline Connectivity After Edge Deletions
Level: Hard
Topic: DSU + Reverse Processing

Problem Description:
An initially connected or disconnected undirected graph has n vertices and m
edges. Then q operations delete edges. Each operation specifies an edge by
its 1-based index in the original edge list. Print the number of connected
components after each deletion.

Important:
The deleted edge indices are distinct. Since DSU cannot undo a union easily,
process operations in reverse: build the graph after all deletions, then add
deleted edges back in reverse order.

Input:
n m
u1 v1
...
um vm
q
d1
d2
...
dq

Output:
Print the number of connected components after each deletion, in the original
operation order.

Constraints:
1 <= n, m, q <= 2 * 10^5
1 <= u, v <= n
1 <= di <= m
All deletion indices are distinct.

Sample Input:
4 4
1 2
2 3
3 4
1 4
2
4
2

Sample Output:
1
2

Sample explanation:
After deleting edge 4, the graph is still connected.
After also deleting edge 2, edges 1 and 3 remain, so the graph has 2 components.

Approach:
Mark all edges that will be deleted. Build DSU using only edges that remain.
Then restore deleted edges from last to first. Record the component count before
restoring each edge; these are the answers after each forward deletion.

Time Complexity: O((n + m + q) * alpha(n))
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

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<pii> edges(m+1);
    forn(i,1,m+1) cin>>edges[i].first>>edges[i].second;

    int q;
    cin>>q;
    vi del(q);
    vector<bool> removed(m+1,false);
    forn(i,0,q)
    {
        cin>>del[i];
        removed[del[i]]=true;
    }

    forn(i,1,n+1) make_set(i);
    int comp=n;

    // build graph with edges that are never deleted
    forn(i,1,m+1)
    {
        if(!removed[i] && find(edges[i].first)!=find(edges[i].second))
        {
            Union(edges[i].first,edges[i].second);
            comp--;
        }
    }

    // add deleted edges back in reverse order
    vi ans(q);
    rev(i,q-1,0)
    {
        ans[i]=comp;
        int id=del[i];
        if(find(edges[id].first)!=find(edges[id].second))
        {
            Union(edges[id].first,edges[id].second);
            comp--;
        }
    }
    forn(i,0,q) cout<<ans[i]<<endl;
}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;  (single test case)
    while(t--) solve();
    return 0;
}