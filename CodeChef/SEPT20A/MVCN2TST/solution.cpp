
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet; // order_of_key find_by_order

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

const int MAXN = 2e5 + 5;
vvi g;
vvi height;
int  tin[MAXN], tout[MAXN], h[MAXN], nd[MAXN], rem[MAXN];
int timer = 0;
int md = 0;

bool compare(pii &a, pii &b){
    if(a.f != b.f)
        return a.f < b.f;
    if(h[a.s] != h[b.s])
        return h[a.s] < h[b.s];
    return a.s < b.s;
}

void dfs(int root, int p, int d){
    h[root] = d;
    height[d].pb(root);
    md = max(md, d);

    tin[root] = timer++;
    nd[root] = 1;

    for(auto child : g[root]){
        if(child != p){
            dfs(child, root, d + 1);
            nd[root] += nd[child];
        }
    }

    tout[root] = timer++;
}

bool is_ancestor(int u, int v){
    return (tin[v] <= tin[u] && tout[u] <= tout[v]);
}

void solve(){

    int n;
    cin >> n;

    g.clear();
    g.rsz(n);
    height.clear();
    height.rsz(n);

    rep(i, n - 1){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    int q;
    cin >> q;

    timer = 0;
    md = 0;
    dfs(0, 0, 0);

    md++;
    rep(i, md){
        sort(all(height[i]));
    }

    vi prefh(md + 1);
    rep(i, md){
        prefh[i + 1] = sz(height) + prefh[i];
    }

    vi pref(n);
    repA(i, 1, n - 1){
        pref[i] = (n - nd[i]) + pref[i - 1];
    }

    modint d;
    modint two(2);
    modint three(3);

    vii valid[n];
    int sid = 0;

    rep(i, q){
        int e;
        cin >> e;

        int c = e ^ d.a;
        int id = 0;

        while(id < sid && rem[id++] <= c) c++;
        dbg(c);
        int initc = c;

        int which = lower_bound(all(pref), c) - pref.begin();
        dbg(which);
        c -= pref[which - 1];

        dbg(c);

        int starth = 0;
        int end = 0;
        while(starth < h[which] && c > sz(height[starth])){
            c -= sz(height[starth]);
            starth++;
        }
        dbg(starth, c, h[which]);
        while(c > 0){
            for(auto xx : height[starth]){
                if(which == xx || (tin[which] <= tin[xx] && tout[xx] <= tout[which])) continue;
                end = xx;
                c--;
                if(c == 0) break;
            }
            starth++;
        }

        dbg(end);

        d += two * modint(which + 1) + three * modint(end + 1);
        two *= modint(2);
        three *= modint(3);

        rem[sid++] = initc;
        repD(ii, sid - 1, 1){
            if(!(rem[ii - 1] > rem[i])) break;
            swap(rem[ii], rem[ii - 1]);
        }
    }

    cout << d << endl;

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
