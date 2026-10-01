// GCD function (Euclidean Algorithm)
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;   // range GCD → initial value = 0
}

// LCM function
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;   // range LCM → initial value = 1
}
