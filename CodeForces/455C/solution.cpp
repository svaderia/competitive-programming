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
//Class to implement union find using path compression
//1-based indexing assumed

class UnionFind {
private:
    int n, set_size, *parent, *rank;
public:
    //Complexity: O(n)
    UnionFind(int a) {
        n = set_size = a;
        parent = new int[n+1];
        rank = new int[n+1];
        for(int i = 1; i <= n; ++i) parent[i]=i, rank[i]=1;
    }
        //Path Compression
    int find(int x) {
        if (x != parent[x]) return parent[x] = find(parent[x]);
        return x;
    }
    //Complexity : O(A N), where A = Inverse Ackermann function
    void unite(int x, int y) {
        int xroot = find(x), yroot = find(y);
        if (xroot != yroot) {
            if (rank[xroot] >= rank[yroot]) {
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
            }
            else {
                parent[xroot] = yroot;
                rank[yroot] += rank[xroot];
            }
            set_size -= 1;
        }
    }
    int size() { return set_size; }
    void print() {
        for(int i = 1; i <= n; ++i)
            cout << i << " -> " << parent[i] << "\n";
    }
};
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

int dia;
vvi g;
vi visited;

int dfs(int root, int par, UnionFind &dsu){

    visited[root] = true;
    dsu.unite(root, par);
    int m1 = 0, m2 = 0;

    for(auto child: g[root]){
        if(child != par){
            int t = dfs(child, root, dsu);
            if(t >= m1){
                m2 = m1;
                m1 = t;
            }else if(t > m2){
                m2 = t;
            }
        }
        dia = max(dia, 1 + m1 + m2);
    }

    return 1 + max(m1, m2);
}

void solve(){

    int n, m, q;
    cin >> n >> m >> q;

    UnionFind dsu = UnionFind(n);
    g.rsz(n + 1); visited.rsz(n + 1);

    rep(i, m){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    vi diam(n + 1, 0);

    repA(i, 1, n){
        if(!visited[i]){
            dia = 1;
            dfs(i, i, dsu);
            diam[dsu.find(i)] = dia - 1;
        }
    }

    rep(i, q){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            dbg(dsu.find(x));
            dbg(diam);
            cout << diam[dsu.find(x)] << endl;
        }else{
            int x, y;
            cin >> x >> y;
            int p1 = dsu.find(x), p2 = dsu.find(y);
            if(p1 != p2){
                dsu.unite(x, y);
                int p = dsu.find(x);
                diam[p] = max({diam[p1], diam[p2], 1 + (diam[p1] + 1) / 2 + (diam[p2] + 1) / 2});
            }
        }
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
