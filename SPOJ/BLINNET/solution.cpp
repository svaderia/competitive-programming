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

void solve(){

    int n;
    cin >> n;

    vector<pair<int, pii> > roads;

    rep(u, n){
        string s;
        cin >> s;
        int p;
        cin >> p;
        rep(i, p){
            int v, c;
            cin >> v >> c;
            v--;
            roads.pb({c, {u, v}});
        }
    }

    sort(all(roads));

    UnionFind dsu(n);

    int mst = 0;
    for(auto e : roads){
        int c = e.f, u = e.s.f, v = e.s.s;
        if(!dsu.connected(u, v)){
            mst += c;
            dsu.unite(u, v);
        }
    }

    cout << mst << endl;

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
