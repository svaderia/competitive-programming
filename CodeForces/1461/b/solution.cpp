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

    vector<string> s(n);
    rep(i, n){
        cin >> s[i];
    }

    vvi pre(n, vi(m + 1));

    rep(i, n){
        rep(j, m){
            pre[i][j + 1] = pre[i][j] + (s[i][j] == '*' ? 1 : 0);
        }
    }

    int ans = 0;
    rep(x, n){
        rep(y, m){
            repA(k, 1, max(n, m)){
                int nx = x + k - 1;
                if(nx >= n) break;
                bool can = true;
                int ly = y - k + 1, ry = y + k - 1;
                if(ly < 0 || ry >= m) can = false;
                if(can && (pre[nx][ry + 1] - pre[nx][ly]) != (ry - ly + 1)) can = false;
                if(!can) break;
                ans++;
            }
        }
    }

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
