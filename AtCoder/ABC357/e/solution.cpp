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
    int n;
    cin >> n;

    vi a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }

    vi visited(n, -1);
    vii cycles;
    auto find_cyles = [&](int root, int d, set<int> &curr, auto self) -> void {
        visited[root] = d;

        int e = a[root];

        if (visited[e] != -1) {
            if (present(curr, e)) {
                int total = (d - visited[e]) + 1;
                cycles.pb(mp(root, total));
            }
        } else {
            curr.insert(root);
            self(e, d + 1, curr, self);
        }
    };

    rep(i, n) {
        if (visited[i] < 0) {
            set<int> curr;
            find_cyles(i, 1, curr, find_cyles);
        }
    }

    vi dp(n, -1);

    for (auto y : cycles) {
        int start = y.f, val = y.s;
        while (a[start] != y.f) {
            dp[start] = val;
            start = a[start];
        }
        dp[start] = val;
    }

    auto dfs = [&](int root, auto self) -> int {
        if (dp[root] != -1) {
            return dp[root];
        }
        if (a[root] == root) {
            return 1;
        }

        int ans = 1 + self(a[root], self);

        return dp[root] = ans;
    };

    rep(i, n) {
        dp[i] = dfs(i, dfs);
    }

    int ans = 0;

    for (auto x : dp) {
        ans += x;
    }

    cout << ans << endl;
}

signed main() {
    fastio;

    solve();

    return 0;
}
