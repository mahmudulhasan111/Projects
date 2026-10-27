/*
Problem 17: DSU With Rollback
Level: Hard
Topic: DSU with rollback (no path compression)
Pattern: union by size + stack of changes; building block of offline dynamic
         connectivity (divide and conquer over time)

Problem Description:
n vertices are initially separate. Process q operations:
1 u v : connect the components of u and v.
2     : undo the most recent type 1 operation that has not been undone yet.
3 u v : print YES if u and v are connected, otherwise NO.
4 u   : print the size of the component containing u.

Input:
n q
operation
... (q operations)

Output:
One line for each operation of type 3 or 4.

Constraints:
1 <= n, q <= 2 * 10^5
1 <= u, v <= n
Every type 2 operation has an un-undone type 1 operation to undo.

Sample Input:
5 8
1 1 2
1 2 3
3 1 3
2
3 1 3
4 1
2
4 1

Sample Output:
YES
NO
2
1

Approach:
Path compression cannot be undone, so use only union by size (find is
O(log n)). Every type 1 operation pushes (child leader, parent leader) on a
stack, or (0, 0) if nothing was merged. To undo, pop it, subtract the size and
make the child its own leader again.

Time Complexity: O(q log n)
Space Complexity: O(n + q)
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

int find_rb(int v)
{
    while(parent[v]!=v) v=parent[v];   // no path compression, so it can be rolled back
    return v;
}

vector<pii> history;   // (child leader, parent leader) or (0, 0) if no merge happened

void union_rb(int a,int b)
{
    a=find_rb(a);
    b=find_rb(b);
    if(a==b)
    {
        history.pb({0,0});
        return;
    }
    if(sz[a]<sz[b]) swap(a,b);
    parent[b]=a;
    sz[a]+=sz[b];
    history.pb({b,a});
}

void rollback()
{
    pii last=history.back();
    history.pop_back();
    if(last.first==0) return;
    int b=last.first,a=last.second;
    sz[a]-=sz[b];
    parent[b]=b;
}

void solve()
{
    int n,q;
    cin>>n>>q;
    forn(i,1,n+1) make_set(i);
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int u,v;
            cin>>u>>v;
            union_rb(u,v);
        }
        else if(type==2) rollback();
        else if(type==3)
        {
            int u,v;
            cin>>u>>v;
            cout<<(find_rb(u)==find_rb(v)?"YES":"NO")<<endl;
        }
        else
        {
            int u;
            cin>>u;
            cout<<sz[find_rb(u)]<<endl;
        }
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