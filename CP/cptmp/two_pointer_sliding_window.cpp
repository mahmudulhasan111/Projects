#include <bits/stdc++.h>
using namespace std;

/* =====================================================================
   COMPLETE TWO POINTERS & SLIDING WINDOW MASTER TEMPLATE FOR CP
   Contains all 7 standard high-frequency patterns.
   ===================================================================== */

// ---------------------------------------------------------------------
// PATTERN 1: CONVERGING TWO POINTERS (OPPOSITE DIRECTION)
// Use Case: Pair Sum / 2-Sum on a sorted array
// Time: O(N), Space: O(1)
// ---------------------------------------------------------------------
bool hasPairWithSum(const vector<int>& a, long long target) {
    int l = 0, r = (int)a.size() - 1;
    
    while (l < r) {
        long long sum = a[l] + a[r];
        if (sum == target) return true;
        
        if (sum < target) l++;
        else r--;
    }
    return false;
}

// ---------------------------------------------------------------------
// PATTERN 2: SAME DIRECTION TWO POINTERS (FAST & SLOW)
// Use Case: In-place array modification / Remove duplicates
// Time: O(N), Space: O(1)
// ---------------------------------------------------------------------
int removeDuplicates(vector<int>& a) {
    if (a.empty()) return 0;
    
    int slow = 0;
    for (int fast = 1; fast < (int)a.size(); fast++) {
        if (a[fast] != a[slow]) {
            slow++;
            a[slow] = a[fast];
        }
    }
    return slow + 1; // Returns new size of unique elements
}

