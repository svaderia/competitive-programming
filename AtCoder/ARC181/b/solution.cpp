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
    string s, x, y;
    cin >> s >> x >> y;

    int n = sz(s);

    if (sz(x) > sz(y)) {
        swap(x, y);
    }

    vi xx(2), yy(2);
    for (auto c : x) {
        xx[c - '0']++;
    }
    for (auto c : y) {
        yy[c - '0']++;
    }

    // total s are equal, then replace t with s
    if (xx[0] == yy[0]) {
        cout << "Yes" << endl;
        return;
    }

    // sizes equal, replace t with s
    if (sz(x) == sz(y)) {
        cout << "Yes" << endl;
        return;
    }

    // total s are not equal, but t are equal then you can never make it work.
    if (yy[1] == xx[1]) {
        cout << "No" << endl;
        return;
    }

    int up = xx[0] - yy[0];
    int down = yy[1] - xx[1];

    if ((up * n) % (down) != 0) {
        cout << "No" << endl;
    } else {
        int tn = (up * n) / down;
        if (tn < 0) {
            cout << "No" << endl;
            return;
        }

        bool ans = true;

        int to_check = gcd(n, tn);

        rep(i, n) {
            int check = (i + to_check) % n;
            if (s[i] != s[check]) {
                ans = false;
            }
        }

        if (ans) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
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
