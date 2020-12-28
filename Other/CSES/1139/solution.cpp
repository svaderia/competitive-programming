#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD   = 1e9 + 7;
const double PI = acos(-1.0);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};

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
vector<set<int> > dp;
vi c, ans;

void dfs(int root, int p){

    int mx = 0, id = -1;
    for(auto child : g[root]){
        if(child == p) continue;
        dfs(child, root);
        if(mx < sz(dp[child])) mx = sz(dp[child]), id = child;
    }

    if(id != -1){
        swap(dp[root], dp[id]);
    }

    for(auto child : g[root]){
        if(child == p || child == id) continue;
        for(auto x : dp[child])
            dp[root].insert(x);
        dp[child].clear();
    }

    dp[root].insert(c[root]);

    ans[root] = sz(dp[root]);
}

void solve(){

    int n;
    cin >> n;

    g.rsz(n);
    dp.rsz(n), c.rsz(n), ans.rsz(n);

    rep(i, n){
        cin >> c[i];
    }

    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(0, 0);

    rep(i, n)
        cout << ans[i] << spc;
}

signed main(){
    fastio;

    solve();

    return 0;
}
