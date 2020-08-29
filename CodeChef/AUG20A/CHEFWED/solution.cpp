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
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
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

int n, k;

int recur(int i, int j, vvi &pre, vvi &dp){

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    dp[i][j] = k + pre[i][j];
    repA(sec, i + 1, j){
        dp[i][j] = min(dp[i][j], k + pre[i][sec - 1] + recur(sec, j, pre, dp));
    }
    return dp[i][j];

}

void solve(){

    cin  >> n >> k;

    vi fam(n);
    rep(i, n){
        cin >> fam[i];
    }

    vvi pre(n, vi(n, 0));
    rep(i, n){
        int clash = 0;
        vi temp(101, 0)
        repA(j, i, n - 1){
            temp[fam[j]]++;
            if(temp[fam[j]] == 2){
                clash += 2;
            }else if(temp[fam[j]] > 2){
                clash++;
            }

            pre[i][j] = clash;
        }
    }

    vvi dp(n, vi(n, -1));

    cout << recur(0, n - 1, pre, dp) << endl;

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
