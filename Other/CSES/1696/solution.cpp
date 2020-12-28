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

struct Edge{
    int to, cap, flow, id;
    Edge(int ii, int ww, int idx) : to(ii), cap(ww), flow(0), id(idx) {}
};

struct Graph{
    int n, m;
    vector<Edge> edges;
    vvi adj;

    Graph() : n(0), m(0), adj(0) {}
    Graph(int nn) : n(nn), m(0), adj(nn) {}

    void addEdge(int u, int v, int w){
        edges.pb(Edge(v, w, m));
        adj[u].pb(m);
        edges.pb(Edge(u, 0, m + 1));
        adj[v].pb(m + 1);
        m += 2;
    }

    void augment(int id, int flow){
        edges[id].flow += flow;
        edges[id ^ 1].flow -= flow;
    }
};

struct Maxflow{
    int n, s, t;
    Graph &g;
    vi level, next;

    Maxflow(int nn, int ss, int tt, Graph &gg) : n(nn), s(ss), t(tt), g(gg), level(n, -1) {}

    int solve(){
        int flow = 0;
        while(bfs()){
            next.clear(), next.rsz(n, 0);
            for(int f = dfs(s, INF); f != 0; f = dfs(s, INF)){
                flow += f;
            }
        }

        return flow;
    }

    bool bfs(){
        level.clear(), level.rsz(n, -1);
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while(!q.empty()){
            int root = q.front();
            q.pop();
            for(auto id : g.adj[root]){
                int v = g.edges[id].to;
                int cap = g.edges[id].cap - g.edges[id].flow;
                if(level[v] == -1 && cap > 0){
                    level[v] = level[root] + 1;
                    q.push(v);
                }
            }
        }

        return level[t] != -1;
    }

    int dfs(int root, int flow){
        if(root == t) return flow;
        int totalEdges = sz(g.adj[root]);

        for(int &cid = next[root]; cid < totalEdges; cid++){
            int id = g.adj[root][cid];
            Edge &e = g.edges[id];
            int v = e.to;
            int cap = e.cap - e.flow;
            if(level[v] > level[root] && cap > 0){
                int blocking = dfs(v, min(cap, flow));

                if(blocking > 0){
                    g.augment(id, blocking);
                    return blocking;
                }
            }
        }
        return 0;
    }
};

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    Graph g(n + m + 2);
    int source = 0, sink = n + m + 1;

    // middle edges;
    rep(i, k){
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b + n, 1);
    }

    // source edges
    repA(i, 1, n)
        g.addEdge(source, i, 1);

    // sink edges
    repA(i, 1, m)
        g.addEdge(i + n, sink, 1);

    Maxflow mflow(n + m + 2, source, sink, g);

    cout << mflow.solve() << endl;

    repA(u, 1, n){
        /* if(mflow.level[u] == -1) continue; */
        for(auto id : g.adj[u]){
            Edge e = g.edges[id];
            int v = e.to;
            /* dbg(u, v, mflow.level[v], e.cap, e.flow); */
            if(e.flow > 0){
                cout << u << spc << v - n << endl;
            }
        }
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
