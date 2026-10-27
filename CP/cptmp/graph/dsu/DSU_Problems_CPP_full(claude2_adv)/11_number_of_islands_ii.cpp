/*
Problem 11: Number of Islands II (Grid DSU)
Level: Medium
Topic: DSU on a grid
Pattern: 2D cell -> id, add cells online, merge with 4 neighbours (LeetCode 305)

Problem Description:
An n x m grid is initially all water. Then q operations turn the cell (r, c)
into land. After each operation print the number of islands. Land cells that
share a side belong to the same island. Turning an already-land cell into land
changes nothing.

Input:
n m q
r1 c1
...
rq cq

Output:
q lines, the number of islands after each operation.

Constraints:
1 <= n * m <= 2 * 10^5
1 <= q <= 2 * 10^5
1 <= r <= n, 1 <= c <= m

Sample Input:
3 3 5
1 1
1 2
2 3
3 3
2 2

Sample Output:
1
1
2
2
1

Approach:
Map (r, c) to id = (r - 1) * m + c. When a cell becomes land, it is a new
island (+1). For each of its 4 land neighbours in a different component, Union
and subtract 1.

Time Complexity: O((n * m + q) * alpha(n * m))
Space Complexity: O(n * m)
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
    int n,m,q;
    cin>>n>>m>>q;
    forn(i,1,n*m+1) make_set(i);
    vector<char> land(n*m+1,0);
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    int comp=0;
    while(q--)
    {
        int r,c;
        cin>>r>>c;
        int id=(r-1)*m+c;
        if(!land[id])
        {
            land[id]=1;
            comp++;
            forn(k,0,4)
            {
                int nr=r+dr[k],nc=c+dc[k];
                if(nr<1||nr>n||nc<1||nc>m) continue;
                int nid=(nr-1)*m+nc;
                if(land[nid] && find(nid)!=find(id))
                {
                    Union(nid,id);
                    comp--;
                }
            }
        }
        cout<<comp<<endl;
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