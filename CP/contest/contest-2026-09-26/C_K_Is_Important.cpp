#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

/* 
   =====================================================================
   ১. ORDERED SET TEMPLATE (PBDS)
   
   কাজ: 
   - সাধারণ std::set-এর মতো সর্টেড এবং ইউনিক (Unique) ডেটা রাখে।
   - extra ক্ষমতা: 
     a) order_of_key(x): x-এর চেয়ে строго (strictly) ছোট কয়টি উপাদান আছে তা O(log N)-এ বলে।
     b) find_by_order(k): k-তম (0-indexed) উপাদানের পয়েন্টার O(log N)-এ দেয়।
   =====================================================================
*/
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/* 
   =====================================================================
   ২. ORDERED MULTISET TEMPLATE (Pair Trick)
   
   কাজ: 
   - ডুপ্লিকেট মান গ্রহণ করতে পারে (সাধারণ PBDS multiset-এ erase করলে সব একই মান মুছে যায়, 
     তাই এই Structure-এ {val, unique_timer} পেয়ার রাখা হয়েছে)।
   
   ফংশন সমূহের কাজ:
   - insert(val): নতুন মান সেটে যুক্ত করে।
   - erase(val): নির্দিষ্ট মানের যেকোনো একটি ইনস্ট্যান্স সেটে থাকলে তা মুছে ফেলে।
   - order_of_key(val): val-এর চেয়ে strictly ছোট কয়টি উপাদান আছে তা গুণ হিসাব করে।
   - find_by_order(k): k-তম (0-indexed) উপাদানের আসল মান রিটার্ন করে।
   - size(): সেটে বর্তমান মোট উপাদান সংখ্যা দেয়।
   - empty(): সেট খালি কি না তা টেস্ট করে।
   =====================================================================
*/
template <typename T>
struct ordered_multiset {
    ordered_set<pair<T, int>> st;
    int timer = 0;

    // সেটে নতুন মান যুক্ত করার কাজ
    void insert(T val) {
        st.insert({val, timer++});
    }

    // নির্দিষ্ট একটি মান সেটে থাকলে তা মুছে ফেলার কাজ
    void erase(T val) {
        auto it = st.lower_bound({val, 0});
        if (it != st.end() && it->first == val) {
            st.erase(it);
        }
    }

    // val-এর চেয়ে ছোট উপাদান সংখ্যা গণনা
    int order_of_key(T val) {
        return st.order_of_key({val, 0});
    }

    // k-তম পজিশনের আসল মান বের করা
    T find_by_order(int k) {
        if (k < 0 || k >= (int)st.size()) return -1;
        return st.find_by_order(k);
    }

    

    int size() { return st.size(); }
    bool empty() { return st.empty(); }

};

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
   
    int n,k;
    cin >> n >> k;
   vll a(n);
    forn(i,0,n)
    {
      cin >> a[i];
    }
  ll scr=0;
    int cnt= min(k-1,n-k+1);
    forn(i,0,cnt){
        scr += max(a[i], a[n-1-i]);
    }

    if (n >2*cnt){
        forn(i, k - 1, n-k + 1) {
            scr += a[i];
        }
    }


    cout << scr << endl;

}

int main()
{
    fast_io;
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}