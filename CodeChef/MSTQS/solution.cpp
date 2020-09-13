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

// 0-based indexing assumed

struct UnionFind {
    int n, set_size;
    vi parent, rank;

    UnionFind(int a) : n(a), set_size(n), parent(n), rank(n) {
        rep(i, n) parent[i]=i, rank[i]=1;
    }

    int find(int x) {
        if (x != parent[x]) return parent[x] = find(parent[x]);
        return x;
    }

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

    bool connected(int x, int y){
        return find(x) == find(y);
    }

    int size() { return set_size; }
};

vvi tg;
map<pii, int> dist;
map<pii, int> active;
map<pii, int> tdist;
int init;
pii which_to_remove;

void getRemoval(int root, int p, vii &temp){

    for(auto child : tg[root]){
        if(child != p){
            temp.pb(mp(min(child, root), max(child, root)));
            if(child == init){
                int tmx = -1;
                for(auto e : temp){
                    if(tdist[e] > tmx){
                        tmx = tdist[e];
                        which_to_remove = e;
                    }
                }
                return;
            }
            getRemoval(child, root, temp);
            temp.pop_back();
        }
    }
}

void dfs(int root, int p, vb &visited){
    visited[root] = true;
    for(auto child : tg[root]){
        if(child != p){
            dfs(child, root, visited);
        }
    }
}

void solve(){

    int n, m, q;
    cin >> n >> m >> q;

    vector<pair<int, pii> > edges;
    tg.rsz(n);

    rep(i, m){
        int u, v, c;
        cin >> u >> v >> c;
        u--, v--;
        edges.eb(mp(c, mp(u, v)));
        dist[mp(min(u, v), max(u, v))] = c;
        active[mp(min(u, v), max(u, v))] = c;
    }

    sort(all(edges));
    UnionFind dsu(n);

    int mst = 0;

    for(auto e : edges){
        int c = e.f, u = e.s.f, v = e.s.s;
        if(!dsu.connected(u, v)){
            tg[u].pb(v);
            tg[v].pb(u);
            tdist[mp(min(u, v), max(u, v))] = c;
            dsu.unite(u, v);
            mst += c;
        }
    }

    set<pii> removed;

    rep(i, q){
        int type;
        cin >> type;
        if(type == 1){
            int u, v;
            cin >> u >> v;
            u--, v--;
            if(u > v) swap(u, v);
            if(active[mp(u, v)] == 0) continue;
            if(present(tdist, mp(u, v))){
                removed.insert(mp(u, v));
                mst -= tdist[mp(u, v)];
                tdist[mp(u, v)] = 0;
            }else{
                tdist[mp(u, v)] = 0;
                tg[u].pb(v);
                tg[v].pb(u);
                init = u;
                vii temp;
                getRemoval(u, u, temp);
                removed.insert(which_to_remove);
                mst -= tdist[which_to_remove];
                tdist.erase(which_to_remove);
                int x = which_to_remove.f, y = which_to_remove.s;
                tg[x].erase(find(all(tg[x]), y));
                tg[y].erase(find(all(tg[y]), x));
            }
            active[mp(u, v)] = 0;
        } else if(type == 2){
            int u, v;
            cin >> u >> v;
            u--, v--;
            if(u > v) swap(u, v);
            if(active[mp(u, v)] == dist[mp(u, v)]) continue;
            active[mp(u, v)] = dist[mp(u, v)];

            if(present(tdist, mp(u, v)) && tdist[mp(u, v)] == 0){
                tdist.erase(mp(u, v));
                tg[u].erase(find(all(tg[u]), v));
                tg[v].erase(find(all(tg[v]), u));

                vb visited(n, false);
                dfs(v, u, visited);

                pii addTo = {u, v};
                int mx = active[{u, v}];

                for(auto e : removed){
                    if(visited[e.f] != visited[e.s]){
                        if(mx > active[e]){
                            mx = active[e];
                            addTo = e;
                        }
                    }
                }

                int x = addTo.f, y = addTo.s;

                tg[x].pb(y);
                tg[y].pb(x);
                tdist[addTo] = active[addTo];
                mst += tdist[addTo];
            }
        }else{
            cout << mst << endl;
        }

    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
