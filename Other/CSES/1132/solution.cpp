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

vvi g;
vi dp, dp2, dp3, ans;

void dfs_down(int root, int p){
    vi m(4);

    for(auto child : g[root]){
        if(child != p){
            dfs_down(child, root);
            m[3] = dp[child];
            sort(rall(m));
        }
    }

    dp[root] = (1 + m[0]);
    dp2[root] = (1 + m[1]);
    dp3[root] = (1 + m[2]);
}

void dfs_up(int root, int p){

    int rdp = dp[root], rdp2 = dp2[root];
    int pdp = dp[p], pdp2 = dp2[p];

    if(root != p){
        if(rdp == pdp - 1){
            dp[root] = max(rdp, 1 + pdp2);
            dp2[root] = max(min(rdp, 1 + pdp2), rdp2);
            dp[p] = pdp2;
            dp2[p] = dp3[p];
        }else{
            dp[root] = 1 + pdp;
            dp2[root] = max(1 + pdp2, rdp);
            dp[p] = pdp;
            dp2[p] = pdp2;
        }
    }

    ans[root] = dp[root] - 1;
    for(auto child : g[root]){
        if(child != p){
            dfs_up(child, root);
        }
    }

    if(root != p){
        dp[root] = rdp, dp2[root] = rdp2;
        dp[p] = pdp, dp2[p] = pdp2;
    }

}

void solve(){

    int n;
    cin >> n;

    g.rsz(n);
    dp.rsz(n);
    dp2.rsz(n);
    dp3.rsz(n);
    ans.rsz(n);

    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs_down(0, 0);
    dfs_up(0, 0);

    rep(i, n){
        cout << ans[i] << spc;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
