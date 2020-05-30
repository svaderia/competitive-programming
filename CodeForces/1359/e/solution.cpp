//https://codeforces.com/contest/1359/problem/E
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define endl "\n"
#define error(x) cerr << #x << " = " << (x) << endl
#define errorp(p) cerr << #p << " = " << (p.first) << ", " << (p.second) << endl

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

const long long mod = 998244353; 
#define ll lli

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (b) { ll d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}

struct modint{
    long long a;
 
    modint() : a(0){}
    modint(long long t){
        a = t % mod;
        if(a < 0) a += mod;
    }
 
    operator long long() const{ return a; }
 
    bool operator==(const modint &x) const{ return a == x.a; }
    bool operator!=(const modint &x) const{ return a != x.a; }
 
    modint operator-() const{ return modint(a ? (mod - a) : 0); }
    modint operator~() const{ return invert(*this); }
 
    modint operator+(const modint &x) const{ return modint(*this) += x; }
    modint operator-(const modint &x) const{ return modint(*this) -= x; }
    modint operator*(const modint &x) const{ return modint(*this) *= x; }
    modint operator/(const modint &x) const{ return modint(*this) /= x; }
 
    modint &operator+=(const modint &x){
        a += x.a;
        if(a >= mod) a -= mod;
        return *this;
    }
    modint &operator-=(const modint &x){
        a -= x.a;
        if(a < 0) a += mod;
        return *this;
    }
    modint &operator*=(const modint &x){
        a = a * x.a % mod;
        return *this;
    }
    modint &operator/=(const modint &x){
        a = a * (~x).a % mod; 
        return *this;
    }
 
    friend ostream &operator<<(ostream &os,const modint &x){
        return os << x.a;
    }
    friend istream &operator>>(istream &is,modint &x){
        long long t;
        is >> t;
        x = modint(t);
        return is;
    }
 
    modint pow(long long x) const{
        modint ret = 1,tmp = a;
        for(;x;tmp *= tmp,x >>= 1){
            if(x & 1) ret *= tmp;
        }
        return ret;
    }

    modint invert(modint a) const{
        ll x, y, g = euclid(a.a, mod, x, y);
        assert(g == 1); return modint((x + mod) % mod);
    }
};

template<class T>
struct Combination{
    vector<T> fact,factinv;
    Combination(int n) : fact(n + 1),factinv(n + 1){
        fact[0] = 1;
        for(int i = 1;i <= n;i++) fact[i] = fact[i - 1] * T(i);
        factinv[n] = ~fact[n];
        for(int i = n;i >= 1;i--) factinv[i - 1] = factinv[i] * T(i);
    }
    T nCr(int n,int r){
        if(r < 0 || n < r) return 0;
        return fact[n] * factinv[r] * factinv[n - r];
    }
};

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int n, k;
    cin >> n >> k;
    modint ans = modint(0);
    Combination<modint> comb(n);
    repA(i, 1, n){
        int mult = n / i - 1;
        ans += comb.nCr(mult, k - 1);
    }

    cout << ans << endl;

    return 0;
}
