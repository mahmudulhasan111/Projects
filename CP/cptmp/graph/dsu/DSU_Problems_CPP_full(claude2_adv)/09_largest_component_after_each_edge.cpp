/*
Problem 9: Components and Largest Component After Each Edge
Level: Medium
Topic: DSU
Pattern: maintain extra info (count, maximum size) while merging

Problem Description:
A graph starts with n isolated vertices. Edges are added one by one. After
each edge, print the number of connected components and the size of the
largest component.

Input:
n m
u1 v1
...
um vm

Output:
m lines: "components largest_size" after each edge.

Constraints:
1 <= n, m <= 2 * 10^5
1 <= u, v <= n

Sample Input:
5 4
1 2
3 4
2 3
4 5

Sample Output:
4 2
3 2
2 4
1 5

Approach:
Keep the component count and the maximum size. A successful Union reduces the
count by one and may increase the maximum to the new leader's size.

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
    int comp=n,mx=1;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        if(find(u)!=find(v))
        {
            Union(u,v);
            comp--;
            mx=max(mx,sz[find(u)]);
        }
        cout<<comp<<" "<<mx<<endl;
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