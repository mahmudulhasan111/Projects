#include <bits/stdc++.h>
using namespace std;

// 1. Integer: Ascending order — ছোট থেকে বড়
// Built-in equivalent: sort(v.begin(), v.end())
bool ascending(int a, int b) {
    return a < b;
}

// 2. Integer: Descending order — বড় থেকে ছোট
// Built-in equivalent: sort(v.begin(), v.end(), greater<int>())
bool descending(int a, int b) {
    return a > b;
}

// 3. Pair: First element ascending — শুধু first অনুযায়ী সাজাবে
// Built-in equivalent: custom comparator; pair-এর default sort নয়
bool firstAscending(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

// 4. Pair: Second element ascending — শুধু second অনুযায়ী সাজাবে
// Built-in equivalent: custom comparator
bool secondAscending(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

// 5. Pair: First ascending, tie হলে second ascending
// Built-in equivalent: default pair sort-এর মতো
// Default pair sort: first ascending, first সমান হলে second ascending
bool pairCompareAsc(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

// 6. Pair: First ascending, tie হলে second descending
// First সমান হলে second-এর বড় মান আগে থাকবে
// Built-in equivalent: সরাসরি এই নিয়মের কোনো সাধারণ comparator নেই
bool pairCompareDesc(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

// 7. String: Alphabetical order — অভিধানক্রমে
// Built-in equivalent: sort(words.begin(), words.end())
bool alphabetical(string a, string b) {
    return a < b;
}

// 8. String: Shorter first — ছোট দৈর্ঘ্যের string আগে
// একই দৈর্ঘ্য হলে তাদের ক্রম নির্দিষ্ট নয়
bool shorterFirst(string a, string b) {
    return a.size() < b.size();
}

// 9. Interval: Ending point ascending — যার end ছোট, সেটি আগে
// End সমান হলে starting point ছোটটি আগে  -built in sort
// Interval = {start, end}
bool endAscending(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}


// Interval: Ending point descending — end বড় হলে আগে
// End সমান হলে starting point ছোটটি আগে
bool endDescending(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    return a.first < b.first;
}
int main() {
    // Example 1: Integer vector
    vector<int> v = {4, 2, 5, 1, 3};

    sort(v.begin(), v.end(), ascending);  // Ascending
    for (int x : v) cout << x << ' ';
    cout << endl;

    sort(v.begin(), v.end(), descending); // Descending
    for (int x : v) cout << x << ' ';
    cout << endl;

    // Example 2: Pair vector
    vector<pair<int, int>> p = {
        {2, 4}, {1, 3}, {2, 3}, {1, 8}
    };

    sort(p.begin(), p.end(), pairCompareAsc); // First ASC, second ASC
    for (auto x : p) {
        cout << x.first << ' ' << x.second << endl;
    }

    sort(p.begin(), p.end(), pairCompareDesc); // First ASC, second DESC
    for (auto x : p) {
        cout << x.first << ' ' << x.second << endl;
    }

    // Example 3: String vector
    vector<string> words = {"pear", "a", "banana", "fig", "kiwi"};

    sort(words.begin(), words.end(), alphabetical); // Alphabetical
    for (string s : words) cout << s << ' ';
    cout << endl;

    sort(words.begin(), words.end(), shorterFirst); // Shorter first
    for (string s : words) cout << s << ' ';
    cout << endl;

    // Example 4: Interval vector
    vector<pair<int, int>> intervals = {
        {1, 5}, {2, 3}, {4, 7}, {2, 6}
    };

    sort(intervals.begin(), intervals.end(), endAscending);
    for (auto x : intervals) {
        cout << '[' << x.first << ',' << x.second << "] ";
    }
    cout << endl;

    return 0;
}
