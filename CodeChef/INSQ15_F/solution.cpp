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

    int n, r;
    cin >> n >> r;
    vi h(n);
    rep(i, n){
        cin >> h[i];
    }

    vi c(n);
    rep(i, n){
        cin >> c[i];
    }

    vvi g(n);
    rep(i, r){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    vector<vb> used(n, vb(2));
    priority_queue<pair<int, pii> > pq;
    pq.push(mp(-c[0], mp(0, 0)));
    pq.push(mp(-c[0], mp(0, 1)));

    vvi dist(n, vi(2, INF));
    dist[0][0] = dist[0][1] = c[0];

    while(!pq.empty()){
        int d = -pq.top().f,  root = pq.top().s.f, dir = pq.top().s.s;
        pq.pop();
        if(used[root][dir]) continue;
        used[root][dir] = true;
        for(auto child : g[root]){
            if(h[child] >= h[root] && dist[child][1] > d + (dir == 1 ? 0 : c[root])){
                dist[child][1] = d + (dir == 1 ? 0 : c[root]);
                pq.push(mp(-dist[child][1], mp(child, 1)));
            }
            if(h[child] <= h[root] && dist[child][0] > d + (dir == 0 ? 0 : c[root])){
                dist[child][0] = d + (dir == 0 ? 0 : c[root]);
                pq.push(mp(-dist[child][0], mp(child, 0)));
            }
        }
    }
    int ans = min(dist[n - 1][0], dist[n - 1][1]);
    cout << (ans == INF ? -1 : ans) << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
