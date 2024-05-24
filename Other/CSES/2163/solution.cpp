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
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }
// clang-format on
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
    OrderedSet; // order_of_key find_by_order

void solve() {
    int n, k;
    cin >> n >> k;
    k++;

    vi ans;
    OrderedSet st;

    rep(i, n) {
        st.insert(i + 1);
    }

    int a = (k - 1) % sz(st);
    while (sz(st) > 0) {
        auto it = st.find_by_order(a + 1);
        it--;
        ans.pb(*it);
        st.erase(it);
        if(sz(st) > 0){
            a += (k - 1) % sz(st);
        }
        if (a >= sz(st) && sz(st) != 0) {
            a -= sz(st);
        }
    }

    for (auto x : ans) {
        cout << x << spc;
    }
    cout << endl;
}

signed main() {
    fastio;

    solve();

    return 0;
}
