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
void err(istream_iterator<string> it) {it++; cout << endl;}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << " [ "<< *it << " : " << a << " ] "; err(++it, args...); }
#else
#define error(args...)
#endif
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

int n;
const int nax = 17;
int a[nax][nax];
vi dp, pre;

void rec(int idx, vi& not_taken, int score_so_far, int mask, int group){
    if(idx == sz(not_taken)){
        
        dp[mask] = max(dp[mask], score_so_far + pre[group]);
        return;
    }

    rec(idx + 1, not_taken, score_so_far, mask, group);
    rec(idx + 1, not_taken, score_so_far, mask | (1 << not_taken[idx]), group | (1 << not_taken[idx]));
}


void solve(){
    cin >> n;
    rep(i, n){
        rep(j, n){
            cin >> a[i][j];
        }
    }

    int maxn = (1 << n);
    dp.resize(maxn);

    pre.resize(maxn);
    repA(mask, 0, maxn - 1){
        rep(i, n){
            if((mask & (1 << i)) != 0){
                repA(j, i + 1, n - 1){
                    if((mask & (1 << j)) != 0){
                        pre[mask] += a[i][j];
                    }
                }
            }
        }
    }

    rep(mask, maxn){
        vi not_taken;
        rep(i, n){
            if((mask & (1 << i)) == 0){
                not_taken.pb(i);
            }
        }
        rec(0, not_taken, dp[mask], mask, 0);
    }

    cout << dp[maxn - 1] << endl;

}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    solve();

    return 0;
}
