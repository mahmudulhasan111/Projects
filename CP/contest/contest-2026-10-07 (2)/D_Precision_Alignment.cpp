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
    ll n, k;
    cin >> n >> k;
    
    vll sum(n),drawbacks(n);
    
    forn(i,0,n)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        
        sum[i]=a+b+c;
        if(a==b && b==c){ drawbacks[i]=-1; continue;}
       
       
        if(a>b || a>c ||b>c) drawbacks[i]=0;
        
        else{
            ll p=min({b-a+1,c-b+1});
            drawbacks[i]=p;

        }


        
    }

    
    
    auto ok=[&](ll mid){
        ll lagbe=0;
        forn(i,0,n)
        {
            if(drawbacks[i]==-1) 
            {
                if(mid>sum[i]) return false;
            }
            if(sum[i]<mid) lagbe+=mid-sum[i]+2*drawbacks[i];
            if(lagbe>k) return false;

        }
        return lagbe<=k;
    };


    ll l=-2e18,r=2e18+1,mid,ans=-1;
    while(l<=r){
        mid=l+(r-l)/2;
        if(ok(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;

    




}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}