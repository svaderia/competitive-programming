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

pair<int, string> lcs(string &s, string &t){
    int n = sz(s), m = sz(t);
    vector<vi> dp(n, vi(m, 0));
    vector<vi> jump(n, vi(m, -1));

    rep(i, n){
        rep(j, m){
            if(s[i] == t[j]){
                dp[i][j] = 1;
                if(i > 0 && j > 0){
                    dp[i][j] += dp[i - 1][j - 1];
                }
                jump[i][j] = 0;
            }else{
                if(j > 0){
                    if(dp[i][j] < dp[i][j - 1]){
                        dp[i][j] = dp[i][j - 1];
                        jump[i][j] = 1;
                    }
                }
                if(i > 0){
                    if(dp[i][j] < dp[i - 1][j]){
                        dp[i][j] = dp[i - 1][j];
                        jump[i][j] = 2;
                    }
                }
            }
        }
    }
    string lcsStr;
    int l = n - 1, r = m - 1;
    while(l >= 0 && r >= 0 && jump[l][r] != -1){
       if(jump[l][r] == 1){
           r--;
       }else if(jump[l][r] == 2){
           l--;
       }else if(jump[l][r] == 0){
           lcsStr.pb(s[l]);
           l--; r--;
       }
    }
    reverse(all(lcsStr));
    return {dp[n - 1][m - 1], lcsStr};
}

void solve(){
    string s, t;
    cin >> s >> t;
    cout << lcs(s, t).second << endl;
    // cout << lcs(s, t).first << endl;

}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    solve();

    return 0;
}
