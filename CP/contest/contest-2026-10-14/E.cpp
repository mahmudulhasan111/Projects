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

ll binpow(ll a,ll b){ll res=1;a%=MOD;while(b>0){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modinv(ll a){return binpow(a,MOD-2);}
ll fact(ll n){ll r=1;for(ll i=1;i<=n;i++)r=(r*i)%MOD;return r;}
ll nPr(ll n,ll r){if(r>n)return 0;ll res=1;for(ll i=0;i<r;i++)res=(res*(n-i))%MOD;return res;}
ll nCr(ll n,ll r){if(r>n)return 0;if(r>n-r)r=n-r;ll res=1;for(ll i=1;i<=r;i++)res=res*(n-r+i)/i;return res;}

void solve()
{
    string s,t;
    cin >> s >> t;
    if(s==t)
    {
        cout << "YES" <<endl; return;
    }
    int n=s.size();
    string p="";
    string q="";
    int idx1,idx2;
    forn(i,0,n)
    {
        if(s[i]!=t[i]){
             idx1=i;
            break;
        }
       

    }
    rev(i,n-1,0)
    {
        if(s[i]!=t[i])
        {
             idx2=i;
             break;
        }
    }
    int len=idx2-idx1+1;
    // cout << len << endl;
    p=s.substr(idx1,len);
    q=t.substr(idx1,len);
    // cout << p << " " << q << endl;
    reverse(all(p));
    if(p==q)
    {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;
    while(t--) solve();
    return 0;
}