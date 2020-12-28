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

int n, lg, timer = 0;
vvi g, up;
vi dp, tin, tout, ans;

void dfs(int root, int p){
    tin[root] = timer++;

    up[root][0] = p;
    repA(st, 1, lg){
        up[root][st] = up[up[root][st - 1]][st - 1];
    }

    for(auto child : g[root]){
        if(child == p) continue;
        dfs(child, root);
    }

    tout[root] = timer++;
}

void dfs_ans(int root, int p){
    for(auto child : g[root]){
        if(child == p) continue;
        dfs_ans(child, root);
        dp[root] += dp[child];
    }
    dbg(root, dp[root]);
    ans[root] = abs(dp[root]);
}

inline bool is_ancestor(int child, int anc){
    return (tin[anc] <= tin[child] && tout[child] <= tout[anc]);
}

int query(int u, int v){
    if(is_ancestor(v, u)) return u;
    if(is_ancestor(u, v)) return v;

    int tv = v;
    repD(st, lg, 0){
        if(!is_ancestor(u, up[tv][st])) tv = up[tv][st];
    }

    return up[tv][0];
}

void solve(){
    int q;
    cin >> n >> q;
    lg = 63 - __builtin_clzll(n);

    g.rsz(n);
    up.rsz(n, vi(lg + 1));
    tin.rsz(n), tout.rsz(n);
    dp.rsz(n);
    ans.rsz(n);

    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(0, 0);

    rep(i, q){
        int u, v;
        cin >> u >> v;
        u--; v--;
        int anc = query(u, v);

        dp[u]++, dp[v]++, dp[anc]--;
        if(up[anc][0] != anc)
            dp[up[anc][0]]--;
    }
    dbg(dp);

    dfs_ans(0, 0);

    rep(i, n)
        cout << ans[i] << spc;

}

signed main(){
    fastio;

    solve();

    return 0;
}
