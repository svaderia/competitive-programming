// clang-format off
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;

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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // order_of_key find_by_order
// Please remove #define int lli

typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map; // order_of_key find_by_order

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
struct segment {
    // TODO: check if it can overflow
    int data;

    // TODO: Make sure the default constructor initialises identity element.
    segment(int m = 0) : data(m) {}

    // TODO: Update to any associative function.
    void join(const segment &other) {
        data += other.data;
    }

    void join(const segment &seg0, const segment &seg1) {
        *this = seg0;
        join(seg1);
    }
};

/* string to_string(segment c) { */
/*    return to_string(c.minimum); */
/* } */

struct seg_tree {
    int n;
    vector<int> lo, hi;
    vector<segment> seg;

    seg_tree(int nn) : n(nn), lo(4 * n), hi(4 * n), seg(4 * n) {
        build(0, n - 1, 1);
    }
    seg_tree(vector<segment> &arr) : n(sz(arr)), lo(4 * n), hi(4 * n), seg(4 * n) {
        build(0, n - 1, 1, arr);
    }

    void pull(int id) {
        seg[id].join(seg[2 * id], seg[2 * id + 1]);
    }

    void build(int l, int r, int id) {
        lo[id] = l, hi[id] = r;
        if (l == r)
            return;
        int mid = (l + r) / 2;
        build(l, mid, 2 * id);
        build(mid + 1, l, 2 * id + 1);
    }

    void build(int l, int r, int id, vector<segment> &arr) {
        lo[id] = l, hi[id] = r;
        if (l == r) {
            seg[id] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, 2 * id, arr);
        build(mid + 1, r, 2 * id + 1, arr);
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

        segment lquery = query(l, r, 2 * id);
        segment rquery = query(l, r, 2 * id + 1);
        lquery.join(rquery);
        return lquery;
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

        set(p, val, 2 * id);
        set(p, val, 2 * id + 1);
        pull(id);
    }

    int right_bound(int l, int val, int id = 1) {
        // No overlap
        if (l > hi[id] || seg[id].data < val) {
            return 0;
        }

        if (lo[id] == hi[id]) {
            return lo[id];
        }

        if (seg[2 * id].data >= val)
            return right_bound(l, val, 2 * id);
        else
            return right_bound(l, val, 2 * id + 1);
    }
};

// clang-format on
void solve(){
    int n;
    cin >> n;

    vi a(n);
    rep(i, n){
        cin >> a[i];
    }

    int m;
    cin >> m;

    vi p(m);
    rep(i, m){
        cin >> p[i];
    }

    ordered_set s;

    vi inv(n);
    rep(i, n){
        int ord = s.order_of_key(a[i]);
        dbg(a[i], ord, s);
        inv[i] = sz(s) - ord;
        s.insert(a[i]);
    }
    
    dbg(inv);

    int total = 0;
    rep(i, n){
        total += inv[i];
    }

    dbg(total);

    vi pref(m + 1);

    int j = 0;
    rep(i, m){
        while(j < p[i]){
            pref[i]++;
            if(i + inv[j] < m){
                pref[i + inv[j]]--;
            }

            j++;
        }
    }
    dbg(pref);

    int rsum = 0;
    int sum = 0;
    rep(i, m){
        rsum += pref[i];
        sum += rsum;
        cout << total - sum << endl;
    }






    

}

signed main(){
    fastio;

    solve();

    return 0;
}
