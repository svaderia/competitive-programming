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

long long euclid(long long a, long long b, long long &x, long long &y) {
    if (b) { long long d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}

const long long mod = 747474747;
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

vvi points;
int d;

int dist(int x1, int x2){
    int ans = 0;
    vi &p1 = points[x1];
    vi &p2 = points[x2];
    rep(i, d){
        ans += abs(p1[i] - p2[i]) * abs(p1[i] - p2[i]);
    }

    return ans;
}

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

// 0-based indexing assumed

struct UnionFind {
    int n, set_size;
    vi parent, rank;

    UnionFind(int a) : n(a), set_size(n), parent(n), rank(n) {
        rep(i, n) parent[i]=i, rank[i]=1;
    }

    int find(int x) {
        if (x != parent[x]) return parent[x] = find(parent[x]);
        return x;
    }

    void unite(int x, int y) {
        int xroot = find(x), yroot = find(y);
        if (xroot != yroot) {
            if (rank[xroot] >= rank[yroot]) {
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
            }
            else {
                parent[xroot] = yroot;
                rank[yroot] += rank[xroot];
            }
            set_size -= 1;
        }
    }

    bool connected(int x, int y){
        return find(x) == find(y);
    }

    int size() { return set_size; }
};

void solve(){

    int n;
    cin >> n >> d;

    points.clear();
    points.rsz(n);

    rep(i, n){
        rep(j, d){
            int x;
            cin >> x;
            points[i].pb(x);
        }
    }
    dbg(points);

    vector<pair<int, pii> > pq;
    rep(x1, n){
        repA(x2, x1 + 1, n - 1){
            pq.pb(mp(dist(x1, x2), mp(x1, x2)));
        }
    }

    modint ans(1);

    sort(rall(pq));

    UnionFind dsu(n);
    int cnt = 0;

    for(auto pnt : pq){
        if(cnt == n - 1) break;
        int distance = pnt.f, x1 = pnt.s.f, x2 = pnt.s.s;
        if(distance <= 1) break;
        dbg(x1, x2, distance);
        if(!dsu.connected(x1, x2)){
            cnt++;
            ans *= modint(distance);
            dsu.unite(x1, x2);
        }
    }

    cout << ans << endl;

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
