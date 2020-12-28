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

    Graph g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        g.add(a, b, false);
    }

    Tarjan scc(g);

    if(scc.numSCCs == 1){
        cout << "YES" << endl;
    }else{
        int z = 0, o = 0;
        rep(i, n){
            if(scc.id[i] == 0) z = i;
            if(scc.id[i] == scc.numSCCs - 1) o = i;
        }
        cout << "NO" << endl;
        cout << z + 1 << spc << o + 1 << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
