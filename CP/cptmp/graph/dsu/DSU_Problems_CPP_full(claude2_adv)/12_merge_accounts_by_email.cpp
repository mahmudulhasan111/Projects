/*
Problem 12: Merge Accounts by Shared Email
Level: Medium
Topic: DSU + Hashing strings
Pattern: map strings to ids, merge items that share a key (LeetCode 721)

Problem Description:
There are n accounts. Account i has k_i emails. Two accounts belong to the same
person if they share at least one email (directly or through other accounts).
Print the number of distinct people, then the number of accounts of each person
in non-increasing order.

Input:
n
k1 email email ... email
...
kn email email ... email

Output:
First line: number of people.
Second line: the group sizes in non-increasing order.

Constraints:
1 <= n <= 2 * 10^5
Total number of emails <= 2 * 10^5
Each email is a string of length <= 50

Sample Input:
4
2 a@x b@x
1 b@x
2 c@x d@x
1 d@x

Sample Output:
2
2 2

Approach:
Remember which account first used each email in a hash map. If an email was
seen before, Union the current account with that first account.

Time Complexity: O((n + E) * alpha(n)) expected, E = total emails
Space Complexity: O(n + E)
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
    unordered_map<string,int> owner;
    forn(i,1,n+1)
    {
        int k;
        cin>>k;
        while(k--)
        {
            string e;
            cin>>e;
            auto it=owner.find(e);
            if(it==owner.end()) owner[e]=i;
            else Union(i,it->second);
        }
    }
    vi sizes;
    forn(i,1,n+1) if(find(i)==i) sizes.pb(sz[i]);
    sort(sizes.rbegin(),sizes.rend());
    cout<<sizes.size()<<endl;
    forn(i,0,(int)sizes.size()) cout<<sizes[i]<<" \n"[i+1==(int)sizes.size()];
}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;  (single test case)
    while(t--) solve();
    return 0;
}