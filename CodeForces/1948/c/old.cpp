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

vvi arr;
vvi visited;
vvi tvisited;

int n;

void dfs(int x, int y){
    visited[x][y] = 1;
    /* cout << x << spc << y << endl; */

    rep(i, 4){
            int xi = x + dx[i];
            int yi = y + dy[i];
            if(xi < 0 or xi > 1) continue;
            if(yi < 0 or yi >= n) continue;
            /* cout << xi << spc << yi << spc << arr[xi][yi] << endl; */
            tvisited[xi][yi] = 1;
            yi += arr[xi][yi];
            if(yi < 0 or yi >= n) continue;
            if(visited[xi][yi] == 0){
                dfs(xi, yi);
            }
    }
}

void solve(){

    cin >> n;

    string x, y;
    cin >> x >> y;

    arr.rsz(2, vi(n));
    rep(i, n){
        arr[0][i] = (x[i] == '>' ? 1 : -1);
    }
    rep(i,n){
        arr[1][i] = (y[i] == '>' ? 1 : -1);
    }

    visited.rsz(2, vi(n, 0));
    tvisited.rsz(2, vi(n, 0));
    dfs(0, 0);

    int ans = visited[1][n - 1] || tvisited[1][n - 1];

    if(ans){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    visited.clear();
    tvisited.clear();


}

signed main(){
    fastio;

    int T;
    cin >> T;

    repA(tc, 1, T){
        solve();
    }

    return 0;
}
