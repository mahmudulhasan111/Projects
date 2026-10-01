#include<bits/stdc++.h>
using namespace std;

/*
========================================================
0/1 KNAPSACK
========================================================
*/
// --------------recursion _--------------------

int knapsack(int wt[], int val[], int w, int n)
{
    // Base case:
    // If there are no items left (n == 0)
    // OR the remaining capacity is 0 (w == 0),
    // we cannot take any more items.
    if (n == 0 || w == 0)
        return 0;

    // Check whether the weight of the current item
    // is less than or equal to the available capacity.
    if (wt[n - 1] <= w)
    {
        // We have TWO choices:according choice diagram
        //
        // 1. Take the current item:
        //    - Add its value: val[n - 1]
        //    - Reduce the available capacity:
        //      w - wt[n - 1]
        //    - Move to the next item:
        //      n - 1
        //
        // 2. Don't take the current item:
        //    - Capacity remains w
        //    - Move to the next item: n - 1
        //
        // We choose whichever gives the maximum value.

        return max(
            val[n - 1] + knapsack(wt, val, w - wt[n - 1], n - 1), // Take
            knapsack(wt, val, w, n - 1)                            // Don't take
        );
    }

    // If the current item's weight is greater than
    // the available capacity, we CANNOT take it.
    // So, simply skip this item and check the remaining items.
    else
    {
        return knapsack(wt, val, w, n - 1);
    }
}




// ---------- Memoization ----------
int dp_knap[1005][1005];

int knap(int i,int W,vector<int>&wt,vector<int>&val){
    if(i==0||W==0)return 0;

    if(dp_knap[i][W]!=-1)return dp_knap[i][W];

    if(wt[i-1]<=W){
        return dp_knap[i][W]=max(
            val[i-1]+knap(i-1,W-wt[i-1],wt,val),
            knap(i-1,W,wt,val)
        );
    }
    return dp_knap[i][W]=knap(i-1,W,wt,val);
}

// ---------- Tabulation ----------
int knapTab(vector<int>&wt,vector<int>&val,int W){
    int n=wt.size();
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));

    for(int i=1;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(wt[i-1]<=w){
                dp[i][w]=max(
                    val[i-1]+dp[i-1][w-wt[i-1]],
                    dp[i-1][w]
                );
            }
            else dp[i][w]=dp[i-1][w];
        }
    }
    return dp[n][W];
}

/*======================================================
SUBSET SUM ====> is subset sum S possible in arr



Question: Given একটা sum S, array থেকে কিছু element নিয়ে S বানানো যাবে কি?

এখানে total sum নিয়ে চিন্তা করার দরকার নেই।

চিন্তা
Given S
   ↓
Can I make S using subset?
   ↓
dp[n][S]
   ↓
 YES → true
 NO  → false
Main DP question
dp[n][S]

exp:

vector<int> arr = {2, 3, 7, 8, 10};

cout << subsetSum(arr, 11);
========================================================*/
bool SubsetSum(vector<int>&arr,int s)
{
    int n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(s+1,0));
    for(int i=0;i<n+1;i++) dp[i][0]=1;
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<s+1;j++)
        {
            if(arr[i-1]<=j)
            dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][s];
  
}







/*
========================================================
EQUAL SUM PARTITION====> is half(sum) possible??


Question: Array-কে দুইটা subset-এ ভাগ করা যাবে কি, যেন দুইটার sum equal হয়?

চিন্তা
Total Sum
   ↓
Odd?
 ├── Yes → false
 └── No
      ↓
   target = sum / 2
      ↓
Can I make target using subset?
      ↓
    YES → true
    NO  → false
Formula
s1 + s2 = sum

Equal হলে:
s1 = s2

তাই:
s1 = sum / 2
Main DP question
dp[n][sum/2 or s1]

অর্থাৎ:

পুরো array থেকে sum/2 or s1 বানানো সম্ভব?
========================================================
*/

bool equalPartition(vector<int>&arr){
    int n=arr.size();
    int sum=accumulate(arr.begin(),arr.end(),0);
    if(sum%2!=0)return false;

    int s1=sum/2;
    vector<vector<int>>dp(n+1,vector<int>(s1+1,0));

    for(int i=0;i<=n;i++)dp[i][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=s1;j++){
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][s1];
}


