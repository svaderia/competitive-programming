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
const int INF   = 1e18;

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

int n, m;
vector<string> arr;
vvi visited;
int ans = 0;

inline bool inside(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == '.');
}

void dfs(int x, int y){
    visited[x][y] = ans;
    rep(i, 4){
        int nx = x + dx[i], ny = y + dy[i];
        if(inside(nx, ny) && visited[nx][ny] == 0)
            dfs(nx, ny);
    }
}

void solve(){

    cin >> n >> m;

    arr.rsz(n);
    visited.rsz(n, vi(m));

    rep(i, n){
        cin >>  arr[i];
    }

    rep(ix, n){
        rep(iy, m){
            if(visited[ix][iy] == 0 && inside(ix, iy)){
                ans++;
                dfs(ix, iy);
            }
        }
    }

    cout << ans << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
