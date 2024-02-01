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

struct Edge{
    int to, w, id;
    Edge(int ii, int ww, int idx) : to(ii), w(ww), id(idx) {}
};

struct Graph{
    int n, m;
    vector<vector<Edge>> adj;

    Graph() : n(0), m(0), adj(0) {}
    Graph(int nn) : n(nn), m(0), adj(nn) {}

    void addEdge(int u, int v, bool directed = false, int w = 0){
        adj[u].pb(Edge(v, w, m));
        if(!directed)
            adj[v].pb(Edge(u, w, m));
        m++;
    }
};

const int MAXK = 500;
Graph g;
vvi dp;
int n, m, c;
vi k;

void self_max(int &a, int b){
    a = max(a, b);
}

void solve(){
    cin >> n >> m >> c;

    k.rsz(n);
    rep(i, n){
        cin >> k[i];
    }

    g = Graph(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        g.addEdge(a - 1, b - 1, true);
    }

    dp.rsz(n, vi(MAXK + 1, -INF));
    dp[0][0] = 0;

    repA(t, 1, MAXK){
        rep(root, n){
            for(auto e : g.adj[root]){
                self_max(dp[e.to][t], k[e.to] + dp[root][t - 1] - c * (2 * t - 1));
            }
        }
    }

    int ans = 0;
    rep(t, MAXK + 1)
        self_max(ans, dp[0][t]);

    cout << ans << endl;

}

signed main(){
#ifndef DEBUG
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
#endif

    fastio;

    solve();

    return 0;
}
