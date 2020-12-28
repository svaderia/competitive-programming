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

struct edge{
    int to, w, id;
    edge(int ii, int ww, int idx) : to(ii), w(ww), id(idx) {}
};

struct Graph{
    int n, m;
    vector<vector<edge>> adj;

    Graph() {}
    Graph(int nn) : n(nn), m(0), adj(nn) {}

    void add(int u, int v, bool undirected = true, int w = 0){
        u--, v--;
        adj[u].pb(edge(v, w, m));
        if(undirected)
            adj[v].pb(edge(u, w, m));
        m++;
    }
};

struct Tarjan{
    Graph g;
    vi pre, low, id;
    int numSCCs, preCounter;
    stack<int> stk;

    Tarjan(Graph gg) : g(gg), pre(g.n, -1), low(g.n), id(g.n), numSCCs(0), preCounter(0) {
        rep(i, g.n)
            if(pre[i] == -1)
                dfs(i);
    };

    void dfs(int root){
        pre[root] = low[root] = preCounter++;
        stk.push(root);

        for(auto edge : g.adj[root]){
            int child = edge.to;
            if(pre[child] == -1)
                dfs(child);

            low[root] = min(low[root], low[child]);
        }

        if(pre[root] == low[root]){
            while(true){
                int top = stk.top(); stk.pop();
                id[top] = numSCCs;
                low[top] = INF;

                if(top == root) break;
            }
            numSCCs++;
        }
    }
};

void solve(){

    int n, m;
    cin >> n >> m;

    vi k(n);
    rep(i, n){
        cin >> k[i];
    }

    Graph g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        g.add(a, b, false);
    }

    Tarjan scc(g);

    vi fk(scc.numSCCs);
    rep(i, n){
        fk[scc.id[i]] += k[i];
    }

    Graph g2(scc.numSCCs);
    rep(i, n){
        for(auto e : g.adj[i]){
            if(scc.id[e.to] != scc.id[i]){
                g2.add(scc.id[i] + 1, scc.id[e.to] + 1, false);
            }
        }
    }

    int ans = 0;
    rep(i, scc.numSCCs){
        int mx = 0;
        for(auto e : g2.adj[i]){
            mx = max(mx, fk[e.to]);
        }
        fk[i] += mx;
        ans = max(ans, fk[i]);
    }

    cout << ans << endl;
}

signed main(){
    fastio;

    solve();

    return 0;
}
