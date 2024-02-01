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

enum{
    H,
    P,
    S
};
void self_max(int &a, int b){
    a = max(a, b);
}

void solve(){
    int n, k;
    cin >> n >> k;

    vi plays(n);
    rep(i, n){
        char x;
        cin >> x;
        plays[i] = (x == 'H' ? H : (x == 'P' ? P : S));
    }

    vector<vvi> dp(n, vvi(k + 1, vi(3, 0)));
    dp[0][0][(plays[0] + 1) % 3] = 1;

    // DP stores max number of games win, till ith game if we have switched k times and current guesture is PLAY
    repA(i, 1, n - 1){
        rep(ks, k + 1){
            rep(play, 3){
                self_max(dp[i][ks][play], ((plays[i] + 1) % 3 == play) + dp[i - 1][ks][play]);
            }
            if(ks > 0){
                self_max(dp[i][ks][(plays[i] + 1) % 3], 1 + max(dp[i - 1][ks - 1][plays[i]], dp[i - 1][ks - 1][(plays[i] + 2) % 3]));
            }
        }
    }

    int ans = 0;
    rep(ks, k + 1){
        rep(play, 3){
            self_max(ans, dp[n - 1][ks][play]);
        }
    }
    cout << ans << endl;

}

signed main(){

#ifndef DEBUG
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
#endif
    fastio;

    solve();

    return 0;
}
