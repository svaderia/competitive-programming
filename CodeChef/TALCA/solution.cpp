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

vector<vi> g, lift;
vi tin, tout;
int n, lg, timer;

void dfs(int root, int p){
    tin[root] = timer++;

    lift[root][0] = p;
    repA(st, 1, lg){
        lift[root][st] = lift[lift[root][st - 1]][st - 1];
    }

    for(auto child : g[root]){
        if(child != p){
            dfs(child, root);
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
    cin >> n;
    lg = 64 - __builtin_clzll(n);
    lg--;
    g.resize(n);
    lift.resize(n, vi(lg + 1));
    tin.resize(n); tout.resize(n);
    rep(i, n - 1){
        int x, y;
        cin >> x >> y; 
        x--; y--;
        g[x].pb(y);
        g[y].pb(x);
    }

    timer = 0;
    dfs(0, 0);

    int m;
    cin >> m;
    rep(i, m){
        int r, u, v;
        cin >> r >> u >> v;

        r--; u--; v--;

        int lca = query(u, v);

        if(is_ancestor(r, lca)){
            int lu = query(r, u), lv = query(r, v);
            if(lu == lca){
                cout << lv + 1 << endl;
            }else if(lv == lca){
                cout << lu + 1 << endl;
            }
        }else{
            cout << lca + 1 << endl;
        }
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
