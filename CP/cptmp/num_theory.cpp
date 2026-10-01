#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

// ===================== BASIC =====================
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);} 
ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}
bool coprime(ll a,ll b){return gcd(a,b)==1;}

// ===================== EXTENDED GCD =====================
ll extended_gcd(ll a,ll b,ll &x,ll &y){
    if(b==0){x=1;y=0;return a;}
    ll x1,y1;
    ll g=extended_gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return g;
}

// ===================== MOD =====================
ll mod_add(ll a,ll b,ll m){return (a%m+b%m)%m;}
ll mod_sub(ll a,ll b,ll m){return (a%m-b%m+m)%m;}
ll mod_mul(ll a,ll b,ll m){return (a%m*b%m)%m;}

ll mod_pow(ll a,ll b,ll m){
    ll r=1; a%=m;
    while(b){
        if(b&1) r=mod_mul(r,a,m);
        a=mod_mul(a,a,m);
        b>>=1;
    }
    return r;
}

ll mod_inv(ll a,ll m){
    ll x,y;
    ll g=extended_gcd(a,m,x,y);
    if(g!=1) return -1;
    return (x%m+m)%m;
}

// ===================== PRIME =====================
bool is_prime(ll n){
    if(n<2) return false;
    if(n<=3) return true;
    if(n%2==0||n%3==0) return false;
    for(ll i=5;i*i<=n;i+=6)
        if(n%i==0||n%(i+2)==0) return false;
    return true;
}

// ===================== SIEVE =====================
const int N = 2e6+5;
vector<long long > all_Primes;

void sieve(){
    vector<bool> prime(N+1,true);

    prime[0]=prime[1]=false;

    for(int i=2;i*i<=N;i++){
        if(prime[i]){
            for(int j=i*i;j<=N;j+=i){
                prime[j]=false;
            }
        }
    }

    for(int i=2;i<=N;i++){
        if(prime[i]){
            all_Primes.push_back(i);
        }
    }
}


// ===================== SPF =====================1
int spf[N];

void compute_spf(){
    for(int i=1;i<N;i++) spf[i]=i;
    for(int i=2;i*i<N;i++)
        if(spf[i]==i)
            for(int j=i*i;j<N;j+=i)
                if(spf[j]==j) spf[j]=i;
}

// ===================== FACTORIZATION ===================== depends on compute spf
map<ll,int> spf_factor1(ll n){
    map<ll,int> mp;
    while(n>1){mp[spf[n]]++; n/=spf[n];}
    return mp;
}

// ================= TRIAL FACTORIZATION (FALLBACK) SPF2================= phitron r ,not depends on compute spf.use this
map<int,int> spf_Factor2(int n){
    map<int,int> cnt;

    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
            cnt[i]++;
            n /= i;
        }
    }

    if(n > 1) cnt[n]++;

    return cnt;
}


// ===================== DIVISORS =====================

vector<int> getDivisors(int n) {
    vector<int> divisors;

    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            divisors.push_back(i);
            if(i != n / i)
                divisors.push_back(n / i);
        }
    }

    sort(divisors.begin(), divisors.end());
    return divisors;
}

ll count_div(ll n){
    auto mp=spf_factor1(n);
    ll r=1;
    for(auto [p,c]:mp) r*=(c+1);
    return r;
}

ll sum_div(ll n){
    auto mp=spf_factor1(n);
    ll r=1;
    for(auto [p,c]:mp){
        ll term=1,cur=1;
        for(int i=0;i<c;i++){cur*=p; term+=cur;}
        r*=term;
    }
    return r;
}

//=====================PRIME DIVISORS===================
//main func
const int MAXN=200005;
vector<int> prime_divisors[MAXN];
 
void precompute_primeDivisor(){
    for(int i=2;i<MAXN;++i){
        if(prime_divisors[i].empty()){
            for(int j=i;j<MAXN;j+=i){
                prime_divisors[j].push_back(i);
            }
        }
    }
}

// ===================== EULER PHI =====================
ll phi(ll n){
    ll r=n;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            while(n%i==0) n/=i;
            r-=r/i;
        }
    }
    if(n>1) r-=r/n;
    return r;
}

