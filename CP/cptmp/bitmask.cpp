#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long

/* Print all masks with binary representation (LSB → MSB) */
void bitmask(int n) {
    for (int mask = 0; mask < (1 << n); mask++){
        // cout << mask << " -> ";
        for (int k = 0; k < n; k++) {
            if (mask & (1 << k)){
                // cout << 1 << " ";
            }
            else {
                // cout << 0 << " ";
            }
        }
        cout << '\n';
    }
}

/* Check if k-th bit is set */
inline bool isSet(int mask, int k) {
    return mask & (1 << k);
}

/* Set k-th bit */
inline int setBit(int mask, int k) {
    return mask | (1 << k);
}

/* Clear k-th bit */
inline int clearBit(int mask, int k) {
    return mask & ~(1 << k);
}

/* Toggle k-th bit */
inline int toggleBit(int mask, int k) {
    return mask ^ (1 << k);
}

/* Count number of set bits */
inline int countBits(int mask) {
    return __builtin_popcount(mask);
}

/* Get lowest set bit */
inline int lowestBit(int mask) {
    return mask & -mask;
}

/* Remove lowest set bit */
inline int removeLowestBit(int mask) {
    return mask & (mask - 1);
}

/* Iterate all subsets */
void iterateMasks(int n) {
    for (int mask = 0; mask < (1 << n); mask++) {
    }
}

/* Iterate elements inside a mask */
void iterateElements(int mask, int n) {
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
        }
    }
}

/* Iterate all submasks */
void iterateSubmasks(int mask) {
    for (int sub = mask; sub; sub = (sub - 1) & mask) {
    }
}

/* Iterate set bits only */
void iterateSetBits(int mask) {
    while (mask) {
        int bit = __builtin_ctz(mask);
        mask &= (mask - 1);
    }
}

/* Generate all subsets */
vector<vector<int>> generateSubsets(vector<int>& a) {
    int n = a.size();
    vector<vector<int>> res;

    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> cur;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) cur.push_back(a[i]);
        }
        res.push_back(cur);
    }
    return res;
}

/* Subset sum */
int subsetSum(vector<int>& a, int mask) {
    int sum = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        if (mask & (1 << i)) sum += a[i];
    }
    return sum;
}

/* Bitmask DP template */
void bitmaskDP(vector<int>& a) {
    int n = a.size();
    vector<int> dp(1 << n, 0);

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                int nmask = mask | (1 << i);
                dp[nmask] = max(dp[nmask], dp[mask] + a[i]);
            }
        }
    }
}

/* Print mask MSB → LSB */
void printMask(int mask, int n) {
    for (int i = n - 1; i >= 0; i--) {
        cout << ((mask >> i) & 1) << " ";
    }
    cout << '\n';
}

int main() {
    fast_io;

    int n = 3;
    bitmask(n);

    return 0;
}