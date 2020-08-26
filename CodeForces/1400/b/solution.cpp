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

    int p, f;
    cin >> p >> f;
    int cs, cw;
    cin >> cs >> cw;
    int s, w;
    cin >> s >> w;
    if(s > w){
        swap(s, w);
        swap(cs, cw);
    }
    int tt = p + f;
    int tm1 = min(cs, (tt) / s);
    
    int ans = 0;
    repA(c1, 0, tm1){
        int c2 = tm1 - c1;
        if(c2 * s > f) c2 = f / s;
        if(c1 * s > p) break;
        int y1 = min(max(0LL, (p - s * c1) / w), cw);
        int y2 = min(max(0LL, (f - s * c2) / w), cw - y1);
        ans = max(ans, c1 + c2 + y1 + y2);
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

