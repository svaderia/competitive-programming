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
    ~UnionFind() {
        delete rank;
        delete parent;
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

void solve(){

    int n, m;
    cin >> n >> m;

    vector<vii> g(n);
    priority_queue<pair<int, pii> > edges;
    rep(i, m){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
        edges.push(mp(-w, mp(u, v)));
    }

    vi dist(n, INF);
    dist[0] = 0;
    priority_queue<pii> pq;
    pq.push(mp(0, 0));
    vi last(n, INF);
    last[0] = 0;
    vb used(n);

    while(!pq.empty()){
        int d = -pq.top().f, node = pq.top().s;
        pq.pop();
        if(used[node]) continue;
        used[node] = true;
        for(auto e : g[node]){
            int nnode = e.f, w = e.s;
            if(d + w <= dist[nnode]){
                dist[nnode] = d + w;
                last[nnode] = min(w, last[nnode]);
                pq.push(mp(-dist[nnode], nnode));
            }
        }
    }
    bool ans = true;
    int sst = 0;
    rep(i, n){
        if(last[i] == INF) ans = false;
        sst += last[i];
    }

    UnionFind dsu = UnionFind(n);

    int mst = 0;
    while(!edges.empty()){
        int w = -edges.top().f, u = edges.top().s.f, v = edges.top().s.s;
        edges.pop();
        u++; v++;
        if(dsu.find(u) == dsu.find(v)) continue;
        mst += w;
        dsu.unite(u, v);
    }

    if(sst != mst){
        ans = false;
    }

    cout << (ans ? "YES" : "NO" )<< endl;

}

signed main(){
    fastio;

    int T;
    cin >> T;

    repA(tc, 1, T){
        solve();
    }

    return 0;
}
