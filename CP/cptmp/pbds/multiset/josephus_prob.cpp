#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/* 
   =====================================================================
   সমস্যার বিষয়: 
   - ১ থেকে N পর্যন্ত মান বৃত্তাকারে নিয়ে প্রতি পদক্ষেপে K-তম মানটিকে সরিয়ে দেওয়া।
   
   PBDS-এর ভূমিকা:
   - Modulo অ্যারিথমেটিক ব্যবহার করে পরবর্তী ডিলিট হওয়া মানটির ইনডেক্স বের করা হয় 
     এবং find_by_order(current_idx) দিয়ে O(\log N) সময়ে তাকে সেটে খুঁজে সরিয়ে দেওয়া হয়।
   =====================================================================
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    ordered_set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);

    int current_idx = 0;
    while (!st.empty()) {
        // পরের বাদ পড়ার ইনডেক্স হিসাব করা
        current_idx = (current_idx + k) % st.size();
        
        // উক্ত ইনডেক্সের পয়েন্টার বের করা
        auto it = st.find_by_order(current_idx);
        cout << *it << (st.size() == 1 ? "" : " ");
        
        // সেট থেকে রিমুভ করা
        st.erase(it);
    }
    cout << "\n";

    return 0;
}