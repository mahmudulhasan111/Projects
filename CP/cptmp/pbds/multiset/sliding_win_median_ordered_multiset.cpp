#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
struct ordered_multiset {
    ordered_set<pair<T, int>> st;
    int timer = 0;

    void insert(T val) {
        st.insert({val, timer++});
    }

    void erase(T val) {
        auto it = st.lower_bound({val, 0});
        if (it != st.end() && it->first == val) {
            st.erase(it);
        }
    }

    int order_of_key(T val) {
        return st.order_of_key({val, 0});
    }

    T find_by_order(int k) {
        if (k < 0 || k >= (int)st.size()) return -1;
        return st.find_by_order(k)->first;
    }

    int size() { return st.size(); }
    bool empty() { return st.empty(); }
};

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int main() {
    fast_io;

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ordered_multiset<long long> oms;

    // ১. প্রথম K সাইজের উইন্ডো তৈরি করা
    for (int i = 0; i < k; i++) {
        oms.insert(a[i]);
    }

    // K সাইজের উইন্ডোর মিডিয়ান ইনডেক্স (0-based)
    int median_idx = (k - 1) / 2;
    cout << oms.find_by_order(median_idx);

    // ২. স্লাইডিং উইন্ডো চালানো: পুরোনো মান মুছে নতুন মান ঢোকানো
    for (int i = k; i < n; i++) {
        oms.erase(a[i - k]); // উইন্ডোর বাইরের মান মুছে ফেলা (Erase)
        oms.insert(a[i]);     // নতুন মান যুক্ত করা (Insert)

        cout << " " << oms.find_by_order(median_idx); // মিডিয়ান প্রিন্ট করা
    }
    cout << "\n";

    return 0;
}