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
#define endl "\n"
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

const int mx = 1000;

int dp[mx][mx][2][4];

void solve(){
    int n, m;
    cin >> n >> m;

    vvi arr(n, vi(m));
    rep(i, n){
        rep(j, m){
            cin >> arr[i][j];
        }
    }

    pii start = {0, 0}, end = {n - 1, m - 1};

    dp[0][0][0][0] = 0;
    queue<pair<pii, pii>> q;
    q.emplace(mp(start, mp(0, 0)));

    auto inside = [&](int x, int y) -> bool {
        return 0 <= x && x < n && 0 <= y && y < m;
    };

    int ans = -1;
    while(!q.empty()){
        pii ps = q.front().f, prop = q.front().s;
        int x = ps.f, y = ps.s;
        int no = prop.f, dir = prop.s;
        int w = dp[x][y][no][dir];
        q.pop();

        if(arr[x][y] == 2) no = 1;

        if(ps == end){
            ans = w;
            break;
        }

        if(arr[x][y] == 4){
            no = 0;
            int nx = x + dx[dir], ny = y + dy[dir];
            if(inside(nx, ny)){
                if(arr[nx][ny] != 0 && arr[nx][ny] != 3){
                    if(dp[nx][ny][no][dir] == 0){
                        dp[nx][ny][no][dir] = w + 1;
                        q.emplace(mp(mp(nx, ny), mp(no, dir)));
                    }
                } else{
                    dir = 4;
                }
            } else{
                dir = 4;
            }
        }
        if(arr[x][y] != 4 || dir == 4){
            rep(d, 4){
                int nx = x + dx[d], ny = y + dy[d];
                if(inside(nx, ny) && arr[nx][ny] != 0 && dp[nx][ny][no][d] == 0 && (no == 1 || arr[nx][ny] != 3)){
                    dp[nx][ny][no][d] = w + 1;
                    q.emplace(mp(mp(nx, ny), mp(no, d)));
                }
            }
        }
    }

    cout << ans << endl;

}

signed main(){

#ifndef DEBUG
    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);
#endif

    fastio;

    solve();

    return 0;
}
