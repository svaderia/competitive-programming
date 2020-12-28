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
struct edge{
    int to, w, id;
    edge(int ii, int ww, int idx) : to(ii), w(ww), id(idx) {}
};

struct Graph{
    int n, m;
    vector<vector<edge>> adj;

    Graph(int nn) : n(nn), m(0), adj(nn) {}

    void add(int u, int v, bool undirected = true, int w = 0){
        adj[u].pb(edge(v, w, m));
        if(undirected)
            adj[v].pb(edge(u, w, m));
        m++;
    }
};

void solve(){

    int n, m;
    cin >> n >> m;

    Graph g(n);
    vi deg(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        g.add(--a, --b);
        deg[a]++, deg[b]++;
    }

    bool possible = true;
    rep(i, n){
        if(deg[i] % 2 == 1) possible = false;
    }
    dbg(deg);

    if(possible){
        set<pii> passed;
        vi done(n);

        stack<int> stk;
        stk.push(0);

        vi ans;
        while(!stk.empty()){
            int root = stk.top();

            while(done[root] < sz(g.adj[root]) && present(passed, mp(root, g.adj[root][done[root]].to))){
                done[root]++;
            }

            if(done[root] == sz(g.adj[root])){
                stk.pop();
                ans.pb(root);
            }else{
                stk.push(g.adj[root][done[root]].to);
                passed.insert(mp(root, g.adj[root][done[root]].to));
                passed.insert(mp(g.adj[root][done[root]].to, root));
                done[root]++;
            }
        }
        if(sz(ans) != m + 1){
            cout << "IMPOSSIBLE" << endl;
        }else{
            for(auto x : ans){
                cout << x + 1 << spc;
            }
        }
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
