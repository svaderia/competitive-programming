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

int count_digit(int x) {
    int temp = 0;
    while (x > 0) {
        temp++;
        x /= 10;
    }

    return temp;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vi x(n);
    rep(i, n) {
        cin >> x[i];
    }

    map<int, map<int, int>> digit; // digit to count mapping

    rep(i, n) {
        int d = count_digit(x[i]);
        int y = x[i] % k;
        if (!present(digit[d], y)) {
            digit[d][y] = 0;
        }
        digit[d][y]++;
    }

    int ans = 0;

    rep(i, n) {
        int d = count_digit(x[i]);
        int y = x[i] % k;

        int tt = y;
        repA(dig, 1, 10) {
            tt *= 10;
            tt %= k;
            int search = (k - tt) % k;
            int tans = 0;
            if (present(digit[dig], search)) {
                tans = digit[dig][search];
            }
            if (dig == d && search == y) {
                tans--;
            }
            assert(tans >= 0);
            ans += tans;
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
