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

const int MaxN=1e5+10;
int parent[MaxN];
int sz[MaxN];

void make_set(int v)
{
    parent[v]=v;
    sz[v]=1;
}

int find(int v)
{
    if(parent[v]==v) return v;
    return parent[v]=find(parent[v]);
}

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
        parent[leader_b]=leader_a;
        sz[leader_a]+=sz[leader_b];
    }
}

void solve()
{
    char c;
    cin>>c;

    string s;
    getline(cin,s);

    int n=c-'A'+1;

    forn(i,0,n)
    {
        make_set(i);
    }

    while(getline(cin,s) && !s.empty())
    {
        int a=s[0]-'A';
        int b=s[1]-'A';
        Union(a,b);
    }

    int components=0;

    forn(i,0,n)
    {
        if(find(i)==i) components++;
    }

    cout<<components<<endl;
}

int main()
{
    fast_io;

    int t;
    cin>>t;

    string s;
    getline(cin,s);
    getline(cin,s);

    while(t--)
    {
        solve();

        if(t) cout<<endl;
    }

    return 0;
}