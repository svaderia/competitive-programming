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

    int n, m, source, dest;
    cin >> n >> m >> source >> dest;
    source--; dest--;

    vector<vii> g(n);
    rep(i, m){
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        g[u].eb(mp(v, c));
        g[v].eb(mp(u, c));
    }

    priority_queue<pii> pq;

    vb used(n);
    vi dp(n, INF);
    dp[source] = 0;
    pq.push(mp(0, source));

    while(!pq.empty()){
        int d = -pq.top().f , root = pq.top().s;
        pq.pop();
        if(used[root]) continue;
        used[root] = true;
        for(auto p : g[root]){
            int child = p.f, w = p.s;
            if(dp[child] > w + d){
                dp[child] = w + d;
                pq.push(mp(-dp[child], child));
            }
        }
    }

    if(dp[dest] == INF){
        cout << "NONE" << endl;
    }else{
        cout << dp[dest] << endl;
    }

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
