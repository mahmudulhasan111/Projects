/*
====================================================
         MODULAR ARITHMETIC FORMULA NOTE
====================================================

1️⃣ BASIC DEFINITIONS:
- a % m = remainder when a is divided by m
- In C++: a % m
- Negative numbers: (-a % m + m) % m to get positive remainder

----------------------------------------------------
2️⃣ BASIC PROPERTIES:

1) Addition:
(a + b) % m = ((a % m) + (b % m)) % m

2) Subtraction:
(a - b) % m = ((a % m - b % m) + m) % m

3) Multiplication:
(a * b) % m = ((a % m) * (b % m)) % m

4) Exponentiation:
(a^b) % m = ((a % m)^b) % m
Use binary exponentiation for large b

5) Division / Modular Inverse:
(a / b) % m = a * b_inv % m
b_inv exists if gcd(b,m) = 1
If m is prime: b_inv = b^(m-2) % m (Fermat's little theorem)

----------------------------------------------------
3️⃣ ADVANCED PROPERTIES:

1) Distributive law:
(a + b) * c % m = ((a*c)%m + (b*c)%m) % m

2) Negative numbers:
(-a) % m = (m - (a % m)) % m

3) Large numbers:
Reduce modulo step by step to avoid overflow

----------------------------------------------------
4️⃣ C++ EXAMPLES:

#include <bits/stdc++.h>
using namespace std;

// Binary exponentiation for (x^y) % m
long long modPow(long long x, long long y, long long m) {
    long long res = 1;
    x = x % m;
    while(y) {
        if(y & 1) res = (res * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}

// Modular inverse using Fermat (if m is prime)
long long modInverse(long long b, long long m) {
    return modPow(b, m-2, m);
}

// modular inverse using Fermat's theorem
ll modInv(ll x, ll m = INF) {
    ll res = 1, y = m - 2;
    x %= m;
    while(y) {
        if(y & 1) res = (res * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}
int main() {
    long long a = 17, b = 5, m = 7;

    // Addition
    long long add = ( (a % m) + (b % m) ) % m;

    // Subtraction
    long long sub = ( (a % m - b % m + m) % m );

    // Multiplication
    long long mul = ( (a % m) * (b % m) ) % m;

    // Exponentiation
    long long exp = modPow(a, b, m);

    // Division
    long long div = (a * modInverse(b, m)) % m;

    // Output examples
    cout << "Addition: " << add << "\n";
    cout << "Subtraction: " << sub << "\n";
    cout << "Multiplication: " << mul << "\n";
    cout << "Exponentiation: " << exp << "\n";
    cout << "Division: " << div << "\n";

    return 0;
}

----------------------------------------------------
5️⃣ TIPS:

- Always reduce numbers modulo m during calculation
- For negative numbers: (x % m + m) % m
- Division requires modular inverse
- Use binary exponentiation for large powers
- Works for CP problems, number theory, combinatorics

====================================================
               END OF NOTE
====================================================
*/
