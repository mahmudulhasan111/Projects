/*
Problem 13: Connect All Cities With Pre-built Roads
Level: Medium
Topic: DSU + Kruskal
Pattern: Kruskal where some edges have cost 0 (union them first)

Problem Description:
There are n cities. k roads already exist (free). There are also m candidate
roads, each with a building cost. Find the minimum total cost to make all
cities connected, or -1 if it is impossible.

Input:
n m k
u1 v1 w1       (m candidate roads)
...
um vm wm
a1 b1          (k existing roads)
...
ak bk

Output:
Print the minimum cost, or -1.

Constraints:
1 <= n <= 2 * 10^5
0 <= m, k <= 2 * 10^5
1 <= u, v, a, b <= n
0 <= w <= 10^9

Sample Input:
4 4 1
1 2 5
2 3 1
3 4 2
1 4 7
1 2

Sample Output:
3

Approach:
Union all existing roads first. Then run Kruskal on the candidate roads sorted
by cost until only one component remains.

Time Complexity: O((m log m) + (n + m + k) * alpha(n))
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
    int n,m,k;
    cin>>n>>m>>k;
    vector<Edge> e(m);
    for(auto &x:e) cin>>x.u>>x.v>>x.w;
    forn(i,1,n+1) make_set(i);
    int comp=n;
    while(k--)
    {
        int a,b;
        cin>>a>>b;
        if(find(a)!=find(b))
        {
            Union(a,b);
            comp--;
        }
    }
    sort(all(e),[](const Edge &a,const Edge &b){ return a.w<b.w; });
    ll cost=0;
    for(auto &x:e)
    {
        if(comp==1) break;
        if(find(x.u)!=find(x.v))
        {
            Union(x.u,x.v);
            cost+=x.w;
            comp--;
        }
    }
    cout<<(comp==1?cost:-1)<<endl;
}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;  (single test case)
    while(t--) solve();
    return 0;
}