/*
Problem 10: Lexicographically Smallest Array With Allowed Swaps
Level: Medium
Topic: DSU + Sorting
Pattern: swaps define groups; inside a group any permutation is reachable
         (LeetCode 1202)

Problem Description:
You are given an array a of n integers and m pairs (i, j). You may swap
a[i] and a[j] for any listed pair, any number of times. Print the
lexicographically smallest array you can obtain.

Input:
n m
a1 a2 ... an
i1 j1
...
im jm

Output:
Print the final array.

Constraints:
1 <= n, m <= 2 * 10^5
1 <= a[i] <= 10^9
1 <= i, j <= n

Sample Input:
5 3
5 4 3 2 1
1 2
2 3
4 5

Sample Output:
3 4 5 1 2

Approach:
Indices connected by swaps form a component, and inside a component the values
can be arranged in any order. For each component, sort its values and place
them on its sorted indices.

Time Complexity: O((n + m) * alpha(n) + n log n)
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
    vi a(n+1);
    forn(i,1,n+1) cin>>a[i];
    forn(i,1,n+1) make_set(i);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        Union(u,v);
    }
    vector<vi> idx(n+1),val(n+1);
    forn(i,1,n+1)
    {
        int r=find(i);
        idx[r].pb(i);          // indices come in increasing order
        val[r].pb(a[i]);
    }
    forn(r,1,n+1)
    {
        sort(all(val[r]));
        forn(k,0,(int)idx[r].size()) a[idx[r][k]]=val[r][k];
    }
    forn(i,1,n+1) cout<<a[i]<<" \n"[i==n];
}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;  (single test case)
    while(t--) solve();
    return 0;
}