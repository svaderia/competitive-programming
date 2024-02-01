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

    UnionFind(int a) : n(a), set_size(n), parent(n), rank(n, 1) {
        rep(i, n) parent[i]=i;
    }

    int find(int x) {
        if (x != parent[x]) return parent[x] = find(parent[x]);
        return x;
    }

    bool merge(int x, int y) {
        int xroot = find(x), yroot = find(y);
        if(xroot == yroot) return false;
        if (rank[xroot] < rank[yroot]) swap(xroot, yroot);
        parent[yroot] = xroot;
        rank[xroot] += rank[yroot];
        set_size -= 1;
        return true;
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    int size() { return set_size; }
};

int n, d;

int value(vi point, int mask){
    int temp = 0;
    rep(i, d){
        if(mask & (1 << i)) temp += point[i];
        else temp -= point[i];
    }
    return temp;
}

void solve(){

    cin >> n >> d;

    vii pq(1<<d, mp(-INF, 0));

    vvi points(n, vi(d));
    rep(i, n){
        rep(j, d){
            cin >> points[i][j];
        }
        rep(mask, 1 << d){
            int val = value(points[i], mask);
            if(pq[mask].f < val){
                pq[mask] = {val, i};
            }
        }
    }

    vector<pair<int, pii>> edges;
    rep(i, n){
        rep(mask, 1 << d){
            int val = value(points[i], mask);

            int top_w = pq[mask].f, v = pq[mask].s;

            edges.eb(mp(abs(top_w - val), mp(i, v)));
        }
    }

    sort(rall(edges));

    int ans = 0;

    UnionFind dsu(n);
    for(auto e : edges){
        int w = e.f, u = e.s.f, v = e.s.s;
        if(!dsu.same(u, v)){
            ans += w;
            dsu.merge(u, v);
        }
    }

    cout << ans << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
