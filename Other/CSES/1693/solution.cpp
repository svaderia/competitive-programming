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
    vi in(n), out(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        g.add(--a, --b, false);
        out[a]++, in[b]++;
    }

    bool possible = true;
    int start = -1, end = -1;
    rep(i, n){
        if(in[i] == out[i]) continue;
        if(in[i] == out[i] + 1 && end == -1)
            end = i;
        else if(out[i] == in[i] + 1 && start == -1)
            start = i;
        else
            possible = false;
    }
    if(start != -1)
        possible = start == 0;
    if(end != -1)
        possible = end == n - 1;

    if(possible){
        vi done(n);

        vi stk;
        if(start == -1) start = 0;
        stk.pb(start);

        vi ans;
        while(sz(stk) != 0){
            int root = *stk.rbegin();

            if(done[root] == sz(g.adj[root])){
                stk.pop_back();
                ans.pb(root);
            }else{
                stk.pb(g.adj[root][done[root]].to);
                done[root]++;
            }
        }
        if(sz(ans) != m + 1 || ans[0] != n - 1){
            cout << "IMPOSSIBLE" << endl;
        }else{
            reverse(all(ans));
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
