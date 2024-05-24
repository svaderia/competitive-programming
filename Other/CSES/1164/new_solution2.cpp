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

    vector<pair<pair<int, int>, int>> a(n);
    rep(i, n) {
        cin >> a[i].f.s >> a[i].f.f;
        a[i].s = i;
    }

    sort(all(a));

    multiset<pair<int, int>> e;
    vi ans(n, INF);

    rep(i, n) {
        int start = a[i].f.s, end = a[i].f.f;
        int idx = a[i].s;

        auto it = e.lower_bound(mp(start, 0));
        if (it == e.begin()) {
            int nk = sz(e) + 1;
            e.insert(mp(end, nk));
            ans[idx] = nk;
        } else {
            it--;
            e.erase(it);
            e.insert(mp(end, (*it).s));
            ans[idx] = (*it).s;
        }
    }

    cout << sz(e) << endl;

    rep(i, n) {
        cout << ans[i] << spc;
    }
    cout << endl;
}

signed main() {
    fastio;

    solve();

    return 0;
}
