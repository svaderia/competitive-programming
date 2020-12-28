// Very long code, checkout solution on USACO Training website
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

int n, lg, timer = 0;
vvi g, up;
vi h;

void dfs(int root, int p, int hh){
    h[root] = hh;

    up[root][0] = p;
    repA(st, 1, lg){
        up[root][st] = up[up[root][st - 1]][st - 1];
    }

    for(auto child : g[root]){
        if(child == p) continue;
        dfs(child, root, hh + 1);
    }

}

int get_par(int v, int dd){
    if(dd == 0) return v;
    dd--;
    int tv = v;
    repD(st, lg, 0){
        if(dd & (1 << st)) tv = up[tv][st];
    }

    return up[tv][0];
}

void solve(){
    int q;
    cin >> n >> q;

    lg = 63 - __builtin_clzll(n);
    g.rsz(n), up.rsz(n, vi(lg + 1)), h.rsz(n);

    vi par(n);
    rep(i, n){
        cin >> par[i];
        par[i]--;
    }

    vi visited(n, 0), cycle(n, -1), cids(n, -1), cycle_len;
    int cnum = 0;
    int id = n + 1;

    auto find_cycle = y_combinator([&] (auto ddfs, int root) -> void {
        visited[root] = 1;
        if(visited[par[root]] == 1){
            int start = par[root];
            cycle[root] = cnum;
            int l = 1;
            cids[root] = id++;
            while(start != root){
                cids[start] = id++;
                cycle[start] = cnum;
                start = par[start];
                l++;
            }
            cnum++;
            cycle_len.pb(l);
        } else if(visited[par[root]] == 0){
            ddfs(par[root]);
        }
        visited[root] = 2;
    });

    rep(i, n)
        if(visited[i] == 0) find_cycle(i);

    vi ids(n, -1);
    auto prepare = y_combinator([&] (auto ddfs, int root) -> void {
        int p = par[root];

        if(cycle[root] == -1){
            g[p].pb(root);
        } else {
            ids[root] = root;
            return;
        }

        if(cycle[p] != -1){
            if(cycle[root] == -1)
                ids[root] = p;
            return;
        }
        if(ids[p] == -1){
            ddfs(p);
        }
        ids[root] = ids[p];
    });

    rep(i, n)
        if(ids[i] == -1) prepare(i);

    rep(i, n)
        if(cycle[i] != -1) dfs(i, i, 0);

    rep(i, q){
        int a, b;
        cin >> a >> b;
        a--, b--;

        if(cycle[a] != -1){
            if(cycle[b] != -1){
                if(cycle[a] != cycle[b]) cout << -1 << endl;
                else cout << (cids[b] - cids[a] + cycle_len[cycle[a]]) % cycle_len[cycle[a]] << endl;
            }else{
                cout << -1 << endl;
            }
        }else{
            if(cycle[b] != -1){
                int pa = get_par(a, h[a]);
                if(cycle[pa] == cycle[b]){
                    cout << h[a] + (cids[b] - cids[pa] + cycle_len[cycle[b]]) % cycle_len[cycle[b]] << endl;
                }else{
                    cout << -1 << endl;
                }
            }else{
                if(ids[a] == ids[b]){
                    if(get_par(a, h[a] - h[b]) == b) cout << h[a] - h[b] << endl;
                    else cout << -1 << endl;
                }else {
                    cout << -1 << endl;
                }
            }
        }

    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
