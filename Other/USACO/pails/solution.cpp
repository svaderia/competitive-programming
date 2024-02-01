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
#define endl "\n"
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

void solve(){
    int x, y, k, m;
    cin >> x >> y >> k >> m;

    queue<pii> q;
    q.push(mp(0, 0));

    int ans = m;

    vvi visited(x + 1, vi(y + 1, -1));
    visited[0][0] = 0;
    while(!q.empty()){
        int a = q.front().f, b = q.front().s;
        int w = visited[a][b];
        q.pop();
        ans = min(ans, abs(m - a - b));
        if(visited[a][b] == k) continue;
        vii newStates;
        if(a < x){
            newStates.pb(mp(x, b));
            int extra = min(a + b, x) - a;
            newStates.pb(mp(a + extra, b - extra));
        }
        if(b < y){
            newStates.pb(mp(a, y));
            int extra = min(a + b, y) - b;
            newStates.pb(mp(a - extra, b + extra));
        }
        if(a > 0)
            newStates.pb(mp(0, b));
        if(b > 0)
            newStates.pb(mp(a, 0));

        for(auto p : newStates){
            if(visited[p.f][p.s] == -1){
                visited[p.f][p.s] = w + 1;
                q.push(p);
            }
        }
    }

    cout << ans << endl;

}

signed main(){
#ifndef DEBUG
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
#endif

    fastio;

    solve();

    return 0;
}
