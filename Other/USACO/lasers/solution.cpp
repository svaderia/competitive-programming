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
    int n, xs, ys, xt, yt;
    cin >> n >> xs >> ys >> xt >> yt;

    unordered_map<int, vi> xx, yy;
    rep(i, n){
        int x, y;
        cin >> x >> y;
        xx[x].pb(y);
        yy[y].pb(x);
    }

    queue<pii> q;
    q.push(mp(xs, 0));
    q.push(mp(ys, 1));

    map<pii, int> dp;
    dp[mp(xs, 0)] = 0;
    dp[mp(0, ys)] = 0;

    int ans = -1;

    if(xs == xt || ys == yt){
        ans = 0;
    }

    while(!q.empty()){
        int curr = q.front().f, dir = q.front().s;
        q.pop();
        if(ans != -1) break;

        if(dir == 0){
            for(auto child : xx[curr]){
                if(child == yt){
                    ans = dp[mp(curr, 0)] + 1;
                    break;
                }
                if(dp[mp(0, child)] == 0){
                    dp[mp(0, child)] = dp[mp(curr, 0)] + 1;
                    q.push(mp(child, 1));
                }
            }
        } else{
            for(auto child : yy[curr]){
                if(child == xt){
                    ans = dp[mp(0, curr)] + 1;
                    break;
                }
                if(dp[mp(child, 0)] == 0){
                    dp[mp(child, 0)] = dp[mp(0, curr)] + 1;
                    q.push(mp(child, 0));
                }
            }
        }
    }

    cout << ans << endl;

}

signed main(){
#ifndef DEBUG
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
#endif

    fastio;

    solve();

    return 0;
}
