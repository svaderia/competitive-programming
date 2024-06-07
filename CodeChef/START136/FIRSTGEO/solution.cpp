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
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
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

    string s;
    cin >> s;

    queue<pair<int, int>> q;
    map<pair<int, int>, bool> visited;

    q.push(mp(0, 0));
    int ans = 0;
    visited[mp(0, 0)] = true;

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        ans++;
        int x = p.f, y = p.s;

        rep(i, 4){
            if(s[i] == '1'){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx > 10 || nx < -10 || ny > 10 || ny < -10){
                    break;
                }
                if(!present(visited, mp(nx, ny))){
                    visited[mp(nx, ny)] = true;
                    q.push(mp(nx, ny));
                }
            }
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
