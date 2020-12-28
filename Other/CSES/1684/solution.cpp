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

    Graph() : n(0), m(0), adj(0) {}
    Graph(int nn) : n(nn), m(0), adj(nn) {}

    void add(int u, int v, bool directed = false, int w = 0){
        adj[u].pb(edge(v, w, m));
        if(!directed)
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

int n, m;
Graph g;

int neg(int a){
    return (a < m) ? a + m : a - m;
}

void add_impl(int a, int b){
    g.add(a, b, true);
}

void add_or(int a, int b){
    add_impl(neg(a), b);
    add_impl(neg(b), a);
}

void solve(){
    cin >> n >> m;

    g = Graph(2 * m);
    rep(i, n){
        char aa, bb;
        int a, b;
        cin >> aa >> a >> bb >> b;
        a--, b--;
        if(aa != '+') a = neg(a);
        if(bb != '+') b = neg(b);
        add_or(a, b);
    }

    Tarjan scc(g);

    bool possible = true;;
    vi ans(m, -1);
    rep(i, m){
        if(scc.id[i] == scc.id[i + m])
            possible = false;
        ans[i] = scc.id[i] < scc.id[i + m];
    }

    if(possible){
        for(auto x : ans)
            cout << (x ? "+" : "-") << spc;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
