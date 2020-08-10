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
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
const int INF   = 1e18;

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

void solve(){

    int m;
    cin  >> m;

    int n = 502;
    vector<vii> g(n);
    rep(i, m){
        int u, v, w;
        cin  >> u >> v >> w;
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
    }

    vb used(n);
    vi fin(n, INF);
    int source;
    cin  >> source;
    fin[source] = 0;
    priority_queue<pii> pq;
    pq.push(mp(0, source));
    while(!pq.empty()){
        int d = -pq.top().f, root = pq.top().s;
        pq.pop();
        if(used[root]) continue;
        used[root] = true;
        for(auto p : g[root]){
            int child = p.f, w = p.s;
            if(d + w < fin[child]){
                fin[child] = d + w;
                pq.push(mp(-fin[child], child));
            }
        }
    }
    int q;
    cin  >> q;
    rep(i, q){
        int t;
        cin  >> t;
        if(fin[t] == INF) cout << "NO PATH" << endl;
        else cout << fin[t] << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
