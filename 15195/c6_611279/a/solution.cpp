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

vvi edges;
vi visited;
int counter;

void dfs(int root){
    visited[root] = counter;
    int m = sz(edges[root]);
    rep(i, m){
        int child = edges[root][i];
        /* cout << child << spc << root << endl; */
        if(visited[child] == 0){
            dfs(child);
        }
    }
}

int nc2(int x){
    return (x * (x - 1)) / 2;
}

void solve(){

    int n, p;
    cin >> n >> p;
    /* cout << n << p << endl; */

    edges.resize(n, vi(0));
    visited.resize(n, 0);

    rep(i, p){
        int x, y;
        cin >> x >> y;
        /* cout << x << y << endl; */
        edges[x].pb(y);
        edges[y].pb(x);
    }

    counter = 1;

    rep(i, n){
        if(visited[i] == 0){
            dfs(i);
            counter++;
        }
    }
    /* cout << "dfs done" << endl; */

    counter++;
    vi count(counter);
    rep(i, n){
        count[visited[i]]++;
    }

    int total = nc2(n);

    rep(i, counter){
        total -= nc2(count[i]);
    }

    cout << total << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
