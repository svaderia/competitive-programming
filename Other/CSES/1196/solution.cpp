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

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    Graph g(n);
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        g.add(a - 1, b - 1, true, c);
    }

    priority_queue<pii> pq;

    vvi dp(n, vi(k, INF));
    dp[0][0] = 0;

    pq.push(mp(0, 0));

    while(!pq.empty()){
        int d = -pq.top().f;
        int root = pq.top().s;
        pq.pop();

        if(dp[root][k - 1] < d) continue;
        for(auto e : g.adj[root]){
            int child = e.to;
            if(dp[child][k - 1] > e.w + d){
                dp[child][k - 1] = e.w + d;
                pq.push(mp(-dp[child][k - 1], child));
                sort(all(dp[child]));
            }
        }
    }

    rep(i, k){
        cout << dp[n - 1][i] << spc;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
