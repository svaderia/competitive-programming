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

void self_min(int &a, int b){
    a = min(a, b);
}

void solve(){
    int n, k;
    cin >> n >> k;

    vi r(n);
    rep(i, n){
        cin >> r[i];
    }

    vvi cost(n, vi(n));

    rep(s, n){
        int cst = 0;
        rep(l, n){
            int e = (s + l) % n;
            cst += l * r[e];
            cost[s][e] = cst;
        }
    }

    int ans = INF;
    rep(start, n){

        vvi dp(n, vi(k + 1, INF));
        rep(e, n){
            dp[e][1] = cost[e][(start - 1 + n) % n];
        }

        repD(i, n - 1, start){
            repA(ks, 2, k){
                repA(j, i + 1, n - 1){
                    self_min(dp[i][ks], cost[i][j - 1] + dp[j][ks - 1]);
                }
            }
        }
        self_min(ans, dp[start][k]);
    }

    cout << ans << endl;

}

signed main(){
#ifndef DEBUG
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
#endif

    fastio;

    solve();

    return 0;
}
