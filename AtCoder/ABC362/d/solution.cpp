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

// clang-format on
void solve() {
    int n, m;
    cin >> n >> m;

    int N = 2 * n;

    vector<vii> g(N);

    vi d(n);
    rep(i, n){
        cin >> d[i];
    }

    rep(i, m) {
        int l, r, w;
        cin >> l >> r >> w;
        l--, r--;
        g[l].pb(mp(r, w));
        g[r].pb(mp(l, w));
    }

    int v = 0;
    priority_queue<pair<int, int>> q;
    vector<int> dist(n, INF);
    vector<bool> visited(n);

    dist[v] = d[v];
    q.push(make_pair(dist[v], v));

    while (!q.empty()) {
        int root = q.top().second;
        q.pop();
        if (visited[root])
            continue;
        visited[root] = true;

        for (auto e : g[root]) {
            int child = e.first, w = e.second;

            if (dist[child] > dist[root] + w + d[child]) {
                dist[child] = dist[root] + w + d[child];
                q.push(make_pair(-dist[child], child));
            }
        }
    }

    repA(i, 1, n - 1) {
        cout << dist[i] << spc;
    }
}

signed main() {
    fastio;

    solve();

    return 0;
}
