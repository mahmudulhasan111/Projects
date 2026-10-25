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


// ll binpow(ll a,ll b){ll res=1;a%=MOD;while(b>0){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
// ll modinv(ll a){return binpow(a,MOD-2);}
// ll fact(ll n){ll r=1;for(ll i=1;i<=n;i++)r=(r*i)%MOD;return r;}
// ll nPr(ll n,ll r){if(r>n)return 0;ll res=1;for(ll i=0;i<r;i++)res=(res*(n-i))%MOD;return res;}
// // // ll nCr(ll n,ll r){if(r>n)return 0;if(r>n-r)r=n-r;ll res=1;for(ll i=1;i<=r;i++)res=res*(n-r+i)/i;return res;}
// ll mex_sort(vector<ll> a)
// {
//     sort(a.begin(), a.end());

//     ll mex = 0;
//     for(ll x : a){
//         if(x == mex)
//             mex++;
//         else if(x > mex)
//             break;
//     }
//     return mex;
// }

void solve()
{
    ll n,k;
    cin >> n >> k;
    vll a(n+1);
    vll cnt(101,0);
    forn(i,1,n+1)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    // sort(all(a));
    // vll mex1;
    // ll mx=0;
    

    // forn(i,1,n+1)
    // {
    //     mx=max(mx,a[i]);
    //     if(i%k==0)
    //     {
    //         mex1.pb(mx);
    //         mx=0;
    //     }
    // }
    // cout << mex_sort(mex1) << endl;

    ll x=0,ans=-1;
    for(int i=0;i<n+1;i++)
    {
        if(cnt[i]>0)
        {
            if(cnt[i]+x>=k)
            {
                
                ll z=(cnt[i]+x-k);
                x=z;
            }
            else {
                ans=i ; break;
            }
        }
        else {ans=i; break;}
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