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
// Remove this when it's an interactive problem
#define endl "\n"
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

void solve(){
    string s;
    cin >> s;

    int n = sz(s);

    vvi dp(n, vi(n));
    rep(i, n){
        repA(j, 0, i - 1){
            int l = i - j;
            /* cout << i << spc << j << spc << s[i] << spc << s[j] << endl; */
            if(s[i] == '?'){
                dp[i][l] = 1;
            }else{
                if(s[j] == '?'){
                    dp[i][l] = 1;
                }else if(s[j] == s[i]){
                    dp[i][l] = 1;
                }
            }
        }
    }

    /* rep(i, n){ */
    /*     rep(j, n){ */
    /*         cout << dp[i][j] << spc; */
    /*     } */
    /*     cout << endl; */
    /* } */


    int mx = 0;
    repA(l, 1, n - 1){
        int c = 0;
        rep(i, n){
            if(dp[i][l] == 1){
                c++;
            }else{
                if(c >= l){
                    mx = max(mx, l);
                }
                c = 0;
            }
        }
        if(c >= l){
            mx = max(mx, l);
        }
    }

    cout << 2 * mx << endl;



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
