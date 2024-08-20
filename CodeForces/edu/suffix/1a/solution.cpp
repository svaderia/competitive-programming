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
void solve() {
    string s;
    cin >> s;

    s.pb('$');

    int alphabet = 256;

    int n = sz(s);

    vi p(n), c(n);

    // size 1 sort with counting;

    vi cnt(alphabet);

    rep(i, n) {
        cnt[s[i]]++;
    }

    rep(i, alphabet - 1) {
        cnt[i + 1] += cnt[i];
    }

    rep(i, n) {
        p[--cnt[s[i]]] = i;
    }
    dbg(s, p);

    int classes = 0;

    c[p[0]] = 0;
    repA(i, 1, n - 1) {
        if (s[p[i]] != s[p[i - 1]])
            classes++;

        c[p[i]] = classes;
    }

    dbg(s, classes, c);

    // size 2^(k + 1) sorting with 2^k available

    for (int z = 1; z < n; z *= 2) {
        vii cs(n);
        rep(i, n) {
            int idx = p[i];
            cs[idx] = mp(c[idx], c[(idx + z) % n]);
        }
        dbg(cs);

        auto cmp = [&](int x, int y) { return cs[x] < cs[y]; };

        sort(all(p), cmp);
        dbg(p);

        classes = 0;
        c[p[0]] = 0;

        repA(i, 1, n - 1) {
            if (cs[p[i]] != cs[p[i - 1]]) {
                classes++;
            }

            c[p[i]] = classes;
        }
    }

    dbg(p);

    rep(i, n) {
        cout << p[i] << spc;
    }
    cout << endl;
}

signed main() {
    fastio;

    solve();

    return 0;
}
