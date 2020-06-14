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
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {it++;}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...); }

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

enum happ{
    swim, 
    bugs,
    homework
};

void solve(){
    int n;
    cin >> n;
    vector<vi> arr(n, vi(3, 0));
    rep(i, n){
        cin >> arr[i][swim] >> arr[i][bugs] >> arr[i][homework];
    }

    vector<vi> dp(n, vi(3, 0));
    vi activity = {swim, bugs, homework};
    for(auto act : activity){
        dp[0][act] = arr[0][act];
    }
    
    repA(i, 1, n - 1){
        for(auto act : activity){
            for(auto prev_act : activity){
                if(act != prev_act)
                    dp[i][act] = max(dp[i][act], dp[i - 1][prev_act] + arr[i][act]);
            }
        }
    }
    cout << max({dp[n - 1][swim], dp[n - 1][bugs], dp[n - 1][homework]}) << endl;
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    solve();

    return 0;
}
