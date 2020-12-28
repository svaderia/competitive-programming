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
const int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};
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

vvi visited(8, vi(8, -1));
vvi ans(8, vi(8, -1));
bool found = false;

inline bool inside(int x, int y){
    return 0 <= x && x < 8 && 0 <= y && y < 8;
}

int count(int x, int y){
    int c = 0;
    rep(d, 8){
        int nx = x + dx[d], ny = y + dy[d];
        if(inside(nx, ny) && visited[nx][ny] == -1)
            c++;
    }

    return c;
}

void dfs(int x, int y, int step){
    if(found) return;
    vector<pair<int, pii>> fin;
    visited[x][y] = step;
    rep(d, 8){
        int nx = x + dx[d], ny = y + dy[d];
        if(inside(nx, ny) && visited[nx][ny] == -1)
            fin.pb(mp(count(nx, ny), mp(nx, ny)));
    }

    sort(all(fin));
    if(sz(fin) == 0){
        bool pos = true;
        rep(i, 8)
            rep(j, 8)
                if(visited[i][j] == -1) pos = false;
        if(pos){
            rep(i, 8)
                rep(j, 8)
                    ans[i][j] = visited[i][j];
            found = true;
        }
    }else{
        for(auto p : fin)
            dfs(p.s.f, p.s.s, step + 1);
    }
    visited[x][y] = -1;
}

void solve(){
    int y, x;
    cin >> y >> x;
    x--, y--;

    dfs(x, y, 1);

    rep(i, 8){
        rep(j, 8){
            cout << ans[i][j] << spc;
        }
        cout << endl;
    }
}

signed main(){
    fastio;

    solve();

    return 0;
}
