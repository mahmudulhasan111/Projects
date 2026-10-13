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
vector<int>sal(2038+1);

bool is_leap(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
void precomputation()
{
    int x=3;
    forn(i,1970,2038)
    {
        sal[i]=x%7;
        x++;
        if(is_leap(i)) x++;


    }
}
// void print(int n)

// {
//        ll ans=62;
//     if(sal[n]==4 && n%4!=0)
//     {
//         cout << 61 << endl; return;
//     }
//     if(sal[n]>4 && n%4!=0)
//     {
//         ans=63;
//     }
//     if(sal[n]>3 && n%4==0)
//     {
//         ans=64;
//     }
//     cout << ans << endl;
// }
void solve()
{
    int n;
    cin >> n;
    // forn(i,1970,2018)
    // {
    //     cout << sal[i] << endl;
    // }

     
    // ll ans;
    // if(is_leap)
    // {
    //     if(sal[n]==0 || sal[n]==1 || sal[n]==4)
    //     ans=62;
        
    //     else if(sal[n]==2 || sal[n]==3 || sal[n]==5)
    //     ans=63;
    //     else ans=64;
    // }
    // else{
    //     if(sal[n]==4) ans=61;
    //     else if(sal[n]==1 || sal[n]==3) ans=62;
    //     else ans=63;
    // }



    // cout << ans << endl;


    // forn(i,1970,2038)
    // {
    //     print(1982);
    // }
    // cout << sal[n] << endl;


    int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int startdays=sal[n];
    if(is_leap(n)) month[1]=29;
    int rows=0;
    forn(i,0,12)
    {
        rows+=(startdays+month[i]+6)/7;
        startdays=(startdays+month[i])%7;
    }
    cout << rows << endl;



   



}

int main()
{
    fast_io;
    int t=1;
    // cin>>t;
    precomputation();
    while(t--) solve();
    return 0;
}