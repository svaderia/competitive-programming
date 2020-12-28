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

int n, m;
vvi g;
vb visited;
vb reach;

void dfs(int root){
    visited[root] = true;
    if(root == n - 1) reach[root] = true;
    for(auto child : g[root]){
        if(!visited[child]) dfs(child);
        reach[root] = reach[root] | reach[child];
    }
}

void solve(){
    cin >> n >> m;

    g.rsz(n);
    visited.rsz(n);
    reach.rsz(n);

    vector<pair<pii, int> > edges;
    rep(i, m){
        int a, b, x;
        cin >> a >> b >> x;
        a--, b--;
        edges.eb(mp(mp(a, b), x));
        g[a].pb(b);
    }

    int root = 0;
    dfs(root);

    vi dp(n, -INF);
    dp[root] = 0;

    rep(_, n){
        for(auto e : edges){
            int a = e.f.f, b = e.f.s, w = e.s;
            dp[b] = max(dp[b], dp[a] + w);
        }
    }

    int changed = false;
    for(auto e : edges){
        int a = e.f.f, b = e.f.s, w = e.s;
        if(dp[b] < dp[a] + w && reach[a]){
            changed = true;
        }
    }

    cout << (changed ? -1 : dp[n - 1]) << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
