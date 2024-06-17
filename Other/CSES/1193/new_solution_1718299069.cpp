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

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    map<int, char> mm = {{0, 'D'}, {1, 'R'}, {2, 'U'}, {3, 'L'}};

    vvi visited(n, vi(m, -1));
    pii start, end;
    rep(i, n) {
        rep(j, m) {
            char x;
            cin >> x;

            if (x == '#') {
                visited[i][j] = 4;
            } else if (x == 'A') {
                start = mp(i, j);
            } else if (x == 'B') {
                end = mp(i, j);
            }
        }
    }

    queue<pair<pii, int>> q;
    q.push(mp(start, 0));

    int dans = -1;

    while (!q.empty()) {
        auto tp = q.front();
        q.pop();
        if (tp.f == end) {
            dans = tp.s;
            break;
        }

        rep(i, 4) {
            pii data = tp.f;
            int dist = tp.s;
            int nx = data.f + dx[i], ny = data.s + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (visited[nx][ny] < 0) {
                    visited[nx][ny] = i;
                    q.push(mp(mp(nx, ny), dist + 1));
                }
            }
        }
    }

    if (dans == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << dans << endl;
        string ans;
        pii temp = end;
        while (temp != start) {
            int dir = visited[temp.f][temp.s];
            int nx = temp.f - dx[dir], ny = temp.s - dy[dir];
            temp = mp(nx, ny);
            ans.pb(mm[dir]);
        }
        reverse(all(ans));
        cout << ans << endl;
    }
}

signed main() {
    fastio;

    solve();

    return 0;
}
