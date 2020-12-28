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
// To enable recursive lambda
// refere : http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

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
    int n, m;
    cin >> n >> m;

    int source = 0, sink = n - 1;

    Graph g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        g.addEdge(a - 1, b - 1, 1);
    }

    Maxflow mflow(n, source, sink, g);

    int totFlow = mflow.solve();

    vi st;
    auto pdfs = y_combinator([&](auto printDfs, int root, int d) -> bool {
        st.pb(root);
        if(root == sink){
            cout << d + 1 << endl;
            for(auto x : st) cout << x + 1 << spc;
            cout << endl;
            st.clear();
            return true;
        }
        for(auto id : g.adj[root]){
            Edge &e = g.edges[id];
            if(e.flow > 0){
                bool can = printDfs(e.to, d + 1);
                if(can){
                    e.flow = 0;
                    return true;
                }
            }
        }
        return false;
    });

    cout << totFlow << endl;
    rep(i, totFlow){
        pdfs(source, 0);
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
