#include <bits/stdc++.h>
using namespace std;

/*
LCS LENGTH (memorization)

LCS (LONGEST COMMON SUBSEQUENCE)

=> দুইটা String-এর মধ্যে সবচেয়ে বড় common subsequence বের করতে হবে।

1. Base Case

ধরি:

X এর length = m
Y এর length = n

যদি যেকোনো একটা String শেষ হয়ে যায়:

m = 0 অথবা n = 0

তাহলে আর কোনো common character পাওয়া সম্ভব না।

সুতরাং:

if (m == 0 || n == 0)
    return 0;
2. যদি শেষের দুইটা character একই হয়

ধরি:

X[m-1] == Y[n-1]

তাহলে এই character-টা অবশ্যই LCS-এর মধ্যে নিতে পারি।

তাই:

LCS(X, Y, m, n)
= 1 + LCS(X, Y, m-1, n-1)

Code:

if (X[m - 1] == Y[n - 1])
{
    return 1 + LCS(X, Y, m - 1, n - 1);
}

অর্থাৎ:

Same character
     ↓
Character টা নাও
     ↓
+ 1
     ↓
দুই String-এর length 1 করে কমাও
3. যদি শেষের দুইটা character আলাদা হয়

যদি:

X[m-1] != Y[n-1]

তাহলে দুটো possibility আছে।

Possibility 1

X-এর শেষ character বাদ দিই:

LCS(X, Y, m-1, n)
Possibility 2

Y-এর শেষ character বাদ দিই:

LCS(X, Y, m, n-1)

দুইটার মধ্যে maximum নিতে হবে।

তাই:

else
{
    return max(
        LCS(X, Y, m - 1, n),
        LCS(X, Y, m, n - 1)
    );
}



                 LCS
                  ↓
        দুইটা String দেওয়া
                  ↓
       m == 0 অথবা n == 0 ?
             /          \
           Yes           No
                            ↓                         ↓
         return 0    X[m-1] == Y[n-1] ?
                         /          \
                       Yes           No
                                                    ↓                            ↓
                  1 + LCS(...)      max(...)
                                                    ↓           /       \
                  m-1, n-1     m-1,n       m,n-1



LCS
 ↓
Base Case → m==0 || n==0 → 0
 ↓
Same Character → 1 + LCS(m-1,n-1)
 ↓
Different Character → max(LCS(m-1,n), LCS(m,n-1))

RECURSIVE
*/

int LCS(string X, string Y, int m, int n)
{
    // Base Case
    if (m == 0 || n == 0)
        return 0;

    // Last characters are same
    if (X[m - 1] == Y[n - 1])
    {
        return 1 + LCS(X, Y, m - 1, n - 1);
    }

    // Last characters are different
    else
    {
        return max(
            LCS(X, Y, m - 1, n),
            LCS(X, Y, m, n - 1)
        );
    }
}


//--------------------------------------
// LCS Length using Memoization
//--------------------------------------

int LCS(string X, string Y, int m, int n,
        vector<vector<int>>& dp)
{
    // Base Case
    if (m == 0 || n == 0)
        return 0;

    // Already calculated
    if (dp[m][n] != -1)
        return dp[m][n];

    // Last characters are same
    if (X[m - 1] == Y[n - 1])
    {
        dp[m][n] = 1 + LCS(
            X, Y, m - 1, n - 1, dp
        );
    }

    // Last characters are different
    else
    {
        dp[m][n] = max(
            LCS(X, Y, m - 1, n, dp),
            LCS(X, Y, m, n - 1, dp)
        );
    }

    return dp[m][n];
}





//--------------------------------------
// 1. LCS Length  top down

LCS LENGTH
    ↓
dp[i][j]
    ↓
s1[i-1] == s2[j-1] ?
      /        \
    Yes         No
               ↓                    ↓
1 + diagonal   max(top, left)
     ↓                                      ↓
dp[i-1][j-1]   max(dp[i-1][j],
                    dp[i][j-1])
     ↓
dp[n][m]
     ↓
LCS Length





Main Formula---------------
Same
↓
dp[i][j] = 1 + dp[i-1][j-1]

Different
↓
dp[i][j] = max(dp[i-1][j], dp[i][j-1])

//--------------------------------------


int LCSLength(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}


