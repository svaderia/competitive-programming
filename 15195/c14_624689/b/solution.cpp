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
// 0-based indexing assumed

struct UnionFind {
    int n, set_size;
    vi parent, rank;

    UnionFind(int a) : n(a), set_size(n), parent(n), rank(n, 1) {
        rep(i, n) parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            return parent[x] = find(parent[x]);
        return x;
    }

    bool merge(int x, int y) {
        int xroot = find(x), yroot = find(y);
        if (xroot == yroot)
            return false;
        if (rank[xroot] < rank[yroot])
            swap(xroot, yroot);
        parent[yroot] = xroot;
        rank[xroot] += rank[yroot];
        set_size -= 1;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size() {
        return set_size;
    }
};
long long euclid(long long a, long long b, long long &x, long long &y) {
    if (b) {
        long long d = euclid(b, a % b, y, x);
        return y -= a / b * x, d;
    }
    return x = 1, y = 0, a;
}

const long long mod = 1000000007;
/* template<long long mod = 1000000007> */
struct modint {
    long long a;
    bool used;

    modint() : a(0), used(false) {}
    modint(long long t) {
        a = t % mod;
        if (a < 0)
            a += mod;
    }

    operator long long() const {
        return a;
    }

    bool operator==(const modint &x) const {
        return a == x.a;
    }
    bool operator!=(const modint &x) const {
        return a != x.a;
    }

    modint operator-() const {
        return modint(a ? (mod - a) : 0);
    }
    modint operator~() const {
        return invert(*this);
    }

    modint operator+(const modint &x) const {
        return modint(*this) += x;
    }
    modint operator-(const modint &x) const {
        return modint(*this) -= x;
    }
    modint operator*(const modint &x) const {
        return modint(*this) *= x;
    }
    modint operator/(const modint &x) const {
        return modint(*this) /= x;
    }

    modint &operator+=(const modint &x) {
        a += x.a;
        if (a >= mod)
            a -= mod;
        return *this;
    }
    modint &operator-=(const modint &x) {
        a -= x.a;
        if (a < 0)
            a += mod;
        return *this;
    }
    modint &operator*=(const modint &x) {
        a = a * x.a % mod;
        return *this;
    }
    modint &operator/=(const modint &x) {
        a = a * (~x).a % mod;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const modint &x) {
        return os << x.a;
    }
    friend istream &operator>>(istream &is, modint &x) {
        long long t;
        is >> t;
        x = modint(t);
        return is;
    }

    modint pow(long long x) const {
        modint ret = 1, tmp = a;
        for (; x; tmp *= tmp, x >>= 1) {
            if (x & 1)
                ret *= tmp;
        }
        return ret;
    }

    modint invert(modint z) const {
        long long x, y, g = euclid(z.a, mod, x, y);
        assert(g == 1);
        return modint((x + mod) % mod);
    }
};

// for debug
string to_string(modint z) {
    return to_string(z.a);
}

typedef vector<modint> vm;
template <class T> struct Combination {
    vector<T> fact, factinv;
    Combination(int n) : fact(n + 1), factinv(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++)
            fact[i] = fact[i - 1] * T(i);
        factinv[n] = ~fact[n];
        for (int i = n; i >= 1; i--)
            factinv[i - 1] = factinv[i] * T(i);
    }
    T nCr(int n, int r) {
        if (r < 0 || n < r)
            return 0;
        return fact[n] * factinv[r] * factinv[n - r];
    }
};

void solve() {
    int n, k;
    cin >> n >> k;

    UnionFind dsu(n + 1);
    vi ref(n + 1, 0);
    rep(i, k) {
        int a, b;
        cin >> a >> b;
        ref[a]++;
        ref[b]++;
        if (ref[a] > 2 || ref[b] > 2) {
            cout << -1 << endl;
            return;
        }
        if (dsu.same(a, b)) {
            cout << -1 << endl;
            return;
        }
        dsu.merge(a, b);
    }

    int cnt = 0;
    int d = 0;

    repA(i, 1, n) {
        if (dsu.parent[i] == i) {
            cnt++;
            if (dsu.rank[i] > 1) {
                d++;
            }
        }
    }

    Combination<modint> c(cnt);

    cout << c.fact[cnt] * modint(2).pow(d) << endl;
}

signed main() {
    fastio;

    solve();

    return 0;
}
