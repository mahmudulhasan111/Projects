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
   - বার বার নির্দিষ্ট ইনডেক্সের উপাদান ডিলিট করে তার মান প্রিন্ট করা।
   
   PBDS-এর ভূমিকা:
   - অ্যারে থেকে কোনো উপাদান মুছলে বাকিগুলো সরাতে O(N) লাগে।
   - PBDS-এর find_by_order(p - 1) দিয়ে p-তম উপাদানটি O(\log N)-এ পাওয়া যায় 
     এবং সহজে মুছেও ফেলা যায়।
   =====================================================================
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    // {ইনডেক্স, ইনপুট মান} পেয়ার আকারে সেটে রাখা হচ্ছে
    ordered_set<pair<int, int>> st; 
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        st.insert({i, val}); 
    }

    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        pos--; // 0-indexed এ পরিবর্তন

        // p-তম উপাদান খুঁজে বের করা
        auto it = st.find_by_order(pos);
        cout << it->second << (i == n - 1 ? "" : " ");
        
        // সেট থেকে সেই পজিশনের মান মুছে ফেলা
        st.erase(it);
    }
    cout << "\n";

    return 0;
}