// ---------------------------------------------------------------------
// PATTERN 3: FIXED-SIZE SLIDING WINDOW
// Use Case: Max/Min sum or property for fixed window length K
// Time: O(N), Space: O(1)
// ---------------------------------------------------------------------
long long maxSubarraySumOfSizeK(const vector<int>& a, int k) {
    int n = a.size();
    if (n < k) return -1;

    long long window_sum = 0;
    for (int i = 0; i < k; i++) window_sum += a[i];

    long long max_sum = window_sum;
    for (int i = k; i < n; i++) {
        window_sum += a[i] - a[i - k]; // Add right, subtract left
        max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}

// ---------------------------------------------------------------------
// PATTERN 4: VARIABLE-SIZE SLIDING WINDOW (EXPAND & SHRINK)
// Use Case: Longest subarray with sum <= K (Non-negative values)
// Time: O(N), Space: O(1)
// ---------------------------------------------------------------------
int longestSubarrayWithSumAtMostK(const vector<int>& a, long long k) {
    int n = a.size();
    int l = 0, max_len = 0;
    long long current_sum = 0;

    for (int r = 0; r < n; r++) {
        current_sum += a[r]; // Expand
        
        while (current_sum > k && l <= r) { // Shrink when invalid
            current_sum -= a[l];
            l++;
        }
        
        max_len = max(max_len, r - l + 1); // Track valid window size
    }
    return max_len;
}

// ---------------------------------------------------------------------
// PATTERN 5: SLIDING WINDOW MAXIMUM / MINIMUM (MONOTONIC DEQUE)
// Use Case: Max/Min element in every sliding window of size K
// Time: O(N), Space: O(K)
// ---------------------------------------------------------------------
vector<int> maxSlidingWindow(const vector<int>& a, int k) {
    deque<int> dq; // Stores indices
    vector<int> result;

    for (int i = 0; i < (int)a.size(); i++) {
        // 1. Remove indices that are out of current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        // 2. Remove smaller elements from back
        while (!dq.empty() && a[dq.back()] <= a[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        // 3. Record max once first window of size K is formed
        if (i >= k - 1) {
            result.push_back(a[dq.front()]);
        }
    }
    return result;
}

// ---------------------------------------------------------------------
// PATTERN 6: COUNT SUBARRAYS WITH "AT MOST K" & "EXACTLY K" TRICK
// Formula: Exactly(K) = AtMost(K) - AtMost(K - 1)
// Time: O(N), Space: O(1)
// ---------------------------------------------------------------------
long long countSubarraysAtMostK(const vector<int>& a, long long k) {
    if (k < 0) return 0;
    int l = 0;
    long long current_sum = 0, count = 0;

    for (int r = 0; r < (int)a.size(); r++) {
        current_sum += a[r];
        
        while (current_sum > k && l <= r) {
            current_sum -= a[l];
            l++;
        }
        
        // Number of valid subarrays ending at index r
        count += (r - l + 1);
    }
    return count;
}

long long countSubarraysExactK(const vector<int>& a, long long k) {
    return countSubarraysAtMostK(a, k) - countSubarraysAtMostK(a, k - 1);
}

// ---------------------------------------------------------------------
// PATTERN 7: TWO POINTERS ON TWO SEPARATE ARRAYS
// Use Case: Compare / Match elements between two sorted arrays
// Time: O(N + M), Space: O(1)
// ---------------------------------------------------------------------
long long countCommonPairs(const vector<int>& a, const vector<int>& b) {
    int i = 0, j = 0;
    long long matching_pairs = 0;

    while (i < (int)a.size() && j < (int)b.size()) {
        if (a[i] == b[j]) {
            long long cntA = 0, cntB = 0, val = a[i];
            
            // Count duplicates in array A and B
            while (i < (int)a.size() && a[i] == val) { cntA++; i++; }
            while (j < (int)b.size() && b[j] == val) { cntB++; j++; }
            
            matching_pairs += (cntA * cntB);
        } 
        else if (a[i] < b[j]) i++;
        else j++;
    }
    return matching_pairs;
}

/* =====================================================================
   MAIN FUNCTION / TEST DEMONSTRATIONS
   ===================================================================== */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "--- TWO POINTERS & SLIDING WINDOW TEST RUN ---\n\n";

    // 1. Converging Two Pointers
    vector<int> sorted1 = {1, 3, 4, 6, 8, 10};
    cout << "1. Has Pair Sum (10): " << (hasPairWithSum(sorted1, 10) ? "YES" : "NO") << "\n";

    // 2. Fast & Slow Two Pointers
    vector<int> sorted2 = {1, 1, 2, 2, 3, 4, 4, 5};
    int unique_cnt = removeDuplicates(sorted2);
    cout << "2. Unique count: " << unique_cnt << " | Elements: ";
    for (int i = 0; i < unique_cnt; i++) cout << sorted2[i] << " ";
    cout << "\n";

    // 3. Fixed-Size Sliding Window
    vector<int> arr3 = {2, 1, 5, 1, 3, 2};
    cout << "3. Max sum of window size 3: " << maxSubarraySumOfSizeK(arr3, 3) << "\n";

    // 4. Variable-Size Sliding Window
    vector<int> arr4 = {1, 2, 1, 0, 1, 1, 0};
    cout << "4. Longest subarray length (sum <= 4): " << longestSubarrayWithSumAtMostK(arr4, 4) << "\n";

    // 5. Monotonic Deque Sliding Window
    vector<int> arr5 = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> max_win = maxSlidingWindow(arr5, 3);
    cout << "5. Max of every window of size 3: ";
    for (int x : max_win) cout << x << " ";
    cout << "\n";

    // 6. Subarrays with At Most K / Exactly K
    vector<int> arr6 = {1, 2, 1, 1, 3};
    cout << "6. Subarrays with Sum EXACTLY 3: " << countSubarraysExactK(arr6, 3) << "\n";

    // 7. Two Pointers on Two Separate Arrays
    vector<int> A = {1, 2, 2, 3, 5};
    vector<int> B = {2, 2, 3, 4, 5};
    cout << "7. Total Matching Pairs (A[i] == B[j]): " << countCommonPairs(A, B) << "\n";

    return 0;
}
