/*
Problem 8: Redundant Connection
Level: Medium
Topic: DSU
Pattern: first edge that joins two already-connected vertices (LeetCode 684)

Problem Description:
A tree with n vertices had one extra edge added, giving n edges in total.
Print the edge that closes the cycle, i.e. the edge that, when processed in
input order, connects two vertices that are already connected.

Input:
n
u1 v1
...
un vn

Output:
Print u v of the redundant edge.

Constraints:
3 <= n <= 2 * 10^5
1 <= u, v <= n
The graph is connected and has exactly one cycle.

Sample Input:
3
1 2
1 3
2 3

Sample Output:
2 3

Approach:
Process edges in order. The edge whose endpoints already have the same leader
is the one that closes the cycle.

Time Complexity: O(n * alpha(n))
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
    int n;
    cin>>n;
    forn(i,1,n+1) make_set(i);
    int ru=-1,rv=-1;
    forn(i,0,n)
    {
        int u,v;
        cin>>u>>v;
        if(find(u)==find(v))
        {
            if(ru==-1) ru=u,rv=v;
        }
        else Union(u,v);
    }
    cout<<ru<<" "<<rv<<endl;
}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;  (single test case)
    while(t--) solve();
    return 0;
}