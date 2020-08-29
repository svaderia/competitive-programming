#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

    modint() : a(1), used(false){}
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

void solve(){

    int n;
    cin >> n;

    set<int> s;
    vi count(n + 1, 0);
    rep(i, n){
        int x;
        cin >> x;
        s.insert(x);
        count[x]++;
    }
    vector<vector<modint>> suf(n + 2, vector<modint>(1));
    vector<vector<modint>> pre(n + 2, vector<modint>(1));

    int maximum = 0;
    for(auto x : s){
        maximum = max(maximum, count[x]);
    }

    Combination<modint> nc = Combination<modint>(maximum);

    int prev = n + 1;
    vi nxt(n + 1);
    vi previous(n + 1);
    int mx = 0;
    for(auto it = s.rbegin(); it != s.rend(); it++){
        int x = *it;
        int c = count[x];
        dbg(x);
        modint temp = modint(1);
        mx = max(c, mx);
        repA(t, 1, mx){
            while(sz(suf[prev]) < t + 1) suf[prev].pb(suf[prev][sz(suf[prev]) - 1]);
            temp += nc.nCr(c, t);
            suf[x].pb(suf[prev][t] * temp);
        }
        nxt[x] = prev;
        prev = x;
    }

    prev = 0;
    mx = 0;
    for(auto x : s){
        int c = count[x];
        dbg(x);
        modint temp = modint(1);
        mx = max(c, mx);
        repA(t, 1, mx){
            while(sz(pre[prev]) < t + 1) pre[prev].pb(pre[prev][sz(pre[prev]) - 1]);
            temp += nc.nCr(c, t);
            pre[x].pb(pre[prev][t] * temp);
        }
        previous[x] = prev;
        prev = x;
    }

    /* repD(x, n, 1){ */
    /*     for(auto p : table[x]){ */
    /*         cout << p.f << spc << p.s << endl; */
    /*     } */
    /* } */

    vector<modint> ans(n + 1, modint(0));
    for(auto x : s){
        int c = count[x];
        repA(cc, 1, c){
            /* int cca = (*(suf[x + 1].upper_bound(cc)--)).f; */
            ans[x] += nc.nCr(c, cc) * suf[nxt[x]][cc] * pre[previous[x]][cc - 1];
        }
    }

    repA(x, 1, n){
        cout << ans[x] << spc;
    }
    cout << endl;

}

signed main(){
    fastio;

    int T;
    cin >> T;

    repA(tc, 1, T){
        solve();
    }

    return 0;
}
