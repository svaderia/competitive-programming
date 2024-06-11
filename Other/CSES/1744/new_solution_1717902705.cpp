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
/* #define endl "\n" */
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

vvi dp;

int recur (int w, int h){
    if (w == 0 || h == 0)
        return 0;
    if (w == h)
        return 0;

    if (dp[w][h] != -1)
        return dp[w][h];

    int ans = INF;

    repA(i, 1, w / 2){
        ans = min(ans, 1 + recur(w - i, h) + recur(i, h));
    }

    repA(i, 1, h / 2){
        ans = min(ans, 1 + recur(w, h - i) + recur(w, i));
    }

    return dp[w][h] = ans;
};

// clang-format on
// lesson to learn here is that recursive lambda functions take more time. I think 
// that is because compiler can't optimise them?
void solve() {
    int a, b;
    cin >> a >> b;

    dp.rsz(a + 1, vi(b + 1, -1));

    cout << recur(a, b) << endl;
}

signed main() {
    fastio;

    solve();

    return 0;
}
