/*
Problem 2: Connectivity Queries
Level: Basic
Topic: DSU

Problem Description:
Initially, n vertices are separate. Process q queries:
1 u v : connect the components containing u and v.
2 u v : print YES if u and v are connected, otherwise print NO.

Input:
n q
type u v
... (q queries)

Output:
For each type 2 query, print YES or NO.

Constraints:
1 <= n, q <= 2 * 10^5
1 <= u, v <= n

Sample Input:
5 5
1 1 2
1 2 3
2 1 3
2 1 4
2 4 5

Sample Output:
YES
NO
NO

Approach:
Use unite(u, v) for type 1. For type 2, vertices are connected exactly
when find_set(u) == find_set(v).

Time Complexity: O(q * alpha(n))
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
    int n,q;
    cin>>n>>q;
    forn(i,1,n+1) make_set(i);
    while(q--)
    {
        int type,u,v;
        cin>>type>>u>>v;
        if(type==1) Union(u,v);
        else cout<<(find(u)==find(v)?"YES":"NO")<<endl;
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