#include <bits/stdc++.h>
using namespace std;

/* =====================================================
   C++ STRING COMPLETE PRACTICAL REFERENCE (CP)
   ===================================================== */

/* =====================
   BUILT-IN string (MOST USED)
   ===================== */

/*
Construction & Size
-------------------
string s;
string s = "abc";
string s(n, c);                  // "cccc..."
int n = s.size();                // or length()
bool ok = s.empty();
s.clear();

Access
------
s[i]
s.front()
s.back()

Append / Modify
---------------
s += "abc";
s += 'x';

s.append("abc");
s.append(3, 'x');

s.push_back('x');
s.pop_back();

Substring
---------
s.substr(pos, len)
s.substr(pos)

Find / Search
-------------
s.find("abc")
s.find('a', pos)
s.rfind("abc")

string::npos → not found

Insert / Erase / Replace
------------------------
s.insert(pos, "abc");
s.insert(pos, k, 'x');

s.erase(pos, len);
s.erase(iterator);

s.replace(pos, len, "abc");

Compare
-------
s == t
s < t
s.compare(t)

Algorithms
----------
reverse(s.begin(), s.end())
sort(s.begin(), s.end())
count(s.begin(), s.end(), 'a')

Conversion
----------
stoi(s), stoll(s)
to_string(x)

Input
-----
cin >> s
getline(cin, s)
*/

/* =====================
   IMPORTANT CUSTOM FUNCTIONS
   ===================== */

// palindrome check O(n)
bool is_palindrome(const string &s) {
    int l = 0, r = (int)s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

// reverse string
string reverse_string(string s) {
    reverse(s.begin(), s.end());
    return s;
}

// lowercase frequency
vector<int> freq_lower(const string &s) {
    vector<int> cnt(26, 0);
    for (char c : s) cnt[c - 'a']++;
    return cnt;
}

// anagram check
bool is_anagram(const string &a, const string &b) {
    if (a.size() != b.size()) return false;
    return freq_lower(a) == freq_lower(b);
}

// string rotation
bool is_rotation(const string &a, const string &b) {
    if (a.size() != b.size()) return false;
    return (a + a).find(b) != string::npos;
}

// split by delimiter
vector<string> split(const string &s, char delim) {
    vector<string> res;
    string cur;
    for (char c : s) {
        if (c == delim) {
            if (!cur.empty()) res.push_back(cur);
            cur.clear();
        } else cur += c;
    }
    if (!cur.empty()) res.push_back(cur);
    return res;
}

// trim spaces
string trim(string s) {
    int l = 0, r = (int)s.size() - 1;
    while (l <= r && isspace(s[l])) l++;
    while (l <= r && isspace(s[r])) r--;
    return s.substr(l, r - l + 1);
}

// all substrings O(n^2)
vector<string> all_substrings(const string &s) {
    vector<string> res;
    int n = s.size();
    for (int i = 0; i < n; i++)
        for (int len = 1; i + len <= n; len++)
            res.push_back(s.substr(i, len));
    return res;
}

/* =====================
   STRING MATCHING ALGORITHMS
   ===================== */

// -------- KMP --------

vector<int> lps_array(const string &p) {
    int m = p.size();
    vector<int> lps(m, 0);
    for (int i = 1, len = 0; i < m; ) {
        if (p[i] == p[len]) lps[i++] = ++len;
        else if (len) len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}

vector<int> kmp_search(const string &s, const string &p) {
    vector<int> res;
    vector<int> lps = lps_array(p);
    for (int i = 0, j = 0; i < (int)s.size(); ) {
        if (s[i] == p[j]) i++, j++;
        if (j == (int)p.size()) {
            res.push_back(i - j);
            j = lps[j - 1];
        } else if (i < (int)s.size() && s[i] != p[j]) {
            if (j) j = lps[j - 1];
            else i++;
        }
    }
    return res;
}

// -------- Z Algorithm --------

vector<int> z_array(const string &s) {
    int n = s.size();
    vector<int> z(n, 0);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

// -------- Rolling Hash --------

struct StringHash {
    static const long long mod = 1000000007;
    static const long long base = 91138233;
    vector<long long> h, p;

    StringHash(const string &s) {
        int n = s.size();
        h.assign(n + 1, 0);
        p.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h[i + 1] = (h[i] * base + s[i]) % mod;
            p[i + 1] = (p[i] * base) % mod;
        }
    }

    long long get(int l, int r) {
        long long res = (h[r + 1] - h[l] * p[r - l + 1]) % mod;
        if (res < 0) res += mod;
        return res;
    }
};

/* =====================
   SOLVE
   ===================== */

void solve() {
    // use what you need
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
