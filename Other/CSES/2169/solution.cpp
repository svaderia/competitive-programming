// clang-format off
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
    OrderedSet; // order_of_key find_by_order

void solve() {
    int n;
    cin >> n;

    map<pii, int> mp;
    vii a(n);
    rep(i, n) {
        cin >> a[i].f >> a[i].s;
        mp[a[i]] = i;
    }

    auto comp = [&](pii x, pii y) {
        if (x.f == y.f)
            return x.s > y.s;
        return x.f < y.f;
    };

    sort(all(a), comp);

    OrderedSet s;

    vi ans(n);

    rep(i, n) {
        int end = a[i].s;
        ans[mp[a[i]]] = sz(s) - (int)s.order_of_key(end);
        s.insert(end);
    }

    vi rans(n);

    reverse(all(a));

    OrderedSet rs;

    rep(i, n) {
        int end = a[i].s;

        rans[mp[a[i]]] = (int)rs.order_of_key(end + 1);
        rs.insert(end);
    }

    rep(i, n) {
        cout << rans[i] << spc;
    }
    cout << endl;
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

