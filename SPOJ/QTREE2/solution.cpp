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

const int maxn = 10000;
const int maxlg = 15;
vector<vi> lift(maxn, vi(maxlg + 1)), g, sum(maxn, vi(maxlg + 1));
vi tin(maxn), tout(maxn), level(maxn);
int lg, timer;
map<pii, int> dis;

void dfs(int root, int p, int depth){
    tin[root] = ++timer;
    level[root] = depth;
    lift[root][0] = p;
    sum[root][0] = dis[{root, p}];
    repA(st, 1, lg){
        sum[root][st] = sum[root][st - 1] + sum[lift[root][st - 1]][st - 1];
        lift[root][st] = lift[lift[root][st - 1]][st - 1];
    }

    for(auto child : g[root]){
        if(child != p){
            dfs(child, root, depth + 1);
        }
    }

    tout[root] = ++timer;
}

bool is_ancestor(int u, int p){
    return tin[p] <= tin[u] && tout[u] <= tout[p]; 
}

int lca(int u, int v){
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

int sm(int u, int v){
    int tu = u, tv = v;

    int ans = 0;
    if(!is_ancestor(u, v)){
        repD(st, lg, 0){
            if(!is_ancestor(u, lift[tv][st])){
                ans += sum[tv][st];
                tv = lift[tv][st];
            }
        }
        ans += sum[tv][0];
    }
    if(!is_ancestor(v, u)){
        repD(st, lg, 0){
            if(!is_ancestor(v, lift[tu][st])){
                ans += sum[tu][st];
                tu = lift[tu][st];
            }
        }
        ans += sum[tu][0];
    }

    return ans;
}

int fkth(int u, int k){
    int target = level[u] - k;
    if(k == 0) return u;
    assert(target >= 0);

    repD(st, lg, 0){
        if(level[lift[u][st]] > target){
            u = lift[u][st];
        }
    }
    return lift[u][0];

}

int kt(int u, int v, int k){
    int lc = lca(u, v);
    int left = level[u] - level[lc] + 1;
    if(k <= left){
        return fkth(u, k - 1);
    }else{
        int right = level[v] - level[lc] + 1;
        int total = left + right - 1;
        int remain = total - k;
        return fkth(v, remain);
    }
}


void solve(){
    int n;
    cin >> n;
    timer = 0;
    
    g.clear(); 
    g.resize(n);
    dis.clear();
    rep(i, n - 1){
        int x, y, c;
        cin >> x >> y >> c; x--; y--;
        g[x].pb(y);
        g[y].pb(x);
        dis[{x, y}] = c;
        dis[{y, x}] = c;
    }
    lg = 63 - __builtin_clzll(n);
    dis[{0, 0}] = 0;
    dfs(0, 0, 0);

    while(true){
        string query;
        cin >> query;
        if(query == "DIST"){
            int u, v;
            cin >> u >> v; u--; v--;
            cout << sm(u, v) << endl;
        }else if(query == "KTH"){
            int u, v, k;
            cin >> u >> v >> k; u--; v--;
            cout << kt(u, v, k) + 1 << endl;
        }else{
            break;
        }
    }
    cout << endl;
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
