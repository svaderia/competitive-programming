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
typedef vector<double> vld;

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

int n;
vector<vld> dp;

double rec(int x, int v){
    if(v <= 0 || v >= 2 * n) return 0;
    if(dp[x][v] == -1){
        double steps = 0;
        // head
        steps += (1.0 + rec(0, v + (1 << x))) / 2.0;
        // tail
        steps += (1.0 + rec(x + 1, v - (1 << x))) / 2.0;

        dp[x][v] = steps;
    }
    return dp[x][v];
}

void solve(){

    cin >> n;

    dp.clear();
    dp.rsz(24, vld(2 * n, -1));

    cout << fixed << setprecision(12) << rec(0, n) << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
