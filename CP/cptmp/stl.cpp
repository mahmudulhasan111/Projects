// ======================= C++ STL CONTEST CHEAT SHEET (DETAILED) =======================
// Purpose: Keep open during contest | Copy-paste friendly | With return type + TC
// ================================================================================

#include <bits/stdc++.h>
using namespace std;

// ======================= FAST IO =======================
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)

// ======================= TYPEDEFS =======================
typedef long long ll;              // 64-bit integer
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

// ======================= CONSTANTS =======================
const int INF = 1e9;                // large int
const ll LINF = 1e18;               // large ll

// ======================= ALGORITHMS =======================

/* -------------------- sort -------------------- */
// sort(begin, end) → void | TC: O(n log n)
// sort(v.begin(), v.end());
// sort(v.begin(), v.end(), greater<int>());

/* -------------------- reverse -------------------- */
// reverse(begin, end) → void | TC: O(n)
// reverse(v.begin(), v.end());

/* -------------------- rotate -------------------- */
// rotate(first, middle, last) → void | TC: O(n)
// makes middle become first
// rotate(v.begin(), v.begin()+k, v.end());   // left rotate k
// rotate(v.begin(), v.end()-k, v.end());     // right rotate k

/* -------------------- min / max element -------------------- */
// min_element(begin, end) → iterator | TC: O(n)
// max_element(begin, end) → iterator | TC: O(n)
// *min_element(v.begin(), v.end());

/* -------------------- sum -------------------- */
// accumulate(begin, end, init) → value | TC: O(n)
// accumulate(v.begin(), v.end(), 0LL);

/* -------------------- count -------------------- */
// count(begin, end, x) → int | TC: O(n)

/* -------------------- find -------------------- */
// find(begin, end, x) → iterator | TC: O(n)
// returns end() if not found

/* -------------------- binary search family -------------------- */
// sorted container required
// binary_search → bool | TC: O(log n)
// lower_bound → iterator (>=x) | TC: O(log n)
// upper_bound → iterator (>x)  | TC: O(log n)

// ======================= VECTOR =======================
// push_back(x) → void | amortized O(1)
// pop_back() → void | O(1)
// size() → size_t | O(1)
// clear() → void | O(n)

// ======================= SET =======================
// set<int> s; (ordered, unique)
// insert(x) → pair<it,bool> | O(log n)
// erase(x) → size_t | O(log n)
// count(x) → 0/1 | O(log n)
// find(x) → iterator | O(log n)
// lower_bound(x) → iterator | O(log n)

// ======================= MULTISET =======================
// multiset<int> ms; (ordered, duplicates)
// insert(x) → iterator | O(log n)
// erase(ms.find(x)) → void | O(log n) (single erase)

// ======================= MAP =======================
// map<K,V> mp; (ordered by key)
// mp[x] → reference | O(log n)
// insert({k,v}) → pair<it,bool> | O(log n)
// erase(k) → size_t | O(log n)
// find(k) → iterator | O(log n)

// ======================= UNORDERED MAP =======================
// unordered_map<K,V> ump; (hash table)
// average O(1), worst O(n)

// ======================= STACK =======================
// push(x) | O(1)
// pop() | O(1)
// top() → reference | O(1)

// ======================= QUEUE =======================
// push(x) | O(1)
// pop() | O(1)
// front() → reference | O(1)

// ======================= DEQUE =======================
// push_front / push_back | O(1)
// pop_front / pop_back | O(1)

// ======================= PRIORITY QUEUE =======================
// priority_queue<int> pq;                   // max heap
// priority_queue<int, vi, greater<int>> pq; // min heap
// push(x) | O(log n)
// pop() | O(log n)
// top() → reference | O(1)

// ======================= STRING =======================
// substr(pos,len) → string | O(len)
// find(t) → index / npos | O(n)
// reverse(s.begin(), s.end())

// ======================= PERMUTATIONS =======================
// next_permutation → bool | O(n)
// do{}while(next_permutation(v.begin(), v.end()));

// ======================= BIT OPERATIONS =======================
// __builtin_popcount(x) → int | O(1)
// __builtin_clz(x) → leading zeros | O(1)
// __builtin_ctz(x) → trailing zeros | O(1)

// ======================= GCD / LCM =======================
// gcd(a,b) → value | O(log min(a,b))
// lcm(a,b) → value

// ======================= RANDOM =======================
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(l,r)(rng);

// ======================= DEBUG =======================
// cerr << "debug" << endl;

// Returns a vector of unique elements in the order of their first appearance
vll get_unique_sequential(const vll &arr) {
    unordered_set<ll> seen;
    vll result;
    for(auto val : arr){
        if(seen.find(val) == seen.end()){
            result.push_back(val);
            seen.insert(val);
        }
    }
    return result;
}


