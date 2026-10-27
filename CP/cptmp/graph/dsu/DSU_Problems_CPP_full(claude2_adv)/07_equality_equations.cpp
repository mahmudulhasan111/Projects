/*
Problem 7: Equality Equations
Level: Medium
Topic: DSU
Pattern: "==" merges, "!=" is checked after all merges (LeetCode 990 style)

Problem Description:
There are n variables numbered 1..n and m statements. Each statement is
either "u == v" or "u != v". Determine whether all statements can be true
at the same time.

Input:
n m
u1 op1 v1
...
um opm vm        (op is the string == or !=)

Output:
Print YES if the statements can all hold, otherwise print NO.

Constraints:
1 <= n, m <= 2 * 10^5
1 <= u, v <= n

Sample Input:
4 3
1 == 2
2 == 3
1 != 3

Sample Output:
NO

Approach:
First process every "==" statement with Union. Then for every "!=" statement,
if both variables are in the same component the statements contradict.

Time Complexity: O((n + m) * alpha(n))
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

void solve()
{
    int n,m;
    cin>>n>>m;
    forn(i,1,n+1) make_set(i);
    vector<pii> neq;
    while(m--)
    {
        int u,v;
        string op;
        cin>>u>>op>>v;
        if(op=="==") Union(u,v);
        else neq.pb({u,v});
    }
    bool ok=true;
    for(auto &p:neq)
    {
        if(find(p.first)==find(p.second)) ok=false;
    }
    cout<<(ok?"YES":"NO")<<endl;
}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;  (single test case)
    while(t--) solve();
    return 0;
}