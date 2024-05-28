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

// The observation from this comment is helpful : https://codeforces.com/blog/entry/129801?#comment-1152987
// We implemented that here.
void solve() {
    int n, q;
    cin >> n >> q;

    vi c(n + 1, 0);
    rep(i, n) {
        cin >> c[i + 1];
    }

    vvi e(n + 1);
    rep(i, n - 1) {
        int x, y;
        cin >> x >> y;

        e[x].pb(y);
        e[y].pb(x);
    }

    vi parent(n + 1, 0);
    vi depth(n + 1, 0);

    // always put return type when doing self shit
    auto dfs = [&](auto self, int root, int d) -> void {
        depth[root] = d;
        for (int x : e[root]) {
            if (x != parent[root]) {
                parent[x] = root;
                self(self, x, d + 1);
            }
        }
    };

    dfs(dfs, 1, 1);

    vi bchild(n + 1, 0);

    repA(i, 1, n) {
        bchild[parent[i]] += c[i];
    }

    int num_leaf = 0;

    // stores depth, id
    set<pair<int, int>> st;

    rep(i, n + 1) {
        if (c[i]) {
            if (bchild[i] == 0) {
                num_leaf++;
            }
            st.insert(mp(depth[i], i));
        }
    }

    rep(i, q) {
        int v;
        cin >> v;

        c[v] ^= 1;

        bchild[parent[v]] += (c[v] == 0) ? -1 : 1;

        if (c[v] == 0) {
            if (bchild[v] == 0) {
                num_leaf--;
            }

            if (c[parent[v]] == 1 && bchild[parent[v]] == 0) {
                num_leaf++;
            }
            st.erase(mp(depth[v], v));
        } else {
            if (bchild[v] == 0) {
                num_leaf++;
            }

            if (c[parent[v]] == 1 && bchild[parent[v]] == 1) {
                num_leaf--;
            }

            st.insert(mp(depth[v], v));
        }

        if (num_leaf == 1) {
            cout << "YES" << endl;
        } else if (num_leaf == 2) {
            pii high = *st.begin();
            auto it = st.begin()++;
            it++;
            if (high.first != (*it).first && bchild[high.second] == 2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
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
