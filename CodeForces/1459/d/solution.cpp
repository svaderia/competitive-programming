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

int n;
vi a, b;
int k;

double recur(int idx, int kk, int discard, int extra){
    if(idx < 0){
        return min((double)extra, (double)discard / 2.0);
    }

    double ans = 0;
    if(kk > 0){
        ans = max(ans, (double)b[idx] + recur(idx - 1, kk - 1, discard, extra + (a[idx] - b[idx])));
    }
    ans = max(ans, recur(idx - 1, kk, discard + b[idx], extra));
    return ans;
}

int m = 105;
void solve(){
    cin >> n;

    a.rsz(n);
    b.rsz(n);
    int w = 0;
    rep(i, n){
        cin >> a[i];
        cin >> b[i];
        w += b[i];
    }

    cout.precision(9);

    vvi dp(n + 1, vi(n * m, -INF));
    dp[0][0] = 0;

    rep(i, n){
        repD(kk, i, 0){
            rep(ss, n * m){
                if(dp[kk][ss] != -INF){
                    dp[kk + 1][ss + a[i]] = max(dp[kk + 1][ss + a[i]], dp[kk][ss] + b[i]);
                }
            }
        }
    }

    vector<double> ans(n, 0);
    repA(kk, 1, n){
        rep(ss, n * m){
            if(dp[kk][ss] != -INF)
                ans[kk - 1] = max(ans[kk - 1], min((double)(w + dp[kk][ss]) / 2.0, (double)ss));
        }
    }

    rep(i, n){
        cout << ans[i] << spc;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
