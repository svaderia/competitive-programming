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

// clang-format on
struct segment {
    // TODO: check if it can overflow
    int minimum;

    // TODO: Make sure the default constructor initialises identity element.
    segment(int m = INF) : minimum(m) {}

    // TODO: Update to any associative function.
    void join(const segment &other) {
        minimum = min(minimum, other.minimum);
    }

    void join(const segment &seg0, const segment &seg1) {
        *this = seg0;
        join(seg1);
    }
};

struct segment_tree {
    int n;
    vector<int> lo, hi;
    vector<segment> seg;

    segment_tree(int _n) : n(_n), lo(4 * n), hi(4 * n), seg(4 * n) {}
    segment_tree(vector<segment> &arr) : n(sz(arr)), lo(4 * n), hi(4 * n), seg(4 * n) {
        build(0, n - 1, 1, arr);
    }

    void pull(int id) {
        seg[id].join(seg[2 * id], seg[2 * id + 1]);
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
        if (l > hi[id] || r < lo[id]) {
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
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<segment> a(n);
    rep(i, n) {
        cin >> a[i].minimum;
    }

    segment_tree s(a);

    rep(i, q) {
        int op;
        cin >> op;

        if (op == 1) {
            int k, val;
            cin >> k >> val;
            k--;

            s.set(k, val);
        } else {
            int x, y;
            cin >> x >> y;
            x--, y--;

            cout << s.query(x, y).minimum << endl;
        }
    }
}

signed main() {
    fastio;

    solve();

    return 0;
}
