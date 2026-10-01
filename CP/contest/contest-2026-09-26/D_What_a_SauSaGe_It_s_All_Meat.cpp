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
int ans(map<int,int>&mp)
{
    int res=0;
    for(auto &[x,y]:mp)
    {
        res+=y;
    }
    return res;
}
void solve()
{
    int n,q;
    cin >> n >> q;
    vi a(n);
    map<int,int>mp;
    forn(i,0,n)
    {
        cin >> a[i];
        int cnt=__builtin_popcount(a[i]);
        if(cnt&1) continue;
        else{
            mp[a[i]]++;
        } 
    }

    cout << ans(mp) << " ";
    while(q--)
    {
        int i, val;
        cin >> i >> val;
        i--;
        if(mp[a[i]]) mp[a[i]]--;
        a[i]=val;
        int cnt=__builtin_popcount(val);
       if(cnt%2==0) mp[val]++;
        cout << ans(mp) << " ";
         
    }
    cout << endl;


}
vi p={3,6,9,12,15};
bool ans1(int val)
{
    int mask=1<<5;
   
    forn(i,0,mask)
    {
         bitset<5>b(i);
        int z=val;
        forn(j,0,5)
        {
            if(b[j]) z^=p[j];
        }
        if(z%3==0) return true;
    }
    return false;
}
void solve2()
{
    int n,q;
    cin >> n >> q;
    vi a(n);
    map<int,int>mp;
    int sum=0;
    forn(i,0,n)
    {
        cin >> a[i];
        if(ans1(a[i]))
        {
            sum++;mp[i]++;
        }
    }
    cout << sum << " ";
    while(q--)
    {
        int i,val;
        cin >> i >> val;
        i--;
        if(mp[i]){
            sum--;
            mp[i]=0;
        }
        if(ans1(val)) {sum++;mp[i]++;}
        cout << sum << " ";
    }

   cout << endl;



}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}