//--------------------------------------
/* 2. Longest Common Substring
=> দুইটা String-এর মধ্যে সবচেয়ে বড় common continuous অংশ বা Longest Common Substring-এর length বের করতে হবে।

Important:
Subsequence-এ character-এর মাঝে gap থাকতে পারে, কিন্তু Substring-এ characterগুলো continuous হতে হবে।

1. DP State

ধরি:

dp[i][j] = s1-এর প্রথম i টি character
           এবং
           s2-এর প্রথম j টি character-এর শেষ থেকে
           কত length-এর common substring আছে

সহজভাবে:

dp[i][j]

মানে s1[i-1] এবং s2[j-1] দিয়ে শেষ হওয়া common substring-এর length।

তাই:

vector<vector<int>> dp(
    n + 1,
    vector<int>(m + 1, 0)
);
2. Base Case

যদি কোনো String-এর length 0 হয়, তাহলে কোনো common substring থাকতে পারে না।

তাই:

dp[i][0] = 0
dp[0][j] = 0

এই কারণেই DP table শুরুতেই 0 দিয়ে initialize করা হয়েছে।

3. যদি Character একই হয়

যদি:

s1[i - 1] == s2[j - 1]

তাহলে এই দুই character একই substring-এর অংশ হতে পারবে।

তাই আগের diagonal state-এর সাথে 1 যোগ হবে:

dp[i][j]
= 1 + dp[i - 1][j - 1]
Code:

if(s1[i - 1] == s2[j - 1])
    dp[i][j] = 1 + dp[i - 1][j - 1];

অর্থাৎ:

Same Character
      ↓
আগের common substring-এর সাথে
এই character যোগ করি
      ↓
1 + diagonal
      ↓
dp[i-1][j-1]
4. যদি Character আলাদা হয়

যদি:

s1[i - 1] != s2[j - 1]

তাহলে common substring এখান থেকে continue করতে পারবে না।

তাই:

dp[i][j] = 0

Code:

else
    dp[i][j] = 0;

এখানে 0 দেওয়া খুব important।

কারণ Substring অবশ্যই continuous হতে হবে।

5. Answer কেন dp[n][m] নয়?

এখানে একটা গুরুত্বপূর্ণ difference আছে।

LCS-এর ক্ষেত্রে:

answer = dp[n][m]

কিন্তু Longest Common Substring-এর ক্ষেত্রে answer যেকোনো dp[i][j] cell-এর মধ্যে থাকতে পারে।

তাই প্রতিটি cell-এর সাথে ans update করি:

ans = max(ans, dp[i][j]);

অর্থাৎ:

প্রতিটি dp[i][j]
      ↓
ans-এর সাথে compare
      ↓
যেটা সবচেয়ে বড়
      ↓
ans

শেষে:

return ans;


summary:
Main Logic
Same Character
↓
dp[i][j] = 1 + dp[i-1][j-1]
Different Character
↓
dp[i][j] = 0
প্রতিটি cell-এর maximum
↓
ans = max(ans, dp[i][j])
↓
Longest Common Substring Length
LCS বনাম Longest Common Substring

সবচেয়ে important difference:

LCS:
Different
↓
max(top, left)

Substring:
Different
↓
0

কারণ Substring continuous হতে হয়, তাই character mismatch হলেই আগের substring আর continue করা যায় না।

Time Complexity: O(n × m)
Space Complexity: O(n × m)

*/--------------------------------------
int longestCommonSubstring(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();
    int ans = 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;

            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}


//--------------------------------------
// 3. Print One LCS:
      Summary
PRINT ONE LCS
      ↓
Build LCS DP Table
      ↓
Start from dp[n][m]
      ↓
Backtracking
      ↓
Characters same?
    /          \
  Yes           No
           ↓                        ↓
Take character  Compare top & left
          ↓                            ↓
i--, j--      Bigger one → move there
   ↓
Continue until i==0 অথবা j==0
      ↓
Reverse the string
      ↓
Return LCS


Main Logic
-------------------------
Same Character
↓
s += s1[i-1]
↓
i--, j--
Different Character
↓
dp[i-1][j] > dp[i][j-1] ?
       /              \
     Yes               No
            ↓                                    ↓
    i--                 j--
Backtracking-এ character উল্টো order-এ পাওয়া যায়
↓
reverse(s)
↓
Actual LCS
মূল Concept

এখানে DP Table তৈরি করা হচ্ছে answer-এর length জানার জন্য, আর তারপর সেই DP Table-কে backtrack করে actual LCS reconstruct করা হচ্ছে।

Time Complexity: O(n × m)
Space Complexity: O(n × m)
//----------------------------------------------------------------------



