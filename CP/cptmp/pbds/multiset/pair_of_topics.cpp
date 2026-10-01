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
   - এমন জোড়া (i, j) বের করতে হবে যেখানে (a_i - b_i) + (a_j - b_j) > 0 হয়।
   
   PBDS-এর ভূমিকা:
   - c[i] = a[i] - b[i] ধরে নিয়ে প্রসেস হওয়া এলিমেন্টগুলো PBDS-এ রাখা হয়।
   - st.order_of_key({-c[i] + 1, -1}) দিয়ে -c[i]-এর চেয়ে বড় কয়টি উপাদান সেটে আছে 
     তা O(\log N) সময়ে গণনা করে উত্তর বের করা হয়।
   =====================================================================
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) c[i] = a[i] - b[i];

    ordered_set<pair<long long, int>> st;
    long long total_pairs = 0;

    for (int i = 0; i < n; i++) {
        // -c[i]-এর চেয়ে বড় কয়টি উপাদান ইতিমধ্যে সেটে আছে তা গণনা করা
        long long count_less_equal = st.order_of_key({-c[i] + 1, -1});
        total_pairs += (st.size() - count_less_equal);

        // বর্তমান c[i] কে সেটে যুক্ত করা
        st.insert({c[i], i});
    }

    cout << total_pairs << "\n";
    return 0;
}