// clang-format off
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
// Remove this when it's an interactive problem
#define endl "\n"
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

struct dsu {
    vi p;

    dsu(int _n) {
        p.rsz(_n, -1);
    }

    int find(int x) {
        return p[x] < 0 ? x : p[x] = find(p[x]);
    }

    int sameSet(int x, int y) {
        return find(x) == find(y);
    }
    
    int size(int x){
        return -p[find(x)];
    }

    int unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return 0;

        if (p[y] > p[x]) swap(x, y);

        p[y] += p[x]; p[x] = y;
        return 1;
    }
};

// clang-format on
void solve() {
    int n, m;
    cin >> n >> m;

    dsu d(n);

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        d.unite(a, b);
    }

    vi ans;
    rep(i, n) {
        if (d.p[i] < 0) {
            ans.pb(i + 1);
        }
    }

    cout << sz(ans) - 1 << endl;
    rep(i, sz(ans) - 1) {
        cout << ans[i] << spc << ans[i + 1] << endl;
    }
}

signed main() {
    fastio;

    solve();

    return 0;
}
