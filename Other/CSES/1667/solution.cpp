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
    int n, m;
    cin >> n >> m;

    vvi g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }

    int start = 0, end = n - 1;

    queue<pii> q;
    q.push(mp(0, 1));

    vi visited(n, -1);
    visited[0] = 0;
    int ans = -1;
    while(!q.empty()){
        int root = q.front().f, d = q.front().s;
        q.pop();
        if(root == end){
            ans = d; break;
        }

        for(auto child : g[root]){
            if(visited[child] == -1){
                visited[child] = root;
                q.push(mp(child, d + 1));
            }
        }
    }

    if(ans == -1){
        cout << "IMPOSSIBLE" << endl;
    }else{
        vi steps;
        int temp = end;
        while(temp != start){
            steps.pb(temp);
            temp = visited[temp];
        }
        steps.pb(start);
        reverse(all(steps));
        cout << ans << endl;
        for(auto x : steps) cout << x + 1 << spc;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
