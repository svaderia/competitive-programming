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

    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vi where(n + 2, INF);
    where[n + 1] = 0;
    rep(i, n) {
        where[a[i]] = i;
    }

    int ans = 0;
    repA(i, 1, n) {
        if (where[i - 1] > where[i]) {
            ans++;
        }
    }

    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        int n1 = a[x], n2 = a[y];

        set<int> affected;
        affected.insert(n1);
        affected.insert(n1 + 1);
        affected.insert(n2);
        affected.insert(n2 + 1);

        int curr = 0;
        for (auto k : affected) {
            if (k == 0 || k == n + 1) {
                continue;
            }

            if (where[k - 1] > where[k]) {
                curr++;
            }
        }
        /* cout << curr << endl; */

        where[n1] = y, where[n2] = x;
        a[y] = n1, a[x] = n2;
        for (auto k : affected) {
            if (k == 0 || k == n + 1) {
                continue;
            }
            /* cout << k << spc << where[k] << endl; */
            /* cout << k - 1<< spc << where[k- 1] << endl; */
            if (where[k - 1] > where[k]) {
                curr--;
            }
        }

        ans -= curr;
        /* cout << curr << spc << ans << endl; */
        cout << ans << endl;
        /* where[n1] = x, where[n2] = y; */
        /* cout << endl; */
    }
}

signed main() {
    fastio;

    solve();

    return 0;
}
