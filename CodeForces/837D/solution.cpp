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

const int MAXX = 5005;
const int MAXK = 202;
int dp[MAXK][MAXX];
int sdp[MAXK][MAXX];

inline void self_max(int &a, int b){
    a = max(a, b);
}

void solve(){
    int n, k;
    cin >> n >> k;

    vi arr(n);
    vi twos(n), fives(n);
    rep(i, n){
        cin >> arr[i];
         while(arr[i] && arr[i] % 2 == 0){
            twos[i]++;
            arr[i] /= 2;
        }
        while(arr[i] && arr[i] % 5 == 0){
            fives[i]++;
            arr[i] /= 5;
        }
    }

    memset(dp, -1, (k + 1) * sizeof(dp[0]));

    dp[0][0] = 0;
    dbg(twos, fives);

    rep(i, n){
        memset(sdp, -1, (k + 1) * sizeof(sdp[0]));
        repA(ks, 1, k){
            rep(x, MAXX){
                if(dp[ks - 1][x] != -1){
                    self_max(sdp[ks][x + fives[i]], twos[i] + dp[ks - 1][x]);
                    self_max(sdp[ks][x], dp[ks - 1][x]);
                }
            }
        }
        repA(ks, 1, k){
            rep(x, MAXX){
                self_max(dp[ks][x], sdp[ks][x]);
            }
        }
    }

    int ans = 0;
    rep(x, MAXX){
        self_max(ans, min(x, dp[k][x]));
    }

    cout << ans << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
