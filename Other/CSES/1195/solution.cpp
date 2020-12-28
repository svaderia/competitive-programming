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

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vii> g(n);
    rep(i, m){
        int a, b, x;
        cin >> a >> b >> x;
        a--, b--;
        g[a].pb(mp(b, x));
    }

    vvi dp(n, vi(2, INF));
    vector<vb> used(n, vb(2));
    dp[0][0] = 0;

    priority_queue<pair<int, pii>> pq;
    pq.push(mp(0ll, mp(0ll, 0ll)));

    while(!pq.empty()){
        auto tmp = pq.top();
        int d = -tmp.f, root = tmp.s.f, dir = tmp.s.s;
        pq.pop();
        if(used[root][dir]) continue;
        used[root][dir] = true;

        for(auto p : g[root]){
            int child = p.f, w = p.s;
            if(dp[child][dir] > d + w){
                dp[child][dir] = d + w;
                pq.push(mp(-dp[child][dir], mp(child, dir)));
            }
            if(!dir && dp[child][1] > d + w / 2){
                dp[child][1] = d + w / 2;
                pq.push(mp(-dp[child][1], mp(child, 1)));

            }
        }
    }

    cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
