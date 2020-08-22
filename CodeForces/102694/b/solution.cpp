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

vvi g;

void solve(){

    int n;
    cin >> n;
    g.rsz(n);
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    int start = 0;
    int mx;
    vi ans(n, 0);
    rep(_, 2){
        vi dist(n);
        vb visited(n);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        visited[start] = true;
        mx = 0;
        while(!q.empty()){
            int root = q.front(); q.pop();
            for(int child : g[root]){
                if(!visited[child]){
                    visited[child] = true;
                    dist[child] = dist[root] + 1;
                    q.push(child);
                    mx = max(mx, dist[child]);
                }
            }
        }

        int end = start;
        rep(i, n){
            if(dist[i] == mx){
                ans[i] = 1;
                end = i;
            }
        }

        start = end;
    }

    rep(i, n){
        cout << mx + ans[i] << endl;
    }





}

signed main(){
    fastio;

    solve();

    return 0;
}
