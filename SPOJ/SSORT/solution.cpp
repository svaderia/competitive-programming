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

vvi g;
map<int, int> pos;
vb visited;
vi a, b;

tuple<int, int, int> dfs(int root){
    visited[root] = true;
    int len, mn, sum;
    mn = sum = b[root];
    len = 1;
    for(auto child : g[root]){
        if(visited[child]) continue;
        dbg(root, g[root]);
        tuple<int, int, int> p = dfs(child);
        int l1, m1, s1;
        tie(l1, m1, s1) = p;
        len += l1; mn = min(mn, m1); sum += s1;
    }
    return make_tuple(len, mn, sum);
}

bool solve(int tc){
    int n;
    cin >> n;
    if(n == 0) return false;
    a.rsz(n); b.rsz(n);
    pos.clear();
    rep(i, n){
        cin >> a[i];
        pos[a[i]] = i;
        b[i] = a[i];
    }
    sort(all(a));
    int min_ele = a[0];
    g.clear();
    g.rsz(n);
    rep(i, n){
        g[pos[a[i]]].pb(i);
    }
    visited.clear();
    visited.rsz(n, false);

    int ans = 0;
    rep(i, n){
        if(visited[i]) continue;
        tuple<int, int, int> p = dfs(i);
        int len, sum, mn;
        tie(len, mn, sum) = p;
        dbg(len, mn, sum);
        if(len > 1){
            ans += sum;
            int diff = (len - 2) * mn;
            int d2 = min_ele * (len + 1) + mn;
            dbg(ans, diff, d2);
            diff = min(diff, d2);
            ans += diff;
        }
    }
    cout << "Case " << tc << ": " << ans << endl;
    cout << endl;

    return true;
}

signed main(){
    fastio;

    bool t = true;
    int tc = 1;
    while(t){
        t = solve(tc++);
    }

    return 0;
}
