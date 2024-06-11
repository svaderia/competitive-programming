// clang-format off
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

// clang-format on
int n, m;
vector<vvi> dp;

int recur(int i, int j, int mask){
    if(j == m){
        return recur(i + 1, 0, mask);
    }

    if(i == n){
        return 1;
    }

    // dp
    if(dp[i][j][mask] != -1){
        return dp[i][j][mask];
    }


    int ans = 0;

    // can't add new
    if((mask & (1 << j)) > 0){
        ans += recur(i, j + 1, mask ^ (1 << j));
        ans %= MOD;
    }else{
        // can add new

        // start a left if you can
        if(j < m - 1 && ((mask & (1 << (j + 1))) == 0)){
            ans +=  recur(i, j + 2, mask);
            ans %= MOD;
        }

        // start a vertilce if you can
        if(i < n - 1){
            ans += recur(i, j + 1, mask | (1 << j));
            ans %= MOD;
        }
    }


    return dp[i][j][mask] = ans;

}

void solve(){
    cin >> m >> n;

    // since the solution to he problem remains the same even if we rotate the n x m 
    // I swapped n & m so that the columns are always < 10 and I can have a mask for columns
    // It helped me solve the problem with a mask on columns, but I think you can do the same
    // with mask on row as well.


    dp.rsz(n, vvi(m, vi((1 << m), -1)));

    cout << recur(0, 0, 0) << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
