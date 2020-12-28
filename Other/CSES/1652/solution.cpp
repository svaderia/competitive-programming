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

    int n, q;
    cin >> n >> q;

    vector<string> s(n);
    rep(i, n){
        cin >> s[i];
    }

    vvi pref(n + 1, vi(n + 1));
    rep(i, n + 1){
        rep(j, n){
            pref[i][j + 1] = pref[i][j] + ((i > 0 && s[i - 1][j] == '*') ? 1 : 0);
        }
    }

    vvi ppref(n + 1, vi(n + 1));
    rep(j, n + 1){
        repA(i, 1, n){
            ppref[i][j] = ppref[i - 1][j] + pref[i][j];
        }
    }

    rep(i, q){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        x1--; y1--;
        int ans = ppref[x2][y2] - ppref[x1][y2] - ppref[x2][y1] + ppref[x1][y1];
        cout << ans << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
