#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD   = 1e9 + 7;
const double PI = acos(-1.0);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
const int INF   = 1e18;

#define fastio            ios_base::sync_with_stdio(false);cin.tie(0)
#define sz(a) int((a).size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define f first
#define s second
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define endl "\n"
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }


// TO_STRING
string to_string(char c) { return string(1,c); }
string to_string(const char* s) { return (string)s; }
string to_string(string s) { return s; }
string to_string(bool b) {
    #ifdef DEBUG
        return b ? "true" : "false";
    #else
        return to_string((int)b);
    #endif
}
template<class A> string to_string(complex<A> c) {
    stringstream ss; ss << c; return ss.str(); }
string to_string(vector<bool> v) {
    string res = "{"; rep(i,sz(v)) res += char('0'+v[i]);
    res += "}"; return res; }
template<size_t SZ> string to_string(bitset<SZ> b) {
    string res = ""; rep(i,SZ) res += char('0'+b[i]);
    return res; }
template<class A, class B> string to_string(pair<A,B> p);
template<class T> string to_string(T v) { // containers with begin(), end()
    #ifdef DEBUG
        bool fst = 1; string res = "{";
        for (const auto& x: v) {
            if (!fst) res += ", ";
            fst = 0; res += to_string(x);
        }
        res += "}"; return res;
    #else
        bool fst = 1; string res = "";
        for (const auto& x: v) {
            if (!fst) res += " ";
            fst = 0; res += to_string(x);
        }
        return res;

    #endif
}
template<class A, class B> string to_string(pair<A,B> p) {
    #ifdef DEBUG
        return "("+to_string(p.f)+", "+to_string(p.s)+")";
    #else
        return to_string(p.f)+" "+to_string(p.s);
    #endif
}

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
    DBG(t...); }
#ifdef DEBUG // compile with -DDEBUG
    #define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif

long long euclid(long long a, long long b, long long &x, long long &y) {
    if (b) { long long d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}

const long long mod = 1000000007;
/* template<long long mod = 1000000007> */
struct modint{
    long long a;
    bool used;

    modint() : a(0), used(false){}
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

    modint invert(modint z) const{
        long long x, y, g = euclid(z.a, mod, x, y);
        assert(g == 1); return modint((x + mod) % mod);
    }
};

// for debug
string to_string(modint z){
    return to_string(z.a);
}

typedef vector<modint> vm;

const int N = 6;

struct Matrix {
    vector<vm> a;
    Matrix() : a(N, vm(N)) {}

    Matrix operator *(const Matrix& other) {
        Matrix product;
        rep(i,N)rep(j,N)rep(k,N) {
            product.a[i][k] += a[i][j] * other.a[j][k];
        }
        return product;
    }

};

Matrix expo_power(Matrix a, long long k) {
    Matrix product;
    rep(i,N) product.a[i][i] = 1;
    while(k > 0) {
        if(k % 2) {
            product = product * a;
        }
        a = a * a;
        k /= 2;
    }
    return product;
}

void solve(){
    int n;
    cin >> n;

    Matrix x;
    rep(i, N){
        x.a[0][i] = 1;
    }
    repA(i, 1, N - 1){
        x.a[i][i - 1] = 1;
    }

    vm f(N + 1, modint(1));
    modint runn;
    repA(i, 1, N){
        f[i] += runn;
        runn += f[i];
    }
    if(n <= 6){
        cout << f[n] << endl;
        return;
    }

    Matrix po = expo_power(x, n - 6);

    modint ans;
    rep(i, N){
        ans += po.a[0][i] * f[N - i];
    }

    cout << ans << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
