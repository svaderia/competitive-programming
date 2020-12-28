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

int n, lg, timer = 0;
vvi g, up;
vi h, tin, tout;

void dfs(int root, int p){
    h[root] = 1 + h[p];

    tin[root] = timer++;

    up[root][0] = p;
    repA(st, 1, lg){
        up[root][st] = up[up[root][st - 1]][st - 1];
    }

    for(auto child : g[root]){
        if(child == p) continue;
        dfs(child, root);
    }

    tout[root] = timer++;
}

inline bool is_ancestor(int child, int anc){
    return (tin[anc] <= tin[child] && tout[child] <= tout[anc]);
}

int query(int u, int v){
    if(is_ancestor(v, u)) return u;
    if(is_ancestor(u, v)) return v;

    int tv = v;
    repD(st, lg, 0){
        if(!is_ancestor(u, up[tv][st])) tv = up[tv][st];
    }

    return up[tv][0];
}

void solve(){
    int q;
    cin >> n >> q;
    lg = 63 - __builtin_clzll(n);

    g.rsz(n);
    up.rsz(n, vi(lg + 1));
    tin.rsz(n), tout.rsz(n);
    h.rsz(n);

    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(0, 0);

    rep(i, q){
        int u, v;
        cin >> u >> v;
        u--; v--;
        int anc = query(u, v);
        cout << h[u] + h[v] - 2 * h[anc] << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
