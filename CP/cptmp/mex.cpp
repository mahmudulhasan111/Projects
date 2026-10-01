#include <bits/stdc++.h>
using namespace std;

/*---------------------------------------------------------
  METHOD 1: MEX using Frequency Array
  - Time:  O(n)
  - Space: O(n)
  - Fastest method
  - Ignores values > n (safe for MEX)
----------------------------------------------------------*/
int mex_freq(const vector<int>& a)
{
    int n = a.size();
    vector<int> freq(n + 1, 0);

    for(int x : a){
        if(x >= 0 && x <= n)
            freq[x]++;
    }

    int mex = 0;
    while(freq[mex]) mex++;
    return mex;
}

/*---------------------------------------------------------
  METHOD 2: MEX using Set
  - Time:  O(n log n)
  - Space: O(n)
  - Removes duplicates automatically
  - Easy to understand but slower
----------------------------------------------------------*/
int mex_set(const vector<int>& a)
{
    set<int> st;
    for(int x : a){
        if(x >= 0)
            st.insert(x);
    }

    int mex = 0;
    while(st.count(mex))
        mex++;

    return mex;
}

/*---------------------------------------------------------
  METHOD 3: MEX using Sorting
  - Time:  O(n log n)
  - Space: O(1) extra (if sorted in-place)
  - No extra data structure needed
----------------------------------------------------------*/
int mex_sort(vector<int> a)
{
    sort(a.begin(), a.end());

    int mex = 0;
    for(int x : a){
        if(x == mex)
            mex++;
        else if(x > mex)
            break;
    }
    return mex;
}

/*---------------------------------------------------------
  DRIVER CODE (example usage)
----------------------------------------------------------*/
int main()
{
    vector<int> v = {0, 1, 2, 4, 7, 7};

    cout << "MEX using freq  : " << mex_freq(v) << '\n';
    cout << "MEX using set   : " << mex_set(v)  << '\n';
    cout << "MEX using sort  : " << mex_sort(v) << '\n';

    return 0;
}