string printOneLCS(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();
    string s = "";

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = n, j = m;

    while(i > 0 && j > 0)
    {
        if(s1[i - 1] == s2[j - 1])
        {
            s += s1[i - 1];
            i--;
            j--;
        }
        else
        {
            if(dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    reverse(s.begin(), s.end());

    return s;
}


//--------------------------------------
/* 4. Shortest Common Supersequence Length

=> দুইটা String s1 এবং s2 দেওয়া আছে। এমন একটি shortest string বানাতে হবে যার মধ্যে s1 এবং s2 দুটোই subsequence হিসেবে থাকবে।

Summary
Problem
  ↓
দুইটা String-এর common supersequence বানাতে হবে
  ↓
Shortest length চাই
  ↓
প্রথমে LCS Length বের করি
  ↓
LCS = common characters
  ↓
common characters দুইবার count হয়ে যায়
  ↓
একবার বাদ দিই
  ↓
SCS Length = n + m - LCS
*/--------------------------------------
int SCSLength(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int lcs = dp[n][m];

    return n + m - lcs;
}


//--------------------------------------
/* 5. Print Shortest Common Supersequence
=> দুইটা String s1 এবং s2 দেওয়া আছে। এমন একটি shortest string বানাতে হবে যার মধ্যে s1 এবং s2 দুটোই subsequence হিসেবে থাকবে।

Summary
PRINT SCS
   ↓
Build LCS DP Table
   ↓
Start from dp[n][m]
   ↓
Backtracking
   ↓
Same Character?
   /          \
 Yes           No
    ↓                              ↓
Take once    Compare top & left
  ↓                                   ↓
i--, j--     Bigger direction
                                  ↓
         Corresponding character take
                                  ↓
              Continue
                                    ↓
One string শেষ?
       ↓
Take remaining characters
       ↓
Reverse
       ↓
Shortest Common Supersequence





Main Logic
Same
↓
s += s1[i-1]
↓
i--, j--
Different
↓
dp[i-1][j] > dp[i][j-1] ?
      /              \
    Yes               No
     ↓                 ↓
s += s1[i-1]      s += s2[j-1]
i--                j--
Concept Flow
Two Strings
    ↓
LCS DP
    ↓
LCS tells us which common characters
should be taken together
    ↓
Backtracking
    ↓
Same → take once
Different → take one according to DP
    ↓
Add remaining characters
    ↓
Reverse
    ↓
Print SCS

Time Complexity: O(n × m)
Space Complexity: O(n × m)
*/--------------------------------------
string printSCS(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();
    string s = "";

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = n, j = m;

    while(i > 0 && j > 0)
    {
        if(s1[i - 1] == s2[j - 1])
        {
            s += s1[i - 1];
            i--;
            j--;
        }
        else
        {
            if(dp[i - 1][j] > dp[i][j - 1])
            {
                s += s1[i - 1];
                i--;
            }
            else
            {
                s += s2[j - 1];
                j--;
            }
        }
    }

    while(i > 0)
    {
        s += s1[i - 1];
        i--;
    }

    while(j > 0)
    {
        s += s2[j - 1];
        j--;
    }

    reverse(s.begin(), s.end());

    return s;
}


/*--------------------------------------
// 6. Minimum Insertions + Deletions
=> দুইটা String s1 এবং s2 দেওয়া আছে। s1 থেকে s2 বানাতে minimum কতগুলো insertion এবং deletion operation লাগবে, সেটা বের করতে হবে।

MINIMUM INSERTIONS + DELETIONS
                        ↓
        প্রথমে LCS বের করি
                        ↓
          LCS Length
                               ↓
    ┌─────────┴─────────┐
    ↓                                               ↓
Deletion             Insertion
    ↓                                                 ↓
 n - LCS             m - LCS
    └─────────┬─────────┘
                              ↓
         Total Operations
                              ↓
         (n - LCS) + (m - LCS)
*/--------------------------------------
int minInsertDeleteOperations(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int lcs = dp[n][m];

    return (n - lcs) + (m - lcs); //deletetion+ add
}


//--------------------------------------
/* 7. Longest Palindromic Subsequence
=> একটি String দেওয়া আছে। String-এর মধ্যে এমন একটি subsequence খুঁজতে হবে যেটা সামনে থেকে এবং পিছন থেকে একই, এবং তার length হবে সবচেয়ে বড়।

অর্থাৎ আমাদের Longest Palindromic Subsequence (LPS) বের করতে হবে।

LONGEST PALINDROMIC SUBSEQUENCE
              ↓
    String s
              ↓
  Reverse(s)
              ↓
  String r = reverse(s)
              ↓
   Find LCS(s, r)
              ↓
  LCS(s, reverse(s))
              ↓
      LPS
              ↓
     dp[n][n]
-----------------
Concept Flow
----------------------

Palindrome
    ↓
Original String = Reverse String
    ↓
Common subsequence খুঁজি
    ↓
LCS
    ↓
Longest Palindromic Subsequence
*/--------------------------------------
int longestPalindromicSubsequence(string s)
{
    string r = s;

    reverse(r.begin(), r.end());

    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s[i - 1] == r[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n];
}


//--------------------------------------
// 8. Minimum Deletions to Make Palindrome
    // delete= s.size()-lcs(s,rev(s))
      //lps=lcs(s,rev(s))
//--------------------------------------
int minDeletionsToPalindrome(string s)
{
    int lps = longestPalindromicSubsequence(s);

    return s.size() - lps;
}


//--------------------------------------
/* 9. Longest Repeating Subsequence
=> একটি String দেওয়া আছে। String-এর মধ্যে এমন একটি subsequence খুঁজতে হবে যেটা কমপক্ষে দুইবার পাওয়া যায়, এবং সেই repeating subsequence-এর length সবচেয়ে বড় হতে হবে।

Important: একই character নিজের একই position থেকে দুইবার নেওয়া যাবে না।


Summary
LONGEST REPEATING SUBSEQUENCE
             ↓
       Same String-এর
       দুইটা copy নাও
             ↓
        LCS বের করো
             ↓
Same Character + Different Index
             ↓
      Valid Match
             ↓
    Longest Repeating
       Subsequence

Main Logic
------------------
s[i-1] == s[j-1]
        +
      i != j
        ↓
dp[i][j] = 1 + dp[i-1][j-1]
Different Character
        OR
      i == j
        ↓
dp[i][j] = max(
    dp[i-1][j],
    dp[i][j-1]
)


-----------------
সবচেয়ে গুরুত্বপূর্ণ অংশ
------------------
LCS(s, s)
   ↓
কিন্তু একই index match করা যাবে না
   ↓
i != j
   ↓
Longest Repeating Subsequence


------------------------------
Concept Flow
---------------------------------
Problem
   ↓
একই String-এর মধ্যে সবচেয়ে বড়
repeating subsequence চাই
   ↓
String-এর দুইটা copy
   ↓
LCS
   ↓
i != j condition
   ↓
Longest Repeating Subsequence
   ↓
dp[n][n]
*/--------------------------------------
int longestRepeatingSubsequence(string &s)
{
    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s[i - 1] == s[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n];
}


//--------------------------------------
/* 10. Sequence Pattern Matching
check if s1 is subsequence of s2:

SEQUENCE PATTERN MATCHING
          ↓
s1 কি s2-এর subsequence?
          ↓
   LCS বের করি
          ↓
LCS Length == s1 Length?
       /          \
     Yes           No
            ↓                               ↓
    TRUE          FALSE
*/--------------------------------------
bool sequencePatternMatching(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return n == dp[n][m];
}

 //returnmin(m,n) == dp[n][m] when told if any of this is subsequence of other 


//--------------------------------------
// MAIN
//--------------------------------------
int main()
{
    string s1, s2;

    cin >> s1 >> s2;

    cout << "LCS length: "
         << LCSLength(s1, s2) << "\n";

    cout << "Longest Common Substring: "
         << longestCommonSubstring(s1, s2) << "\n";

    cout << "One LCS: "
         << printOneLCS(s1, s2) << "\n";

    cout << "SCS length: "
         << SCSLength(s1, s2) << "\n";

    cout << "SCS string: "
         << printSCS(s1, s2) << "\n";

    cout << "Min insertions + deletions: "
         << minInsertDeleteOperations(s1, s2) << "\n";

    cout << "LPS of s1: "
         << longestPalindromicSubsequence(s1) << "\n";

    cout << "Min deletions to palindrome: "
         << minDeletionsToPalindrome(s1) << "\n";

    cout << "Longest Repeating Subsequence of s1: "
         << longestRepeatingSubsequence(s1) << "\n";

    cout << "Sequence Pattern Matching (s1 in s2): "
         << sequencePatternMatching(s1, s2) << "\n";

    return 0;
}

/*
================ LCS PATTERN IDENTIFICATION TRICKS =================

1. Two strings + subsequence word
   → Usually LCS problem.

2. Convert string A → B using insert/delete
   → LCS = common part
   deletions = n - LCS
   insertions = m - LCS

3. Palindrome with subsequence
   → LPS = LCS(s , reverse(s))

4. Shortest Common Supersequence
   → SCS length = n + m - LCS

5. Check if s1 is subsequence of s2
   → LCS(s1,s2) == length(s1)

6. Repeating subsequence in same string
   → LCS(s,s) with condition i != j

7. Keyword difference
   substring → Longest Common Substring
   subsequence → LCS

=============================================================
*/



//https://chatgpt.com/c/6a7c9271-020c-83e8-859e-b5c690c1e096
