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
// To enable recursive lambda
// refere : http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

void solve(){
    int n;
    cin >> n;

    vi par(n);
    rep(i, n){
        cin >> par[i];
        par[i]--;
    }

    vi ans(n, -1);
    vi visited(n, 0);
    vi cycle(n, -1);
    vi ids(n, -1);
    vi cycle_len;
    int cnum = 0;
    int id = 0;

    auto find_cycle = y_combinator([&] (auto ddfs, int root) -> void {
        visited[root] = 1;
        if(visited[par[root]] == 1){
            int start = par[root];
            cycle[root] = cnum;
            int l = 1;
            ids[root] = id++;
            while(start != root){
                ids[start] = id++;
                cycle[start] = cnum;
                start = par[start];
                l++;
            }
            cnum++;
            cycle_len.pb(l);
        } else if(visited[par[root]] == 0){
            ddfs(par[root]);
        }
        visited[root] = 2;
    });

    rep(i, n)
        if(visited[i] == 0) find_cycle(i);

    visited.clear();
    visited.rsz(n, 0);
    auto get_cycles = y_combinator([&] (auto dfs, int root) -> void {
        visited[root] = 1;
        int p = par[root];
        if(cycle[p] != -1){
            ans[root] = cycle_len[cycle[p]] + (cycle[root] == -1);
            return;
        }
        if(visited[p] == 0){
            dfs(p);
        }
        ans[root] = 1 + ans[p];
    });

    rep(i, n)
        if(visited[i] == 0) get_cycles(i);

    rep(i, n)
        cout << ans[i] << spc;

}

signed main(){
    fastio;

    solve();

    return 0;
}
