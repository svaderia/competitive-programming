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

#define ll lli

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (b) { ll d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}

const ll mod = 1000000007;
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
        ll x, y, g = euclid(z.a, mod, x, y);
        assert(g == 1); return modint((x + mod) % mod);
    }
};

typedef vector<modint> vm;


// TO_STRING
string to_string(char c) { return string(1,c); }
string to_string(const char* s) { return (string)s; }
string to_string(modint x) { return to_string(x.a); }
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

int n, m, q;

struct Matrix {
    vvi a = vvi(n, vi(n));

    Matrix operator *(const Matrix& other) {
        Matrix product;
        vector<vector<long long>> tmp(n, vector<long long>(n));
        rep(i,n)rep(j,n)rep(k,n) {
            tmp[i][k] += (long long) a[i][j] * other.a[j][k];
            if(tmp[i][k] >= 8LL * mod * mod) {
                tmp[i][k] %= mod;
            }
            // product.a[i][k] = (product.a[i][k] + (long long) a[i][j] * other.a[j][k]) % mod;
        }
        rep(i,n)rep(j,n) product.a[i][j] = tmp[i][j] % mod;
        return product;
    }
};

vector<Matrix> precompute;

Matrix expo_power(Matrix a, long long k) {
    Matrix product;
    rep(i,n) product.a[i][i] = 1;
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
    cin >> n >> m >> q;

    Matrix adj;
    rep(i, m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj.a[u][v] = 1;
    }

    vector<pair<int, pii> > queries(q);
    vii ks;
    int mxk = 0;
    rep(i, q){
        int ss, t, k;
        cin >> ss >> t >> k;
        ss--; t--;
        queries[i] = {k, {ss, t}};
        ks.pb({k, i});
        mxk = max(k, mxk);
    }

    int BASE = 1;
    int idx = 0;
    while(BASE < mxk){
        BASE *= 2;
        idx++;
    }

    precompute.rsz(idx + 1);
    precompute[0] = adj;
    repA(i, 1, idx){
        precompute[i] = precompute[i - 1] * precompute[i - 1];
    }

    vi fin(q);
    rep(_, q){
        int k, ss, t;
        k = queries[_].f;
        ss = queries[_].s.f;
        t = queries[_].s.s;

        vi curr(n);
        curr[ss] = 1;

        idx = 0;
        while(k > 0){
            if(k&1){
                vi temp(n);
                rep(i, n) rep(j, n){
                    temp[j] += (curr[i] * precompute[idx].a[i][j]) % MOD;
                }
                rep(i, n) curr[i] = temp[i] % MOD;

            }
            k /= 2;
            idx++;
        }

        fin[_] = curr[t];





    }

    rep(i, q){
        cout << fin[i] << endl;
    }


}

signed main(){
    fastio;

    solve();

    return 0;
}
