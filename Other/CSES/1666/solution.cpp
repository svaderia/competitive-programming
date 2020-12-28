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

void solve(){
    int n, m;
    cin >> n >> m;

    UnionFind dsu(n);

    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        dsu.merge(a, b);
    }

    vi ans;
    rep(i, n){
        if(dsu.find(i) == i) ans.pb(i + 1);
    }

    int sans = sz(ans);
    sans--;
    cout << sans << endl;

    rep(i, sans){
        cout << ans[0] << spc << ans[i + 1] << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
