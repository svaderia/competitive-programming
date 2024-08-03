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

    vector<vii> g(n);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        g[a].pb(mp(b, c));
    }

    priority_queue<pair<int, pair<int, int>>> q;

    vvi dp(n, vi(2, INF));
    vector<vb> visited(n, vb(2));

    dp[0][0] = 0;
    q.push(mp(0, mp(0, 0)));

    while (!q.empty()) {
        auto r = q.top();
        q.pop();
        int root = r.s.f, dir = r.s.s;

        if (visited[root][dir])
            continue;
        visited[root][dir] = true;

        for (auto e : g[root]) {
            int child = e.f, w = e.s;
            if (dir == 0) { // switch
                if (dp[child][1] > dp[root][0] + w / 2) {
                    dp[child][1] = dp[root][0] + w / 2;
                    q.push(mp(-dp[child][1], mp(child, 1)));
                }
            }
            if (dp[child][dir] > dp[root][dir] + w) {
                dp[child][dir] = dp[root][dir] + w;
                q.push(mp(-dp[child][dir], mp(child, dir)));
            }
        }
    }

    cout << dp[n - 1][1] << endl;
}

signed main() {
    fastio;

    solve();

    return 0;
}
