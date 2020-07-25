#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
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

int n, l, k;
set<pii> visited;

bool dfs(int place, int tide, vi &d, vi &p){
    tide++;
    tide %= (2 * k);
    if(place == n + 1) return true;
    if(present(visited, mp(place, tide))) return false;
    visited.insert(mp(place, tide));
    if(d[place] + p[tide] > l) return false;
    return dfs(place + 1, tide, d, p) || dfs(place, tide, d, p);
}

void solve(){
    cin >> n >> k >> l;
    vi d(n + 1);
    repA(i, 1, n){
        cin >> d[i];
    }
    d[0] = -k;
    vi p;
    rep(i, k + 1){
        p.pb(i);
    }
    repD(i, k - 1, 1){
        p.pb(i);
    }

    visited.clear();
    bool ans = dfs(0, 0, d, p);
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;

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

