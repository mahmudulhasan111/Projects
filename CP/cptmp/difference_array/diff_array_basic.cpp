#include <bits/stdc++.h>
using namespace std;

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

/* 
   =====================================================================
   ১. 1D DIFFERENCE ARRAY (1-based indexing)
   
   কাজ:
   - update1D(l, r, val): [l, r] রেঞ্জের সব উপাদানের সাথে val যোগ করে -> O(1)
   - build1D(n): Prefix sum চালিয়ে ফাইনাল অ্যারে গঠন করে -> O(N)
   =====================================================================
*/
const int MAXN = 2e5 + 5;
ll diff1D[MAXN], a1D[MAXN];

void update1D(int l, int r, ll val) {
    diff1D[l] += val;
    diff1D[r + 1] -= val;
}

void build1D(int n) {
    for (int i = 1; i <= n; i++) {
        diff1D[i] += diff1D[i - 1]; // Prefix sum
        a1D[i] = diff1D[i];         // Final reconstructed array
    }
}

/* 
   =====================================================================
   ২. 2D DIFFERENCE ARRAY (1-based indexing)
   
   কাজ:
   - update2D(r1, c1, r2, c2, val): (r1, c1) থেকে (r2, c2) রেঞ্জে val যোগ করে -> O(1)
   - build2D(r, c): 2D Prefix sum দিয়ে ফাইনাল ম্যাট্রিক্স পুনর্গঠন করে -> O(R * C)
   =====================================================================
*/
const int MAXR = 1005, MAXC = 1005;
ll diff2D[MAXR][MAXC], a2D[MAXR][MAXC];

void update2D(int r1, int c1, int r2, int c2, ll val) {
    diff2D[r1][c1] += val;
    diff2D[r1][c2 + 1] -= val;
    diff2D[r2 + 1][c1] -= val;
    diff2D[r2 + 1][c2 + 1] += val;
}

void build2D(int rows, int cols) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            diff2D[i][j] += diff2D[i - 1][j] + diff2D[i][j - 1] - diff2D[i - 1][j - 1];
            a2D[i][j] = diff2D[i][j];
        }
    }
}

// মাল্টিপল টেস্টকেসের ক্ষেত্রে গ্লোবাল অ্যারে রিমেম্বারিং/ক্লিন করার ফাংশন
void clear1D(int n) {
    for (int i = 0; i <= n + 2; i++) diff1D[i] = 0, a1D[i] = 0;
}

void clear2D(int r, int c) {
    for (int i = 0; i <= r + 2; i++) {
        for (int j = 0; j <= c + 2; j++) {
            diff2D[i][j] = 0, a2D[i][j] = 0;
        }
    }
}

void solve()
{
    int n = 5;
    clear1D(n);

    // [2, 4] রেঞ্জে +5 এবং [1, 3] রেঞ্জে +2 যোগ করা
    update1D(2, 4, 5);
    update1D(1, 3, 2);

    build1D(n);

    // আউটপুট: 2 7 7 5 0
    forn(i, 1, n + 1) {
        cout << a1D[i] << " ";
    }
    cout << endl;
}

int main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}