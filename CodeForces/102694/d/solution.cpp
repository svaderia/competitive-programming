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

int timer, lg;
vvi g, up, mn;
vi tin, tout;
map<pii, int> dist;

void dfs(int root, int p){
    tin[root] = timer++;
    dbg(root, p);

    dbg( lg);
    up[root][0] = p;
    mn[root][0] = dist[{root, p}];
    dbg( lg);
    repA(step, 1, lg){
        dbg(step, lg);
        mn[root][step] = min(mn[root][step - 1], mn[up[root][step - 1]][step - 1]);
        up[root][step] = up[up[root][step - 1]][step - 1];
    }

    for(auto child : g[root]){
        if(child != p){
            dfs(child, root);
        }
    }

    tout[root] = timer++;
}

bool isAncestor(int u, int p){
    return (tin[p] <= tin[u] && tout[u] <= tout[p]);
}

int query(int u, int v){

    int tu = u, tv = v;

    int ans = INF;
    if(!isAncestor(u, v)){
        repD(st, lg, 0){
            if(!isAncestor(u, up[tv][st])){
                ans = min(ans, mn[tv][st]);
                tv = up[tv][st];
            }
        }
        ans = min(ans, mn[tv][0]);
    }
    if(!isAncestor(v, u)){
        repD(st, lg, 0){
            if(!isAncestor(v, up[tu][st])){
                ans = min(ans, mn[tu][st]);
                tu = up[tu][st];
            }
        }
        ans = min(ans, mn[tu][0]);
    }
    return ans;
}

void solve(){

    int n, m;
    cin >> n >> m;
    g.rsz(n); tin.rsz(n); tout.rsz(n); timer = 0;
    lg = 63 - __builtin_clzll(n);
    mn.rsz(n, vi(lg + 1));
    up.rsz(n, vi(lg + 1));

    rep(i, m){
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
        dist[{a, b}] = w;
        dist[{b, a}] = w;
    }
    rep(a, n){
        dist[{a, a}] = INF;
    }

    dfs(0, 0);

    int q;
    cin >> q;
    rep(i, q){
        int u, v;
        cin >> u >> v;
        u--; v--;
        cout << query(u, v) << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
