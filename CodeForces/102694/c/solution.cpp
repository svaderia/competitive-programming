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

vvi g, up;
vi tin, tout, level;
int timer;
int lg;

void dfs(int root, int p, int depth){
    tin[root] = timer++;

    up[root][0] = p;
    repA(st, 1, lg){
        up[root][st] = up[up[root][st - 1]][st - 1];
    }

    level[root] = depth;

    for(auto child : g[root]){
        if(child != p){
            dfs(child, root, depth + 1);
        }
    }

    tout[root] = timer++;
}

bool isAncestor(int u, int p){
    return (tin[p] <= tin[u] && tout[u] <= tout[p]);
}

int findAncestor(int u, int v){
    if(isAncestor(u, v)) return v;
    if(isAncestor(v, u)) return u;

    int tv = v;
    repD(st, lg, 0){
        if(!isAncestor(u, up[tv][st])){
            tv = up[tv][st];
        }
    }

    return up[tv][0];
}

int findAtLevel(int u, int lev){
    int tu = u;

    repD(st, lg, 0){
        if(level[up[tu][st]] > lev){
            tu = up[tu][st];
            dbg(tu, level[tu]);
        }
    }

    return up[tu][0];
}

int findKth(int u, int v, int k){
    int anc = findAncestor(u, v);
    int tot = level[u] + level[v] - 2 * level[anc];
    if(tot <= k) return v;

    int mid = level[u] - level[anc];
    dbg(anc, tot, mid);
    if(k <= mid){
        dbg(u, level[u], level[u] - k);
        return findAtLevel(u, level[u] - k);
    }else{
        int diff = k - mid;
        dbg(u, level[u], diff, level[anc] + diff);
        return findAtLevel(v, level[anc] + diff);
    }
}

void solve(){
    int n;
    cin >> n;

    g.rsz(n); tin.rsz(n); tout.rsz(n); level.rsz(n);

    lg = 63 - __builtin_clzll(n);

    up.rsz(n, vi(lg + 1, 0));

    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    timer = 0;

    dfs(0, 0, 0);

    int q;
    cin >> q;
    rep(i, q){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;

        cout << findKth(a, b, c) + 1 << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}


