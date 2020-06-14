#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define int lli
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
#define error_old(x) cerr << #x << " = " << (x) << endl
#define errorp(p) cerr << #p << " = " << (p.first) << ", " << (p.second) << endl
#ifdef DEBUG
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {it++;}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...); }
#else
#define error(args...)
#endif

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

const int MAXV = 1e5 + 5;

void solve(){
    int n, W;
    cin >> n >> W;

    vi w(n), v(n);
    rep(i, n){
        cin >> w[i] >> v[i];
    }

    vi dp(MAXV, MOD);
    dp[0] = 0;
    rep(i, n){
        vi sdp(MAXV, MOD);     
        rep(val, MAXV){
            if(dp[val] != MOD && dp[val] + w[i] <= W){
                sdp[val + v[i]] = min(dp[val + v[i]], dp[val] + w[i]);
                error(val, dp[val], v[i], w[i]); 
            }
        }
        rep(val, MAXV){
            dp[val] = min(dp[val], sdp[val]);
        }
    }
    int ans = -1;
    rep(i, MAXV){
        if(dp[i] != MOD){
            ans = i;
        }
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
