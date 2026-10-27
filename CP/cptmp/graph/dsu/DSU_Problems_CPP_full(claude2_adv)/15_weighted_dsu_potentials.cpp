/*
Problem 15: Weighted DSU (Difference Constraints)
Level: Hard
Topic: Weighted DSU / potentials
Pattern: store x[v] - x[leader]; answer relation queries and detect conflicts

Problem Description:
There are n unknown values x1..xn. Process q operations:
1 a b d : add the fact x[b] - x[a] = d.
          Print OK if it is new or already implied, or CONFLICT if it
          contradicts earlier facts (a conflicting fact is ignored).
2 a b   : print x[b] - x[a] if it can be determined, otherwise UNKNOWN.

Input:
n q
type a b d    (type 1)
type a b      (type 2)
...

Output:
One line for every operation.

Constraints:
1 <= n, q <= 2 * 10^5
1 <= a, b <= n
|d| <= 10^9

Sample Input:
4 6
1 1 2 3
1 2 3 4
2 1 3
2 1 4
1 1 3 5
1 1 3 7

Sample Output:
OK
OK
7
UNKNOWN
CONFLICT
OK

Approach:
pot[v] = x[v] - x[parent[v]]; with path compression it becomes the difference to
the leader. For fact x[b] - x[a] = d with leaders ra, rb: if ra == rb the fact is
consistent iff pot[b] - pot[a] == d. Otherwise attach rb below ra with
pot[rb] = d + pot[a] - pot[b] (or the negative if ra is attached below rb).

Time Complexity: O((n + q) * alpha(n))
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

ll pot[MaxN];   // pot[v] = x[v] - x[parent[v]]

int find_w(int v)
{
    if(parent[v]==v) return v;
    int r=find_w(parent[v]);
    pot[v]+=pot[parent[v]];   // parent[v] already points to leader here
    return parent[v]=r;
}

void solve()
{
    int n,q;
    cin>>n>>q;
    forn(i,1,n+1) make_set(i);
    while(q--)
    {
        int type,a,b;
        cin>>type>>a>>b;
        int ra=find_w(a),rb=find_w(b);
        if(type==1)
        {
            ll d;
            cin>>d;
            if(ra==rb)
            {
                cout<<(pot[b]-pot[a]==d?"OK":"CONFLICT")<<endl;
            }
            else
            {
                ll val=d+pot[a]-pot[b];   // x[rb] - x[ra]
                if(sz[ra]<sz[rb])
                {
                    swap(ra,rb);
                    val=-val;
                }
                parent[rb]=ra;
                pot[rb]=val;
                sz[ra]+=sz[rb];
                cout<<"OK"<<endl;
            }
        }
        else
        {
            if(ra==rb) cout<<pot[b]-pot[a]<<endl;
            else cout<<"UNKNOWN"<<endl;
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