// ===================== PHI SIEVE =====================
ll phi_arr[N];

void phi_sieve(){
    for(int i=0;i<N;i++) phi_arr[i]=i;
    for(int i=2;i<N;i++)
        if(phi_arr[i]==i)
            for(int j=i;j<N;j+=i)
                phi_arr[j]-=phi_arr[j]/i;
}

// ===================== MOBIUS FUNCTION =====================
int mobius[N];

void mobius_sieve(){
    for(int i=1;i<N;i++) mobius[i]=1;
    for(int i=2;i<N;i++){
        if(spf[i]==i){
            for(int j=i;j<N;j+=i) mobius[j]*=-1;
            for(ll j=1LL*i*i;j<N;j+=1LL*i*i) mobius[j]=0;
        }
    }
}

// ===================== BINARY GCD =====================
ll binary_gcd(ll a,ll b){
    if(!a) return b;
    if(!b) return a;
    int shift=__builtin_ctz(a|b);
    a>>=__builtin_ctz(a);
    do{
        b>>=__builtin_ctz(b);
        if(a>b) swap(a,b);
        b-=a;
    }while(b);
    return a<<shift;
}



// ===================== LEGENDRE =====================
ll power_in_fact(ll n,ll p){
    ll c=0;
    while(n){n/=p; c+=n;} return c;
}

// ===================== CRT =====================
ll crt(ll a1,ll m1,ll a2,ll m2){
    ll x,y;
    ll g=extended_gcd(m1,m2,x,y);
    if((a2-a1)%g!=0) return -1;
    ll l=m1/g*m2;
    ll res=(a1 + (a2-a1)/g * x % (m2/g) * m1)%l;
    return (res+l)%l;
}

// ===================== MILLER RABIN =====================
ll mulmod(ll a,ll b,ll m){return (__int128)a*b%m;}

ll binpow(ll a,ll d,ll m){
    ll r=1;
    while(d){
        if(d&1) r=mulmod(r,a,m);
        a=mulmod(a,a,m);
        d>>=1;
    }
    return r;
}

bool miller_rabin(ll n){
    if(n<2) return false;
    for(ll p:{2,3,5,7,11,13,17,19,23}){
        if(n%p==0) return n==p;
    }
    ll d=n-1,s=0;
    while((d&1)==0){d>>=1; s++;}
    for(ll a:{2,325,9375,28178,450775,9780504,1795265022}){
        if(a%n==0) continue;
        ll x=binpow(a,d,n);
        if(x==1||x==n-1) continue;
        bool comp=true;
        for(int r=1;r<s;r++){
            x=mulmod(x,x,n);
            if(x==n-1){comp=false; break;}
        }
        if(comp) return false;
    }
    return true;
}

// ===================== POLLARD RHO =====================
ll f(ll x,ll c,ll mod){return (mulmod(x,x,mod)+c)%mod;}

ll pollard(ll n){
    if(n%2==0) return 2;
    ll x=rand()%n,y=x,c=rand()%n;
    ll d=1;
    while(d==1){
        x=f(x,c,n);
        y=f(f(y,c,n),c,n);
        d=gcd(abs(x-y),n);
        if(d==n) return pollard(n);
    }
    return d;
}

// ===================== TIPS =====================
/*
TOPICS COVERED:
- gcd, lcm
- modular arithmetic
- sieve, spf
- factorization
- divisors
- euler totient
- mobius
- nCr
- CRT
- Miller Rabin
- Pollard Rho

TRICKS:
1. gcd(a,b,c)=gcd(gcd(a,b),c)
2. lcm overflow -> divide first
3. (a/b)%mod != a%mod * inv(b)%mod ALWAYS
4. sqrt decomposition often useful
5. use __int128 for overflow
6. primes upto 1e6 -> sieve
7. large primes -> miller rabin
8. fast factor -> pollard rho
9. mobius for inclusion exclusion
10. phi for coprime count
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    compute_spf();
    

    return 0;
}
