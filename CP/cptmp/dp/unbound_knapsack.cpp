 f #include<bits/stdc++.h>
using namespace std;

/*
========================================
UNBOUNDED KNAPSACK FAMILY TEMPLATE
========================================
//--------------------------------------
/*1.
UNBOUNDED KNAPSACK (MAX PROFIT)

=> প্রতিটা item-এর weight এবং value দেওয়া আছে। Maximum capacity W-এর মধ্যে সর্বোচ্চ profit কত পাওয়া যাবে? এখানে একই item একাধিকবার নেওয়া যায়।

1. Formula

ধরি:

wt[i]  = current item-এর weight
val[i] = current item-এর value

প্রতিটা item-এর জন্য দুইটা choice:

1. Item নেব না
2. Item নেব

Item না নিলে:

dp[i-1][j]

কারণ আগের i-1টা item দিয়েই capacity j solve করব।

Item নিলে:

val[i-1] + dp[i][j-wt[i-1]]

এখানে important হলো:

dp[i][...]

i-1 না হয়ে i হয়েছে।

কারণ একই item আবার নেওয়া যাবে।

তাই:

=> dp[i][j]
= max(
    dp[i-1][j],
    val[i-1] + dp[i][j-wt[i-1]]
  )

এইটাই main formula।

তোমার code:

dp[i][j]=max(
    dp[i-1][j],                    // skip item
    val[i-1]+dp[i][j-wt[i-1]]      // take item again
);

একদম এই formula-টাই implement করছে।

Concept Flow
Unbounded Knapsack
        ↓
প্রতিটা item-এর 2 choice
        ↓
Skip / Take
        ↓
Skip → dp[i-1][j]
        ↓
Take → val[i-1] + dp[i][j-wt[i-1]]
        ↓
Same item আবার নেওয়া যাবে
        ↓
তাই Take-এর ক্ষেত্রে dp[i][...]
        ↓
max(Skip, Take)
        ↓
dp[n][W]
        ↓
Maximum Profit
সবচেয়ে important difference
0/1 Knapsack:

Take → val[i-1] + dp[i-1][j-wt[i-1]]
                              ↑
                         item আর নেওয়া যাবে না


Unbounded Knapsack:

Take → val[i-1] + dp[i][j-wt[i-1]]
                         ↑
                    item আবার নেওয়া যাবে

Shortcut:
dp[i-1] → 0/1 Knapsack
dp[i] → Unbounded Knapsack
*/
//--------------------------------------
int unboundedKnapsack(vector<int>&val,vector<int>&wt,int W){

    int n=wt.size();
    vector<vector<int>>dp(n+1,vector<int>(W+1,0));

    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){

            if(wt[i-1]<=j)
                dp[i][j]=max(
                    dp[i-1][j],              // skip item
                    val[i-1]+dp[i][j-wt[i-1]] // take item again
                );
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][W];
}


//recursion version
int unboundedKnapsack(vector<int>& val, vector<int>& wt, int W)
{
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

    function<int(int, int)> f = [&](int i, int W) -> int
    {
        if(i == 0 || W == 0)
            return 0;

        if(dp[i][W] != -1)
            return dp[i][W];

        if(wt[i-1] <= W)
        {
            return dp[i][W] = max(
                f(i-1, W),                    // skip
                val[i-1] + f(i, W-wt[i-1])    // take again
            );
        }
        else
        {
            return dp[i][W] = f(i-1, W);
        }
    };

    return f(n, W);
}

//--------------------------------------
/* 2. Rod Cutting (Max Profit)
  ROD CUTTING (MAX PROFIT)

=> Length n-এর একটা rod আছে। প্রতিটি length-এর piece-এর price দেওয়া আছে। Rod কেটে এমনভাবে maximum profit বের করতে হবে। একই length-এর piece একাধিকবার নেওয়া যায়।

1. Formula

ধরি:

i = current rod piece-এর length

price[i-1] = সেই length-এর price

j = current rod-এর available length

প্রতিটা piece-এর জন্য দুইটা choice:

1. Piece নেব না / এই length ব্যবহার করব না
2. Piece কাটব

Skip করলে:

dp[i-1][j]

কারণ current length i ব্যবহার করছি না।

Piece কাটলে:

price[i-1] + dp[i][j-i]

এখানে dp[i][j-i] কেন?

কারণ একই length-এর piece আবারও নেওয়া যাবে।

তাই:

=> dp[i][j]
= max(
    price[i-1] + dp[i][j-i],
    dp[i-1][j]
  )

এইটাই main formula।

তোমার code:

if(i<=j)
    dp[i][j]=max(
        price[i-1]+dp[i][j-i], // cut rod
        dp[i-1][j]             // skip
    );
else
    dp[i][j]=dp[i-1][j];

একদম এই formula-টাই implement করছে।
Example

ধরি:

price = {1, 5, 8, 9}
total length n = 4
এর মানে:

Length 1 → price 1
Length 2 → price 5
Length 3 → price 8
Length 4 → price 9

Rod-এর total length:

n = 4

*/
// here len is n but in other problem len can be given separately.

int rodCutting(vector<int>&price){

    int n=price.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){

            if(i<=j)
                dp[i][j]=max(
                    price[i-1]+dp[i][j-i], // cut rod
                    dp[i-1][j]             // skip
                );
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][n];
}



