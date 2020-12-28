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

typedef vector<long double> vld;

const int n = 8;

bool inside(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

void solve(){
    int k;
    cin >> k;

    vector<vld> ans(n, vld(n, 1));
    rep(startR, n){
        rep(startC, n){
            vector<vector<vld>> dp(k + 1, vector<vld>(n, vld(n, 0)));
            dp[0][startR][startC] = 1;
            repA(kk, 1, k){
                rep(i, n){
                    rep(j, n){
                        int canMove = 0;
                        rep(d, 4){
                            int nx = i + dx[d], ny = j + dy[d];
                            if(inside(nx, ny)) canMove++;
                        }
                        rep(d, 4){
                            int nx = i + dx[d], ny = j + dy[d];
                            if(inside(nx, ny)) dp[kk][nx][ny] += dp[kk - 1][i][j] / canMove;
                        }
                    }
                }
            }
            rep(i, n){
                rep(j, n){
                    ans[i][j] *= (1 - dp[k][i][j]);
                }
            }
        }
    }

    long double ansPrint = 0;
    rep(i, n){
        rep(j, n){
            ansPrint += ans[i][j];
        }
    }

    cout << fixed << setprecision(6) << ansPrint << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
