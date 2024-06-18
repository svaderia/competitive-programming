// clang-format off
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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const lli INF   = 1e18;

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
// Remove this when it's an interactive problem
#define endl "\n"
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }
long long euclid(long long a, long long b, long long &x, long long &y) {
    if (b) { long long d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}

const long long mod = 998244353;
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



struct segment_change {
    // TODO: check for overflows
    modint la, lb;

    // TODO: Make sure the default constructor initialises identity element.
    segment_change(int _la = 0, int _lb = 0) : la(_la), lb(_lb){}

    bool has_change() const {
        return true;
    }

    // Return the combined result of applying this segment_change followed by `other`.
    // TODO: check for boundary values.
    segment_change combine(const segment_change &other) {
        return segment_change(la + other.la, lb + other.lb);
    }
};

/* string to_string(segment_change c) { */
/*     vector<int> print = {c.to_add, c.to_set}; */
/*     return to_string(print) ; */
/* } */

struct segment {
    // TODO: check if it can overflow
    modint a, b, ab, len;

    // TODO: Make sure the default constructor initialises identity element.
    segment(int _a = 0, int _b = 0, int _len = 0) : a(_a), b(_b), ab(a * b), len(_len) {}

    void apply(const segment_change &change) {
        ab += change.la * b + change.lb * a + change.la * change.lb * len;
        a += change.la * len;
        b += change.lb * len;
    }

    // TODO: Update to any associative function.
    void join(const segment &other) {
        a += other.a;
        b += other.b;
        ab += other.ab;
        len += other.len;
    }

    void join(const segment &seg0, const segment &seg1) {
        *this = seg0;
        join(seg1);
    }
};

/* string to_string(segment c) { */
/*     vector<int> print = {c.sum, c.len}; */
/*     return to_string(print) ; */
/* } */

struct seg_tree_lazy {
    int n;
    vector<int> lo, hi;
    vector<segment> seg;
    vector<segment_change> seg_change;

    void pull(int id) {
        seg[id].join(seg[2 * id], seg[2 * id + 1]);
    }

    void apply_and_combine(int id, const segment_change &change) {
        seg[id].apply(change);
        seg_change[id] = seg_change[id].combine(change);
    }

    void push(int id) {
        if (lo[id] != hi[id] && seg_change[id].has_change()) {
            apply_and_combine(2 * id, seg_change[id]);
            apply_and_combine(2 * id + 1, seg_change[id]);
        }
        seg_change[id] = segment_change();
    }

    void build(int id, int l, int r) {
        lo[id] = l, hi[id] = r;
        if (l == r)
            return;
        int mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
    }

    void build(int id, int l, int r, vector<segment> &arr) {
        lo[id] = l, hi[id] = r;
        if (l == r) {
            seg[id] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id, l, mid, arr);
        build(2 * id + 1, mid + 1, r, arr);
        pull(id);
    }

    // query [l, r]
    segment query(int l, int r, int id = 1) {
        // outside
        if (lo[id] > r || hi[id] < l) {
            return segment();
        }

        if (l <= lo[id] && hi[id] <= r) {
            return seg[id];
        }

        push(id);

        segment lquery = query(l, r, 2 * id);
        segment rquery = query(l, r, 2 * id + 1);
        lquery.join(rquery);
        return lquery;
    }

    void range_change(int l, int r, segment_change change, int id = 1) {
        if (l > hi[id] || r < lo[id])
            return;

        if (l <= lo[id] && hi[id] <= r) {
            apply_and_combine(id, change);
            return;
        }

        push(id);

        range_change(l, r, change, 2 * id);
        range_change(l, r, change, 2 * id + 1);

        pull(id);
    }

    void set(int p, segment val, int id = 1) {
        // No overlap
        if (p < lo[id] || p > hi[id]) {
            return;
        }

        if (lo[id] == hi[id]) {
            seg[id] = val;
            return;
        }

        push(id);

        set(p, val, 2 * id);
        set(p, val, 2 * id + 1);
        pull(id);
    }

    seg_tree_lazy(int nn) : n(nn), lo(4 * n), hi(4 * n), seg(4 * n), seg_change(4 * n) {
        build(1, 0, n - 1);
    }
    seg_tree_lazy(vector<segment> &arr) : n(sz(arr)), lo(4 * n), hi(4 * n), seg(4 * n), seg_change(4 * n) {
        build(1, 0, n - 1, arr);
    }
};

// clang-format on
void solve() {
    int n, q;
    cin >> n >> q;

    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vi b(n);
    rep(i, n) {
        cin >> b[i];
    }

    vector<segment> seg(n);
    rep(i, n) {
        seg[i] = segment(a[i], b[i], 1);
    }

    seg_tree_lazy s(seg);

    rep(k, q) {
        int op;
        cin >> op;

        if (op == 3) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << s.query(l, r).ab << endl;
        } else if (op == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            l--, r--;

            s.range_change(l, r, segment_change(val, 0));
        } else {
            int l, r, val;
            cin >> l >> r >> val;
            l--, r--;

            s.range_change(l, r, segment_change(0, val));
        }
    }
}

signed main() {
    fastio;

    solve();

    return 0;
}
