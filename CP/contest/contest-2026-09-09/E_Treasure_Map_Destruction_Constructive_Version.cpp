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
vi compute_prefix(const vi &v){
    int n = v.size();           
    vi pre(n);                   
    if(n == 0) return pre;       

    pre[0] = v[0];               
    for(int i=1;i<n;i++){
        pre[i] = pre[i-1] + v[i];
    }
    return pre;
}
void solve()
{
    int n;
    cin >> n;
    vi a(n);
    forn(i,0,n)
    {
        cin >> a[i];
    }
    vi diff(n+2,0);
    forn(i,0,n)
    {
        if(a[i]>0)
        {
            int L=max(0,i-a[i]+1);
            int R=min(n-1,i+a[i]-1);
            if(L<=R)
            {
                diff[L]++;
                diff[R+1]--;
            }
            
        }
    }
    vi pre_diff=compute_prefix(diff);
    int valid=0, invalid=0;
    forn(i,0,n)
    {
        if(pre_diff[i]==0) valid++;
        else invalid++;
    }
    if(valid==0) 
    {
        cout << -1 << endl; return;
    }
    forn(i,0,n)
    {
        bool satisfied=false;
        if(a[i]>=0)
        {
            int l=i-a[i], r=i+a[i];
            if(l>=0 && pre_diff[l]==0) satisfied=true;
            if(r<n && pre_diff[r]==0) satisfied=true;
            if(!satisfied)
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    string ans="";
    forn(i,0,n)
    {
        if(pre_diff[i]==0) ans+='1';
        else ans+='0';
    }
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