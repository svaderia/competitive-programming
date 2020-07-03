#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(false);cin.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define endl "\n"
#define errorp(p) cerr << #p << " = " << (p.first) << ", " << (p.second) << endl
#ifdef DEBUG
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {it++; cout << endl;}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << " [ "<< *it << " : " << a << " ] "; err(++it, args...); }
#else
#define error(args...)
#endif
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

const int maxn = 450000;
const int maxlg = 20;
vector<vi> lift(maxn, vi(maxlg + 1)), g;
vi tin(maxn), tout(maxn);
int lg, timer;
vector<bitset<250> > dp(maxn);

void dfs(int root, int par){
    tin[root] = timer++;

    lift[root][0] = par;
    repA(st, 1, lg){
        lift[root][st] = lift[lift[root][st - 1]][st - 1];
    }
    for(int child : g[root]){
        if(child != par){
            dfs(child, root);
            dp[root] |= dp[child];
        }
    }

    tout[root] = timer++;
}

bool is_ancestor(int u, int p){
    return tin[p] <= tin[u] && tout[u] <= tout[p]; 
}

int query(int u, int v){
    if(is_ancestor(u, v)){
        return v;
    }
    if(is_ancestor(v, u)){
        return u;
    }

    repD(st, lg, 0){
        if(!is_ancestor(u, lift[v][st])){
            v = lift[v][st];
        }
    }
    return lift[v][0];
}


void solve(){
    int n, q, root;
    cin >> n >> q >> root;
    timer = 0;
    rep(i, n){
        int s;
        cin >> s;
        s--;
        dp[i].reset();
        dp[i].set(s);
    }
    g.clear(); 
    g.resize(n);
    rep(i, n - 1){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    lg = 63 - __builtin_clzll(n);

    dfs(root, root);

    rep(i, q){
        int u, v;
        cin >> u >> v;
        int lca = query(u, v);
        cout << dp[lca].count() << endl;
    }

}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        solve();
    }

    return 0;
}
