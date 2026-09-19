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

// void solve()
// {
//     int n;
//     cin >> n;
//     string s;
//     cin >> s;
//     vi occ;
//     int cnt0=0,cnt1=0;
//     forn(i,0,n)
//     {
//         if(s[i]=='0')
//         {
//             if(cnt1)
//             {
//                 occ.pb(cnt1);
//                 cnt1=0;
//             }
//             cnt0++;
//         }
//         else{
//              if(cnt0)
//             {
//                 occ.pb(cnt0);
//                 cnt0=0;
//             }
//             cnt1++;
//         }
//     }
//     if(cnt1)
//     {
//         occ.pb(cnt1);
        
//     }
//     if(cnt0) occ.pb(cnt0);
//     int m=occ.size();
//     if(m==1 && n>2)
//     {
//         cout << -1 << endl;return;
//     }
//     map<int ,int> mp;
//     if(s[0]=='0')
//     {
//         for(int i=0;i<m-1;i+=2)
//         {
//             mp[0]+=occ[i]-1;
//             mp[1]+=occ[i+1]-1;
//         }
//     }
//     else{
//         for(int i=0;i<m-1;i+=2)
//         {
//             mp[1]+=occ[i]-1;
//             mp[0]+=occ[i+1]-1;
//         }
//     }
//     // cout << mp[0] <<" " << mp[1]<< endl;
//     int ex0=0, ex1=1;
//     if(s[0]=='0') ex0++;
//     else ex1++;

//     if(s[n-1]=='0') ex0++;
//     else ex1++;

//     int ans=0;
    
//     if(mp[0]>mp[1])
//     {
//         if(mp[1]+ex1<mp[0]-1)
//         {
//             cout << -1 << endl;
//             return;
//         }
//         else  ans= mp[0]+max(mp[1],mp[0]-1);
//     }
//     else{
//          if(mp[0]+ex0<mp[1]-1)
//         {
//             cout << -1 << endl;
//             return;
//         }
//         else  ans= mp[1]+max(mp[0],mp[1]-1);
//     }
//     cout << ans << endl;

// }
void solve2(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt0 = 0, cnt1 = 0;
    for (char c : s){
        if (c == '0') cnt0++;
        else cnt1++;
    }

    int diff = cnt0 - cnt1;

    if (abs(diff) > 2){
        cout << -1 << endl;
        return;
    }

    int run_count = 0;
    int first_0 = -1, last_0 = -1;
    int first_1 = -1, last_1 = -1;

    for (int i = 0; i < n; i++){
        if (i == 0 || s[i] != s[i - 1]){
            run_count++;
            if (s[i] == '0'){
                if (first_0 == -1) first_0 = run_count;
                last_0 = run_count;
            } else{
                if (first_1 == -1) first_1 = run_count;
                last_1 = run_count;
            }
        }
    }

    int max_len = -1;

    if (diff >= 0 && diff <= 2){
        if (first_0 != -1 && last_0 != -1 && first_0 <= last_0){
            max_len = max(max_len, last_0 - first_0 + 1);
        }
    }

    if (diff >= -2 && diff <= 0){
        if (first_1 != -1 && last_1 != -1 && first_1 <= last_1){
            max_len = max(max_len, last_1 - first_1 + 1);
        }
    }

    if (diff >= -1 && diff <= 1){
        if (first_0 != -1 && last_1 != -1 && first_0 <= last_1){
            max_len = max(max_len, last_1 - first_0 + 1);
        }
    }

    if (diff >= -1 && diff <= 1){
        if (first_1 != -1 && last_0 != -1 && first_1 <= last_0){
            max_len = max(max_len, last_0 - first_1 + 1);
        }
    }

    if (max_len == -1){
        cout << -1 << endl;
    } else{
        cout << n - max_len << endl;
    }
}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve2();
    return 0;
}