/*
========================================================
COUNT SUBSET SUM ===> how many subset sum possible

Question: Given S, কয়টা different subset আছে যাদের sum S?

এখানে bool DP আর হবে না।

কারণ আমাদের শুধু:

possible / impossible

জানতে হবে না।

আমাদের জানতে হবে:

কয়টা way?
চিন্তা
Given S
   ↓
How many subsets can make S?
   ↓
dp[n][S]
   ↓
     count
DP meaning
dp[i][j]

মানে:

প্রথম iটা element ব্যবহার করে sum j বানানোর কয়টা উপায় আছে?
so, 

dp[i][j]
=
dp[i-1][j]
+
dp[i-1][j-arr[i-1]]
========================================================
*/

int countSubsetSum(vector<int>&arr,int target){
    int n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(target+1,0));

    for(int i=0;i<=n;i++)dp[i][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=target;j++){
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][target];
}


/*
========================================================
MINIMUM SUBSET SUM DIFFERENCE--- abs(sum1-sum2)===>min

formula :
diff= s2 - s1
    = (sum - s1) - s1
    = sum - 2*s1


পুরো algorithm এক লাইনে

তোমার code-এর পুরো চিন্তাটা হলো:

Find all possible subset sums
                       ↓
    ┌──────────────┐
    │ DP[n][s1]    │
    └──────────────┘
                       ↓
     only check s1 ≤ total_sum/2
                       ↓
      Difference = sum - 2*s1
                       ↓
      minimum one
========================================================
*/

int minSubsetDiff(vector<int>&arr){
    int n=arr.size();
    int sum=accumulate(arr.begin(),arr.end(),0);

    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));

    for(int i=0;i<=n;i++)dp[i][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j)
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    int ans=INT_MAX;
    for(int s1=0;s1<=sum/2;s1++){
        if(dp[n][s1])
            ans=min(ans,sum-2*s1);
    }
    return ans;
}


/*
========================================================
COUNT PARTITIONS WITH GIVEN DIFFERENCE
==>Array-কে দুইটা subset-এ ভাগ করো যেন তাদের difference diff হয়। কয়ভাবে করা যায়?


1. Formula

S1 + S2 = sum
S1 - S2 = diff

দুই equation যোগ করি:
=>(S1 + S2) + (S1 - S2)
= sum + diff

=>2S1 = sum + diff

S1 = (sum + diff) / 2

এইটাই main formula।

তোমার code:

int s1 = (diff + sum) / 2;

একদম এই formula-টাই implement করছে।
      Count Partitions With Given Difference
                    ↓
      Mathematical Formula
                    ↓
       S1 = (sum + diff)/2
                    ↓
       Count Subset Sum
                    ↓
     countSubsetSum(arr, S1)
========================================================
*/

int countPartitions(vector<int>&arr,int diff){
    int n=arr.size();
    int sum=accumulate(arr.begin(),arr.end(),0);

    if((diff+sum)%2!=0)return 0;

    int s1=(diff+sum)/2;
    return countSubsetSum(arr,s1);
}


/*
========================================================
TARGET SUM (+ / -)
=> Array-এর প্রতিটা element-এর সামনে + অথবা - বসিয়ে target বানাতে হবে। কয়ভাবে করা যায়?

1. Formula

ধরি:

S1 = যেসব element-এর সামনে + আছে
S2 = যেসব element-এর সামনে - আছে

তাহলে:

S1 + S2 = sum
S1 - S2 = target

দুই equation যোগ করি:

=> (S1 + S2) + (S1 - S2)
=> sum + target

তাহলে:

=> 2S1 = sum + target

সুতরাং:

S1 = (sum + target) / 2

এইটাই main formula।

তোমার code:

int s1 = (sum + target) / 2;

একদম এই formula-টাই implement করছে।

এরপর problemটা হয়ে যায়:

S1 sum-এর কতগুলো subset আছে?


summary:

অর্থাৎ Count Subset Sum।
        ↓
S1 + S2 = sum
S1 - S2 = target
        ↓
2S1 = sum + target
        ↓
S1 = (sum + target) / 2
        ↓
COUNT SUBSET SUM
        ↓
countSubsetSum(arr, S1)
========================================================
*/

long long targetSumWays(vector<int>&arr,int target){
    int n=arr.size();
    int sum=accumulate(arr.begin(),arr.end(),0);

    if(abs(target)>sum)return 0;
    if((sum+target)%2!=0)return 0;

    int s1=(sum+target)/2;

    return countSubsetSum(arr,s1);

}


//https://chatgpt.com/c/6a7c1cdf-ec54-83ee-bc90-f70fc4b8d9ab