//--------------------------------------
/* 3. Coin Change (Number of ways)
কিছু coin দেওয়া আছে এবং একটা amount দেওয়া আছে। Coin ব্যবহার করে amount বানানোর মোট কয়টা উপায় আছে?

এখানে একই coin একাধিকবার ব্যবহার করা যায় এবং coin-এর order আলাদা way হিসেবে ধরা হবে না।

Example
coins = {1, 2, 5}
amount = 5

Possible ways:
5
2 + 2 + 1
2 + 1 + 1 + 1
1 + 1 + 1 + 1 + 1

তাই answer:
4




Coin Change
     ↓
প্রতিটা coin-এর 2 choice
     ↓
Take / Skip
     ↓
Skip → dp[i-1][j]
     ↓
Take → dp[i][j-coin]
     ↓
Same coin আবার নেওয়া যাবে
     ↓
dp[i][j] = Take + Skip
     ↓
dp[n][amount]
     ↓
Total Number of Ways
*/
//--------------------------------------
long long coinChangeWays(vector<int>&coins,int amount){

    int n=coins.size();
    vector<vector<long long>>dp(n+1,vector<long long>(amount+1,0));

    for(int i=0;i<=n;i++)
        dp[i][0]=1;   // amount 0 বানানোর 1 way

    for(int i=1;i<=n;i++){
        for(int j=0;j<=amount;j++){

            if(coins[i-1]<=j)
                dp[i][j]=
                    dp[i][j-coins[i-1]] +   // take coin
                    dp[i-1][j];             // skip coin
            else
                dp[i][j]=dp[i-1][j];          //skip coin
        }
    }

    return dp[n][amount];
}



//--------------------------------------
/* 4. Coin Change (Minimum num of coins needed to make the amount)
=> কিছু coin দেওয়া আছে এবং একটা amount দেওয়া আছে। amount বানাতে minimum কয়টা coin লাগবে সেটা বের করতে হবে।

এখানে একই coin একাধিকবার ব্যবহার করা যায়।

Example
coins = {1, 2, 5}
amount = 11

Possible:

5 + 5 + 1 = 11 → 3 coins
2 + 2 + 2 + 2 + 2 + 1 = 11 → 6 coins
1 + 1 + ... + 1 = 11 → 11 coins

তাই:

Answer = 3
1. Formula

ধরি:

i = current coin
j = current amount

প্রতিটা coin-এর দুইটা choice:

1. Coin নেব
2. Coin নেব না

Coin নিলে:

1 + dp[i][j-coins[i-1]]

এখানে 1 হচ্ছে current coin-এর জন্য।

আর:

dp[i][j-coins[i-1]]

মানে remaining amount বানাতে minimum কয়টা coin লাগবে।

dp[i] ব্যবহার করছি কারণ একই coin আবার নেওয়া যাবে।

Coin না নিলে:

dp[i-1][j]

তাই:

=> dp[i][j]
 = min(
     1 + dp[i][j-coins[i-1]],
     dp[i-1][j]
   )

এইটাই main formula।

তোমার code: 

dp[i][j]=min(
    1+dp[i][j-coins[i-1]], // take coin
    dp[i-1][j]              // skip coin
);

একদম এই formula-টাই implement করছে।

2. dp[i][0] = 0 কেন?
for(int i=0;i<=n;i++)
    dp[i][0]=0;

Amount 0 বানাতে কোনো coin লাগবে না।

amount = 0
↓
minimum coins = 0

তাই:

dp[i][0] = 0
3. INT_MAX-1 কেন?
vector<vector<int>> dp(
    n+1,
    vector<int>(amount+1, INT_MAX-1)
);

যদি কোনো amount বানানো না যায়, তখন আমরা তাকে infinity হিসেবে রাখছি।

যেমন:

coins = {2}
amount = 3

3 বানানো সম্ভব না।

তাই:

dp[1][3] = INT_MAX-1

INT_MAX সরাসরি না নেওয়ার একটা কারণ হলো:

1 + INT_MAX

করলে integer overflow হতে পারে।

তাই:

INT_MAX - 1

নিরাপদভাবে infinity হিসেবে ব্যবহার করা হয়েছে।

4. প্রথম coin-এর initialization
for(int j=1;j<=amount;j++){
    if(j%coins[0]==0)
        dp[1][j]=j/coins[0];
}

কারণ শুধু প্রথম coin ব্যবহার করে amount বানাতে হবে।

ধরি:

coins[0] = 2

তাহলে:

amount  2 → 1 coin
amount  4 → 2 coins
amount  6 → 3 coins
amount  8 → 4 coins

Formula:

j / coins[0]

কিন্তু যদি:

j % coins[0] != 0

হয়, তাহলে প্রথম coin দিয়ে amount বানানো সম্ভব না।











Coin Change
     ↓
Minimum number of coins
     ↓
প্রতিটা coin-এর 2 choice
     ↓
Take / Skip
     ↓
Take → 1 + dp[i][j-coin]
     ↓
Skip → dp[i-1][j]
     ↓
min(Take, Skip)
     ↓
dp[n][amount]
     ↓
Minimum Number of Coins
*/--------------------------------------
int minCoins(vector<int>&coins,int amount){

    int n=coins.size();
    vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX-1));

    for(int i=0;i<=n;i++)
        dp[i][0]=0;

    for(int j=1;j<=amount;j++){   
        if(j%coins[0]==0)
            dp[1][j]=j/coins[0];
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=amount;j++){

            if(coins[i-1]<=j)
                dp[i][j]=min(
                    1+dp[i][j-coins[i-1]],
                    dp[i-1][j]
                );
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][amount]==INT_MAX-1?-1:dp[n][amount];  //or >amount
}
