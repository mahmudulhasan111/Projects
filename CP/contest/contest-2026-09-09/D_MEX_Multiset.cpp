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

// int mex_freq(const vector<int>& a)
// {
//     int n = a.size();
//     vector<int> freq(n + 1, 0);

//     for(int x : a){
//         if(x >= 0 && x <= n)
//             freq[x]++;
//     }

//     int mex = 0;
//     while(freq[mex]) mex++;
//     return mex;
// }
void solve()
{
    int n;
    cin >> n;
    multiset<int>a,b,c;
    string ans="";
    int cnt0=0;
    forn(i,0,n)
    {
        int x;
        cin >> x;
        if(x==0)
        {
             if(!a.count(x)) {a.insert(x); ans+="A";}
             else if(!b.count(x)){ b.insert(x), ans+="B";}
             else ans+="A";
             cnt0++;
        }
        else{
          c.insert(x); ans+='C';
            
            
            
        }
    }
    // vi va(all(a)), vb(all(b)), vc(all(c));
    // int mexA=mex_freq(va),mexB=mex_freq(vb), mexC=mex_freq(vc);
    // ll total=mexA+mexB+mexC;
    // ll mx=max({mexA, mexB, mexC});
    if(cnt0==1) 
    {
        cout << "NO" << endl; return;
    }
    cout << "YES" << endl;
    cout << ans << endl;


}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}