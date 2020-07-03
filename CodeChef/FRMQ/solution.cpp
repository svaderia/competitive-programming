#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(false);cin.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define endl "\n"
#define errorp(p) cerr << #p << " = " << (p.first) << ", " << (p.second) << endl
#ifdef DEBUG
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {it++; cout << endl;}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << " [ "<< *it << " : " << a << " ] "; err(++it, args...); }
#else
#define error(args...)
#endif
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

vi v;
int n; 
vector<vi> t;

#define op max
int msb(int x) { return __builtin_clz(1) - __builtin_clz(x); }

void solve(){
    cin >> n;
    v.resize(n);
    rep(i, n){
        cin >> v[i];
    }
    t.resize(n, vi(msb(n) + 1));
    for (int i = 0; i < n; i++) t[i][0] = v[i];
    for (int j = 1; (1<<j) <= n; j++) for (int i = 0; i+(1<<j) <= n; i++)
        t[i][j] = op(t[i][j - 1], t[i+(1<<(j-1))][j - 1]);
    int M, x, y;
    cin >> M >> x >> y;
    lli ans = 0;
    int tx = x; int ty = y;
    if(tx > ty) swap(tx, ty);
    int j = msb(ty-tx+1);
    ans += op(t[tx][j], t[ty-(1<<j)+1][j]);
    rep(i, M - 1){
        x += 7; while(x >= n - 1) x -= (n - 1);
        y += 11; while(y >= n) y -= n;
        tx = x; ty = y;
        if(tx > ty) swap(tx, ty);
        j = msb(ty-tx+1);
        ans += op(t[tx][j], t[ty-(1<<j)+1][j]);
    }
    cout << ans << endl;
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    solve();

    return 0;
}
