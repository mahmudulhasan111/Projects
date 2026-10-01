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
    int n;
    cin >> n;
    string s;
    cin >> s;
     int first_one=-1;
    for(int i=0;i<n;++i){
        if(s[i]=='1'){
            first_one=i;
            break;
        }
    }
    
    if(first_one==-1){
        cout<<0<<"\n";
        return;
    }
    
    if(first_one==0){
        int count_zero=0;
        for(char c:s){
            if(c=='0')count_zero++;
        }
        cout<<count_zero<<"\n";
        return;
    }
    
    vector<int> pref_1(n+1,0);
    for(int i=0;i<n;++i){
        pref_1[i+1]=pref_1[i]+(s[i]=='1'?1:0);
    }
    
    vector<int> suff_0(n+1,0);
    for(int i=n-1;i>=0;--i){
        suff_0[i]=suff_0[i+1]+(s[i]=='0'?1:0);
    }
    
    int min_ops=n+1;
    
    for(int p=first_one;p<=n;++p){
        int current_cost=pref_1[p]+suff_0[p];
        min_ops=min(min_ops,current_cost);
    }
    
    cout<<min_ops<<"\n";

}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}