int main(){
    fast_io;
    int n,m,x,y,k,a,b,c;

    // IMPORTANT CP DECLARATIONS + FUNCTIONS + NESTED

// 1D Vector
vector<int> v;                                      // empty
vector<int> v(n);                                   // size n, init 0
vector<int> v(n, x);                                // size n, init x

// 2D Vector
vector<vector<int>> a;                              // empty
vector<vector<int>> b(n, vector<int>(m));           // n×m, init 0
vector<vector<int>> c(n, vector<int>(m, x));        // n×m, init x
vector<vector<int>> d{{1,2,3},{4,5,6}};              // initializer list

// Nested Vector (3D)
vector<vector<vector<int>>> v3(n, vector<vector<int>>(m, vector<int>(k, x))); // n×m×k, init x

// Pair / Nested Pair
pair<int,int> p;                                   // pair
pair<int,int> p2 = {x, y};                          // init
pair<int,pair<int,int>> np = {a, {b, c}};           // nested pair

// Map / Nested Map
map<int,int> mp;                                   // ordered map
unordered_map<int,int> ump;                         // unordered map
map<int, vector<int>> mpv;                          // map of vector
map<int, map<int,int>> mp2;                         // nested map

// Set / Nested Set
set<int> st;                                       // ordered set
unordered_set<int> ust;                             // unordered set
set<pair<int,int>> s_pair;                           // set of pairs
set<vector<int>> s_vec;                              // set of vectors

// Stack / Queue / Heap
stack<int> st;                                      // stack
queue<int> q;                                       // queue
priority_queue<int> pq;                             // max heap
priority_queue<int, vector<int>, greater<int>> pq2; // min heap
stack<pair<int,int>> st_pair;                        // stack of pairs

// String
string s;                                           // string
string s2 = "abc";                                  // init

// 2D Array
int arr[n][m];                                      // 2D array
int arr2[n][m] = {0};                               // init 0

// IMPORTANT FUNCTIONS

// max / min (2 or more values)
max(a, b);                                          // max of 2
min(a, b);                                          // min of 2
max({a, b, c});                                     // max of ≥2
min({a, b, c});                                     // min of ≥2

// GCD / LCM
__gcd(a, b);                                        // gcd
lcm(a, b);                                          // lcm (C++17)

// Vector operations
sort(v.begin(), v.end());                           // sort asc
reverse(v.begin(), v.end());                        // reverse
accumulate(v.begin(), v.end(), 0LL);                // sum
*max_element(v.begin(), v.end());                   // max element
*min_element(v.begin(), v.end());                   // min element

// Binary Search
binary_search(v.begin(), v.end(), x);               // exists?
lower_bound(v.begin(), v.end(), x);                 // first ≥ x
upper_bound(v.begin(), v.end(), x);                 // first > x

// Nested Loops / Iteration
for(auto &row : b)                                  // iterate 2D vector row
    for(auto &val : row)                            // iterate each element
        val = 0;

for(auto &[key, val] : mpv)                         // iterate map<int, vector<int>>
    for(auto &x : val)
        x += 1;

 return 0;
}

// ======================= HOW TO CALL FUNCTIONS (NAMING RULE) =======================
// Contest rule: how to remember WHICH prefix to use
// s.   → set / multiset
// mp.  → map
// ms.  → multiset (explicit)
// v.   → vector (only size / push / pop etc)
// all. → generic STL algorithms (find / count / sort / rotate)

// ======================= CONTAINER-SPECIFIC BUILT-IN FUNCTIONS =======================
// (Use these instead of generic algorithms when available — more efficient)

/* -------- vector / array / deque -------- */
// find(v.begin(), v.end(), x) → iterator | O(n)
// count(v.begin(), v.end(), x) → int | O(n)
// lower_bound / upper_bound (sorted) → iterator | O(log n)
// NOTE: No member find/count

/* -------- string -------- */
// s.find(t) → index / npos | avg O(n)
// s.substr(pos,len) → string | O(len)
// count(s.begin(), s.end(), c) → int | O(n)

/* -------- set (ordered, unique) -------- */
// s.find(x) → iterator | O(log n)
// s.count(x) → 0/1 | O(log n)
// s.lower_bound(x) → iterator | O(log n)
// s.upper_bound(x) → iterator | O(log n)

/* -------- multiset (ordered, duplicates) -------- */
// ms.find(x) → iterator (one occurrence) | O(log n)
// ms.count(x) → frequency | O(log n)
// ms.lower_bound / upper_bound → iterator | O(log n)

/* -------- map (ordered by key) -------- */
// mp.find(k) → iterator | O(log n)
// mp.count(k) → 0/1 | O(log n)
// mp[k] → reference (inserts if absent) | O(log n)

/* -------- unordered_set -------- */
// us.find(x) → iterator | avg O(1)
// us.count(x) → 0/1 | avg O(1)

/* -------- unordered_map -------- */
// ump.find(k) → iterator | avg O(1)
// ump.count(k) → 0/1 | avg O(1)

/* -------- priority_queue -------- */
// pq.top() → reference | O(1)
// pq.push(x) | O(log n)
// pq.pop() | O(log n)

/* -------- stack / queue -------- */
// stack: top / push / pop | O(1)
// queue: front / push / pop | O(1)

// ======================= END =======================
