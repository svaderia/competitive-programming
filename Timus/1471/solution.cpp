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

vector<vi> g, lift, sum;
int n, lg, timer;
vi tin, tout;
map<pii, int> dis;

void dfs(int root, int p){
    tin[root] = ++timer;

    lift[root][0] = p;
    sum[root][0] = dis[{root, p}];
    repA(st, 1, lg){
        sum[root][st] = sum[root][st - 1] + sum[lift[root][st - 1]][st - 1];
        lift[root][st] = lift[lift[root][st - 1]][st - 1];
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

int query(int u, int v){
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


void solve(){
    cin >> n;
    lg = 64 - __builtin_clzll(n); lg--;
    g.resize(n);
    lift.resize(n, vi(lg + 1)); sum.resize(n, vi(lg + 1));
    rep(i, n - 1){
        int x, y, c;
        cin >> x >> y >> c;
        g[x].pb(y);
        g[y].pb(x);
        dis[{x, y}] = c;
        dis[{y, x}] = c;
    }
    timer = 0;
    tin.resize(n); tout.resize(n);
    dis[{0, 0}] = 0;
    dfs(0, 0);

    int m;
    cin >> m;
    rep(i, m){
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << endl;
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
