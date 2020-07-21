#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD    = 1e9 + 7;
const double PI = acos(-1.0);

#define fastio            ios_base::sync_with_stdio(false);cin.tie(0)
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

unordered_map<int, int> pos;
int val;
int n;

void recur(vi &p, vi &arr, int len){
    if(len == 0) return;
    else if(len == 1) arr.pb(1);
    else{
        while(pos[val] > len && val > 0){
            val--;
        }
        int new_div = (len - pos[val] + 1);
        arr.pb(new_div);
        recur(p, arr, pos[val] - 1);
    }
}

void solve(){
    cin >> n;
    vi p(2 * n);
    vi arr;
    pos.clear();
    rep(i, 2*n){
        cin >> p[i];
        pos[p[i]] = i + 1;
    }
    val = 2 * n;
    recur(p, arr, 2 * n);
    vi dp(n + 1);
    dp[0] = 1;
    for(auto x : arr){
        vi new_dp(n + 1);
        rep(i, n + 1){
            if(dp[i] == 1 && i + x <= n) new_dp[i + x] = 1;
        }
        rep(i, n + 1){
            if(new_dp[i]) dp[i] = 1;
        }
    }
    if(dp[n]) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main(){
    #ifdef DEBUG
        freopen("test", "r", stdin);
    #endif
    fastio;

    int T;
    cin >> T;

    repA(tc, 1, T){
        solve();
    }

    return 0;
}

