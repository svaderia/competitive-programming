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

// clang-format on
struct node {
    int data;

    node(int d) : data(d) {}
    node() {}
} typedef node;


string to_string(node a){
  return to_string(a.data);
}


struct segtree {
    typedef node T;

    vector<int> lo, hi; // stores the left and right index for each node id.
    vector<T> seg;      // stores the data for each segment tree node.

    // TODO: You need to change the following
    T unit = T(0); // The identity element
    T merge(T a, T b) {
        return a.data + b.data;
    } // any associative function

    void update(int id) {
        seg[id] = merge(seg[2 * id], seg[2 * id + 1]);
    }

    segtree(int n) {
        lo.rsz(4 * n);
        hi.rsz(4 * n);
        seg.rsz(4 * n);
    }

    void build(int id, int l, int r, vector<int> &arr) {
        lo[id] = l, hi[id] = r;
        if (l == r) {
            seg[id] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id, l, mid, arr);
        build(2 * id + 1, mid + 1, r, arr);

        update(id);
    }

    // query [l, r]
    T query(int l, int r, int id = 1) {
        dbg(id, l, r, lo[id], hi[id]);
        if (l > hi[id] || lo[id] > r) { // query not inside
            return unit;
        }
        if (l <= lo[id] && hi[id] <= r) { // query completly inside
            return seg[id];
        }

        T lquery = query(l, r, 2 * id);
        T rquery = query(l, r, 2 * id + 1);
        dbg(lquery, rquery);

        return merge(lquery, rquery);
    }

    void set(int i, T val, int id = 1) {
        if (i > hi[id] || i < lo[id]) { // when not inside the segment, return
            return;
        }

        if (lo[id] == hi[id]) {
            seg[id] = val;
            return;
        }

        set(i, val, 2 * id);
        set(i, val, 2 * id + 1);

        update(id);
    };
};

void solve() {
    int n, q;
    cin >> n >> q;

    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    segtree s(n);
    s.build(1, 0, n - 1, a);

    dbg(s.seg);

    rep(i, q) {
      int op, x, y;
      cin >> op >> x >> y;

      if(op == 1){
        x--;
        s.set(x, y);
      }else{
        x--, y--;
        cout << s.query(x, y).data << endl;
      }
    }

    
}

signed main() {
    fastio;

    solve();

    return 0;
}
