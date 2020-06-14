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

const int nax = 3005;
int dp[nax][nax][2];
int val[nax];

int rec(int i, int j, int who){
    if(dp[i][j][who] != -1){
        return dp[i][j][who];
    }
    if(i > j){
        return 0;
    }

    if(who){
        dp[i][j][who] = min(rec(i + 1, j, 1 - who) - val[i], rec(i, j - 1, 1 - who) - val[j]);
    }else{
        dp[i][j][who] = max(rec(i + 1, j, 1 - who) + val[i], rec(i, j - 1, 1 - who) + val[j]);
    }

    return dp[i][j][who];
}

void solve(){
    // dp[i][j][who] : substring [i, j] and it is turn of who;
    int n;
    cin >> n;
    rep(i, n){
        cin >> val[i];
    }
    rep(i, n){
        rep(j, n){
            rep(who, 2){
                dp[i][j][who] = -1;
            }
        }
    }

    cout << rec(0, n - 1, 0) <<  endl;
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    solve();

    return 0;
}
