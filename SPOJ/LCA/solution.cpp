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

int n, M;
vector<vi> g, lift;
int root;
vi tin, tout;
int timer;
int l;

void read_inp(){
    cin >> n;
    g.clear();
    g.resize(n); 
    tin.resize(n); tout.resize(n); 
    timer = 0;
    rep(i, n){
        int x, sz;
        cin >> sz;
        rep(k, sz){
            cin >> x;
            x--;
            g[i].pb(x);
        }
    }
    
    root = 0;
}

void dfs(int r, int p){
    tin[r] = ++timer;
    lift[r].pb(p);
    repA(st, 1, l){
        lift[r].pb(lift[lift[r][st - 1]][st - 1]);
    }

    for(auto child : g[r]){
        dfs(child, r);
    }

    tout[r] = ++timer;
}

bool is_ancestor(int u, int p){
    return tin[p] <= tin[u] && tout[u] <= tout[p];
}

int que(int u, int v){
    
    if(is_ancestor(u, v)){
        return v;
    }
    if(is_ancestor(v, u)){
        return u;
    }

    repD(lv, l, 0){
        if(!is_ancestor(u, lift[v][lv])){
            v = lift[v][lv];
        }
    }
    return lift[v][0];
}

void solve(){
    int lg = 64 - __builtin_clzll(n);
    // error(lg, n, root);
    lift.clear();
    lift.resize(n);
    l = lg - 1;
    
    dfs(root, root);

    cin >> M;
    rep(i, M){
        int x, y;
        cin >> x >> y;
        x--; y--;
        cout << que(x, y) + 1 << endl;
    }
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    repA(tc, 1, T){
        cout << "Case " << tc << ":" << endl;
        read_inp();
        solve();
    }

    return 0;
}
