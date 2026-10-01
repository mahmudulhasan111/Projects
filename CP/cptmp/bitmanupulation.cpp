#include <bits/stdc++.h>
using namespace std;

/* =====================================================
   COMPLETE BIT MANIPULATION + BITMASK TEMPLATE for CP
   Every builtin function explained, all utilities reusable
   Copy‑paste any part into your contest code
   ===================================================== */

/* ======================= BUILTIN FUNCTIONS =======================
   1) __builtin_popcount(x)      -> int এ কয়টা set bit আছে
   2) __builtin_popcountll(x)    -> long long এ কয়টা set bit আছে
   3) __builtin_clz(x)           -> leading zero count (32 bit)
   4) __builtin_clzll(x)         -> leading zero count (64 bit)
   5) __builtin_ctz(x)           -> trailing zero count (32 bit)
   6) __builtin_ctzll(x)         -> trailing zero count (64 bit)
   7) __builtin_parity(x)        -> set bit সংখ্যা odd না even
   8) __builtin_parityll(x)      -> same for long long
   9) __lg(x)                    -> floor(log2(x)),
                                    highest set bit index (0-based, x > 0)
                                    binary size = __lg(x) + 1
==================================================================== */


/* ======================= BASIC BIT TRICKS ======================= */
// check ith bit:          n & (1<<i)
// set ith bit:            n | (1LL << i)
// clear ith bit:          n & ~(1LL << i)
// toggle ith bit:         n ^ (1LL << i)
// extract lowest set bit: n & -n
// remove lowest set bit:  n & (n - 1)

//log₂(n) (floored).
// highest bit index:      63 - __builtin_clzll(n)   or __lg(n)
// lowest bit index:       __builtin_ctzll(n)
// check power of two:     (n > 0 && (n & (n-1)) == 0)

/* ======================= FUNCTIONS (REUSABLE) ======================= */

int highestSetBit(long long n){
    if(n == 0) return -1;
    return 63 - __builtin_clzll(n);
}

int lowestSetBit(long long n){
    if(n == 0) return -1;
    return __builtin_ctzll(n);
}

bool isPowerOfTwo(long long n){ return n > 0 && (n & (n - 1)) == 0; }

int countBitsFast(long long n){ return __builtin_popcountll(n); }

int countBitsSlow(long long n){
    int c = 0;
    while(n){ n &= (n - 1); c++; }
    return c;
}
//=========================get xor from 0 to n============================
int pref_xor(int n)
{
    if(n%4==0)  return n;
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    return 0;
}

/* ======================= BITMASK BASICS ======================= */
// full mask: (1LL << n) - 1
// iterate all bits 0 to n-1:
// for(int i = 0; i < n; i++) if(mask & (1LL << i)){}

/* Correct version you asked for */
vector<int> getBits(long long n){
    long long mask = (1LL << n);
    vector<int> v;
    for(int i = 0; i < n; i++){
        if(mask & (1LL << i)) v.push_back(i);
    }
    return v;
}

/* real version (extract bits of any mask) */
vector<int> getSetBitsOfMask(long long mask){
    vector<int> v;
    for(int i = 0; i < 63; i++) if(mask & (1LL << i)) v.push_back(i);
    return v;
}

/* iterate all submasks */
vector<long long> getSubmasks(long long mask){
    vector<long long> v;
    for(long long sub = mask; sub; sub = (sub - 1) & mask) v.push_back(sub);
    return v;
}

/* ======================= GRAY CODE ======================= */
vector<int> grayCode(int n){
    vector<int> g;
    int total = 1 << n;
    for(int i = 0; i < total; i++) g.push_back(i ^ (i >> 1));
    return g;
}

/* ======================= SOS DP TEMPLATE ======================= */
void SOSdp(vector<int> &f, int n){
    for(int i = 0; i < n; i++){
        for(int mask = 0; mask < (1 << n); mask++){
            if(mask & (1 << i)) f[mask] += f[mask ^ (1 << i)];
        }
    }
}

/* ======================= TSP BITMASK DP EXAMPLE ======================= */
int tspExample(int n, vector<vector<int>> &cost){
    int N = 1 << n;
    const int INF = 1e9;
    vector<vector<int>> dp(N, vector<int>(n, INF));
    dp[1][0] = 0;
    for(int mask = 0; mask < N; mask++){
        for(int last = 0; last < n; last++){
            if(!(mask & (1 << last))) continue;
            for(int nxt = 0; nxt < n; nxt++){
                if(mask & (1 << nxt)) continue;
                int nmask = mask | (1 << nxt);
                dp[nmask][nxt] = min(dp[nmask][nxt], dp[mask][last] + cost[last][nxt]);
            }
        }
    }
    int ans = INF;
    for(int i = 0; i < n; i++) ans = min(ans, dp[(1 << n) - 1][i] + cost[i][0]);
    return ans;
}

/* ======================= MAIN (TEST AREA) ======================= */
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n = 29;
    cout << "popcount: " << __builtin_popcountll(n) << " ";
    cout << "leading zeros: " << __builtin_clzll(n) << " ";
    cout << "trailing zeros: " << __builtin_ctzll(n) << " ";
    cout << "highest bit: " << highestSetBit(n) << " ";
    cout << "lowest bit: " << lowestSetBit(n) << " ";

    return 0;
}

