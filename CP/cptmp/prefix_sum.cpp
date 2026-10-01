#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vll vector<long long>
#define forn(i,a,b) for(int i=a;i<b;i++)

/*
    PREFIX SUM (Hybrid style used in CP)

    - Input array `a`        : 0-based indexing
    - Prefix array `pref:
    - pref[0] is a DUMMY (guard value)
    - Useful prefix indices : 1 ... n

    Definition:
        pref[i] = sum of a[0 ... i-1]

    Range sum (0-based):
        sum(l, r) = pref[r + 1] - pref[l]
*/

vector<long long> build_prefix(const vector<long long>& a) {
    int n = a.size();
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    return pref;
}
//l,r: 0 based.
long long range_sum(const vector<long long>& pref, int l, int r) {
    return pref[r + 1] - pref[l];
}


// ============================
// Function: compute_prefix
// ============================
// Input: 0-based array `v[0..n-1]`
// Output: 0-based prefix sum array `pre[0..n-1]`
// pre[i] = sum of v[0] to v[i]
vll compute_prefix(const vi &v){
    int n = v.size();           
    vll pre(n);                   
    if(n == 0) return pre;       

    pre[0] = v[0];               
    for(int i=1;i<n;i++){
        pre[i] = pre[i-1] + v[i];
    }
    return pre;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;                     // number of test cases
    while(t--){
        int n;
        cin >> n;

        vi arr(n);
        forn(i,0,n) cin >> arr[i];    // 0-based input

        vll pre = compute_prefix(arr); // compute prefix sum

        cout << "Prefix sum array: ";
        forn(i,0,n) cout << pre[i] << " "; // print 0-based prefix
        cout << endl;
    }
}
