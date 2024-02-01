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
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    rep(i, n){
        cin >> s[i];
    }

    pii start, end;
    vvi arr(n, vi(m));
    rep(i, n){
        rep(j, m){
            arr[i][j] = (s[i][j] != '#' );
            if(s[i][j] == 'C') start = mp(i, j);
            if(s[i][j] == 'D') end = mp(i, j);
        }
    }

    auto inside = [&](int x, int y) -> bool{
        return (0 <= x && x < n && 0 <= y && y < m && arr[x][y] > 0);
    };

    auto move = [&](int x, int y, bool dir) -> pii {
        if(!inside(x, y)) return mp(-1, -1);
        if(dir){
            repA(nx, x, n - 1){
                if(arr[nx][y] == 0) return mp(nx - 1, y);
                if(s[nx][y] == 'D') return mp(nx, y);
            }
            return mp(-1, -1);
        } else{
            repD(nx, x, 0){
                if(arr[nx][y] == 0) return mp(nx + 1, y);
                if(s[nx][y] == 'D') return mp(nx, y);
            }
            return mp(-1, -1);
        }
    };
    start = move(start.f, start.s, true);
    if(!inside(start.f, start.s)){
        cout << -1 << endl;
        return;
    }

    priority_queue<pair<int, pair<pii, bool>>> q;
    q.push(mp(0, mp(start, true)));

    vvi dp(n, vi(m, INF));
    dp[start.f][start.s] = 0;
    int ans = -1;

    while(!q.empty()){
        if(ans != -1) break;
        int d = -q.top().f;
        pii curr = q.top().s.f; bool dir = q.top().s.s;
        q.pop();
        if(curr == end){
            ans = d;
            break;
        }

        vii new_states;
        new_states.pb(move(curr.f, curr.s, !dir));
        new_states.pb(move(curr.f, curr.s + 1, dir));
        new_states.pb(move(curr.f, curr.s - 1, dir));

        for(auto p : new_states){
            if(inside(p.f, p.s)){
                if(p.s == curr.s && dp[p.f][p.s] > d + 1){
                    dp[p.f][p.s] = d + 1;
                    q.push(mp(-dp[p.f][p.s], mp(p, !dir)));
                }
                if(p.s != curr.s && dp[p.f][p.s] > d){
                    dp[p.f][p.s] = d;
                    q.push(mp(-dp[p.f][p.s], mp(p, dir)));
                }
            }
        }
    }

    cout << ans << endl;

}

signed main(){
#ifndef DEBUG
    freopen("gravity.in", "r", stdin);
    freopen("gravity.out", "w", stdout);
#endif

    fastio;

    solve();

    return 0;
}
