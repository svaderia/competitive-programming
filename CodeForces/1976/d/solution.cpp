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
//
// Two observation : 
// for an [l, r] to be an answer, 
//      the prefix sums need to be exactly same.
//      There should not be any element which is greater than 2 * pref[l] between these two points.

// clang-format on

struct sparse_table {

    const int LOG = 20; // should be okay until 10^6 arrays

    int n;
    vector<vector<int>> dp;

    // this is the merge function
    int merge(int a, int b) {
        return max(a, b);
    }

    sparse_table(vector<int> &a) {
        n = sz(a);
        dp.resize(LOG);
        dp[0] = a;

        repA(id, 1, LOG - 1) {
            dp[id].resize(n);
            rep(j, n) {
                dp[id][j] = dp[id - 1][j];
                int next_id = j + (1LL << (id - 1));
                if (next_id < n) {
                    dp[id][j] = merge(dp[id][j], dp[id - 1][next_id]);
                }
            }
        }
    }

    // query of the form [l, r)
    int query(int l, int r) {
        int d = r - l + 1;
        int id = 63 - __builtin_clzll(d);

        int shift = (1LL << id);
        return merge(dp[id][l], dp[id][r - shift + 1]);
    }
};

void solve() {

    string s;
    cin >> s;

    int n = sz(s);

    vvi same(n);
    same[0].pb(0);

    vi pre(n + 1, 0);

    rep(i, n) {
        pre[i + 1] = pre[i] + (s[i] == '(' ? 1 : -1);
        same[pre[i + 1]].pb(i + 1);
    }

    sparse_table st(pre);

    int ans = 0;
    rep(i, n) {
        rep(j, sz(same[i])) {
            int l = j, r = sz(same[i]);
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (st.query(same[i][j], same[i][mid]) > 2 * i) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            l--;
            ans += (l - j);
        }
    }

    cout << ans << endl;
}

signed main() {
    fastio;

    int T;
    cin >> T;

    repA(tc, 1, T) {
        solve();
    }

    return 0;
}
