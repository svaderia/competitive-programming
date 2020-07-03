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
const int INF = MOD;

vector<vi> g;
vi tin, tout;
int n, timer, lg;
vector<vi> up, mn, mx;
map<pii, int> dis;

void dfs(int root, int p){
    tin[root] = ++timer;

    up[root][0] = p;
    mn[root][0] = dis[{root, p}];
    mx[root][0] = dis[{root, p}];
    if(root == p){
        mx[root][0] = 0;
    }
    error(root, p, mn[root][0], mx[root][0]);
    repA(st, 1, lg){
        mn[root][st] = min(mn[root][st - 1], mn[up[root][st - 1]][st - 1]);
        mx[root][st] = max(mx[root][st - 1], mx[up[root][st - 1]][st - 1]);
        up[root][st] = up[up[root][st - 1]][st - 1];
    }
    for(auto child : g[root]){
        if(child != p){
            dfs(child, root);
        }
    }

    tout[root] = ++timer;
}

bool is_ancestor(int u, int p){
    return tin[p] <= tin[u] && tout[u] <= tout[p];
}

pii query(int u, int v){
    if(u == v){
        return {0, 0};
    }
    int tu = u, tv = v;
    int amn = INF, amx = 0;

    error(tu, tv);
    if(!is_ancestor(u, v)){
        repD(st, lg, 0){
            if(!is_ancestor(u, up[tv][st])){
                amn = min(amn, mn[tv][st]);
                amx = max(amx, mx[tv][st]);
                tv = up[tv][st];
                error(tv);
            }
        }
        amn = min(amn, mn[tv][0]);
        amx = max(amx, mx[tv][0]);
        error(tv, mn[tv][0], mx[tv][0]);
    }

    if(!is_ancestor(v, u)){
        repD(st, lg, 0){
            if(!is_ancestor(v, up[tu][st])){
                amn = min(amn, mn[tu][st]);
                amx = max(amx, mx[tu][st]);
                tu = up[tu][st];
                error(tu);
            }
        }
        amn = min(amn, mn[tu][0]);
        amx = max(amx, mx[tu][0]);
        error(tu, mn[tu][0], mx[tu][0]);
    }


    return {amn, amx};
}

void solve(){
    cin >> n;
    lg = 64 - __builtin_clzll(n);
    lg--;
    error(lg);
    timer = 0;
    g.resize(n); tin.resize(n); tout.resize(n);
    up.resize(n, vi(lg + 1));
    mn.resize(n, vi(lg + 1));
    mx.resize(n, vi(lg + 1));

    rep(i, n - 1){
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
        dis[{x, y}] = c;
        dis[{y, x}] = c;
    }
    
    dis[{0, 0}] = INF;
    error(timer);
    dfs(0, 0);
    error(timer);

    int k;
    cin >> k;
    rep(i, k){
        int x, y;
        cin >> x >> y;
        x--; y--;
        pii ans = query(x, y);
        cout << ans.first << " " << ans.second << endl;
    }
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    solve();

    return 0;
}

/// TRY To do it with Sparse table; // YOu should be able to, During Euler tour, rather than storing indexes, store the lengths, and you are good to go.