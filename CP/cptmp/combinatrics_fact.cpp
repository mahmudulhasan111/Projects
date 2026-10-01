/* =====================================================
   COMBINATORICS 
   ===================================================== */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

/* -------------------- CONSTANTS -------------------- */
const ll MOD = 1e9 + 7;
const int MAXN = 1e6;

/* -------------------- VECTORS -------------------- */
vector<ll> fact(MAXN + 1), invfact(MAXN + 1);

/* -------------------- FAST POWER -------------------- */
// calculates (a^b) % MOD
ll binpow(ll a, ll b)
{
    ll res = 1;
    a %= MOD;
    while(b > 0)
    {
        if(b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

/* -------------------- MODULAR INVERSE -------------------- */
// MOD must be prime
ll modinv(ll a)
{
    return binpow(a, MOD - 2);
}

/* -------------------- PRECOMPUTE FACT & INVFACT -------------------- */
void init_fact()
{
    fact[0] = 1;
    for(int i = 1; i <= MAXN; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    invfact[MAXN] = modinv(fact[MAXN]);
    for(int i = MAXN - 1; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
}

/* -------------------- NCR -------------------- */
// nCr % MOD
ll nCr(ll n, ll r)
{
    if(r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}

/* -------------------- NPR -------------------- */
// nPr % MOD
ll nPr(ll n, ll r)
{
    if(r < 0 || r > n) return 0;
    return fact[n] * invfact[n - r] % MOD;
}

/* -------------------- SIMPLE NCR (NO MOD) -------------------- */
// works for small n
ll nCr_simple(ll n, ll r)
{
    if(r > n - r) r = n - r;
    ll ans = 1;
    for(ll i = 0; i < r; i++)
        ans = ans * (n - i) / (i + 1);
    return ans;
}

/* -------------------- STARS AND BARS or (ball and box)  -------------------- */
// ways to distribute k identical items into n boxes
// stars = k, bars = n - 1
// = C(stars + bars, stars) = C(stars + bars, bars)
ll stars_and_bars(ll k, ll n)
{
    return nCr(k + (n- 1), k);
}




/*-------------------------------------simple calc.---------------------------

*        COMBINATORICS FULL NOTE (C++)
*        n!, nPr, nCr (Simple Loop Based)
*        Use for small n (≤ 60)

#include <bits/stdc++.h>
using namespace std;

------------------------------------------------
  FACTORIAL
  n! = 1 * 2 * 3 * ... * n
-----------------------------------------------
long long factorial(int n)
{
    long long res = 1;
    for(int i = 1; i <= n; i++)
         res = (res * i) % MOD;
    return res;
}
------------------------------------------------
  PERMUTATION (nPr)
  Formula:
      nPr = n! / (n - r)!
  Optimized:
      n * (n-1) * ... * (n-r+1)
------------------------------------------------


long long nPr(int n, int r)
{
    if(r > n) return 0;

    long long res = 1;
    for(int i = 0; i < r; i++)
       res = (res*(n - i))%MOD;
        

    return res;
}



------------------------------------------------
  COMBINATION (nCr)
  Formula:
      nCr = n! / (r! * (n-r)!)

  Optimized formula:
      nCr = Π (n-r+i)/i   , i = 1 to r

  Trick:
      nCr = nC(n-r)  (symmetry)
------------------------------------------------
long long nCr(int n, int r)
{
    if(r > n) return 0;

    
    if(r > n - r) r = n - r;

    long long res = 1;
    for(int i = 1; i <= r; i++)
    {
        res = res * (n - r + i);
        res = res / i;
    }
    return res;
}

------------------------------------------------
  RELATION
      nPr = nCr * r!
------------------------------------------------
long long nPr_using_nCr(int n, int r)
{
    return nCr(n, r) * factorial(r);
}

------------------------------------------------
  BASIC IDENTITIES (NOT CODE)
  
  1) nC0 = nCn = 1
  2) nP0 = 1
  3) nCr = nC(n-r)
  4) nPr = n * (n-1) * ... * (n-r+1)
------------------------------------------------

------------------------------------------------
  LIMITATIONS
  - long long overflows for n > ~20 (factorial)
  - nCr safe roughly up to n ≤ 60
  - NOT for modulo problems
------------------------------------------------

int main()
{
    int n = 5, r = 2;

    cout << "Factorial of " << n << " = " << factorial(n) << '\n';
    cout << "nPr = " << nPr(n, r) << '\n';
    cout << "nCr = " << nCr(n, r) << '\n';
    cout << "nPr (using nCr) = " << nPr_using_nCr(n, r) << '\n';

    return 0;
}



*/








/* -------------------- MAIN -------------------- */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    init_fact();

    // demo
    cout << "nCr(5,2) = " << nCr(5, 2) << "\n";      // 10
    cout << "nPr(5,2) = " << nPr(5, 2) << "\n";      // 20
    cout << "2^10 % MOD = " << binpow(2, 10) << "\n"; // 1024

    return 0;
}

