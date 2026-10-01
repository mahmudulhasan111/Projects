/*
====================================================
        COMPETITIVE PROGRAMMING FORMULA NOTE
====================================================

-----------------------------
1) BASIC SUMMATION FORMULAS
-----------------------------

Sum of first n natural numbers:
∑ i = n(n+1)/2

Sum of squares:
∑ i^2 = n(n+1)(2n+1)/6

Sum of cubes:
∑ i^3 = [n(n+1)/2]^2

Sum of first n even numbers:
2 + 4 + ... + 2n = n(n+1)

Sum of first n odd numbers:
1 + 3 + ... + (2n-1) = n^2

General odd series:
∑ (2i-1) = n^2

k(2k−1) series:
∑ k(2k−1) = n(n+1)(4n−1)/6


-----------------------------
2) AP (Arithmetic Progression)
-----------------------------

nth term:
a_n = a + (n−1)d

Sum of n terms:
S_n = n/2 [2a + (n−1)d]

Find n:
n = (last − first)/d + 1


-----------------------------
3) GP (Geometric Progression)
-----------------------------

nth term:
a_n = a * r^(n−1)

Sum (r ≠ 1):
S_n = a (r^n − 1)/(r − 1)

Infinite GP (|r| < 1):
S = a / (1 − r)


-----------------------------
4) NUMBER THEORY ESSENTIALS
-----------------------------

GCD:
gcd(a,b) = gcd(b, a%b)

LCM:
lcm(a,b) = (a/gcd(a,b)) * b

Prime check (sqrt):
O(√n)

Number of divisors:
If n = p1^a * p2^b * ...
divisors = (a+1)(b+1)...

Sum of divisors:
σ(n) = (p1^(a+1)-1)/(p1-1) * ...

Euler Totient:
φ(n) = n * Π(1 − 1/p)

Modular inverse (prime mod):
inv(a) = a^(mod−2) % mod

(a^b mod m):
Binary exponentiation O(log b)


-----------------------------
5) MODULAR ARITHMETIC
-----------------------------

(a + b) % m
(a − b + m) % m
(a * b) % m

(a / b) % m = a * modInverse(b) % m


-----------------------------
6) COMBINATORICS
-----------------------------

nCr:
n! / (r!(n−r)!)

Pascal:
C(n,r) = C(n−1,r) + C(n−1,r−1)

Sum of nCr:
∑ C(n,r) = 2^n

Stars & Bars:
Ways = C(n+k−1, k−1)


-----------------------------
7) BIT MANIPULATION
-----------------------------

Check ith bit:
(x >> i) & 1

Set ith bit:
x | (1 << i)

Unset ith bit:
x & ~(1 << i)

Toggle ith bit:
x ^ (1 << i)

Count bits:
__builtin_popcount(x)


-----------------------------
8) PREFIX SUM
-----------------------------

pref[i] = a[0] + ... + a[i−1]

Range sum [l,r]:
pref[r+1] − pref[l]


-----------------------------
9) TWO POINTER / SLIDING WINDOW
-----------------------------

Used for:
• subarray sum
• longest substring
• fixed / variable window


-----------------------------
10) MATH TRICKS
-----------------------------

XOR 1 to n:
n % 4 == 0 → n
n % 4 == 1 → 1
n % 4 == 2 → n+1
n % 4 == 3 → 0

Sum of digits (1 to n):
Use digit DP


-----------------------------
END OF CP FORMULA NOTE
-----------------------------
*/

int main() {
    return 0;
}
