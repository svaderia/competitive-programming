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

    int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;

    vector<vii> g(n + 1);
    rep(i, m){
        int u, v, cost;
        cin >> u >> v >> cost;
        g[u].pb(mp(v, cost));
    }

    vector<pair<pii, int> > ways;
    rep(i, k){
        int u, v, c;
        cin >> u >> v >> c;
        ways.pb(mp(mp(u, v), c));
    }

    int ans = INF;
    rep(curr, k){
        vi used(n + 1, false);
        vi fin(n + 1, INF);
        fin[s] = 0;
        priority_queue<pii> pq;
        pq.push(mp(0, s));
        while(!pq.empty()){
            int d = -pq.top().f, root = pq.top().s;
            pq.pop();
            if(used[root]) continue;
            used[root] = true;
            if(root == t){
                ans = min(ans, d);
                break;
            }
            for(auto p : g[root]){
                int child = p.f, w = p.s;
                if(d + w < fin[child]){
                    fin[child] = d + w;
                    pq.push(mp(-fin[child], child));
                }
            }
            int u = ways[curr].f.f, v = ways[curr].f.s, w = ways[curr].s;
            if(v == root) swap(u, v);
            if(u == root){
                if(d + w < fin[v]){
                    fin[v] = d + w;
                    pq.push(mp(-fin[v], v));
                }
            }
        }
    }

    if(ans == INF) ans = -1;
    cout << ans << endl;

}

signed main(){
    fastio;

    int T;
    cin >> T;

    repA(tc, 1, T){
        solve();
    }

    return 0;
}
