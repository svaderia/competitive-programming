//https://codeforces.com/contest/1363/problem/B
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

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0)
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
#define error(x) cerr << #x << " = " << (x) << endl
#define errorp(p) cerr << #p << " = " << (p.first) << ", " << (p.second) << endl

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

void solve(){
    int n;
    string s;
    cin >> s;
    n = sz(s);

    vi pref1(n + 1, 0);
    vi pref0(n + 1, 0);
    rep(i, n){
        pref1[i + 1] = pref1[i] + (s[i] == '1');
        pref0[i + 1] = pref0[i] + (s[i] == '0');
    }

    int ans = INT_MAX;
    rep(x, n + 1){
        ans = min(ans, pref0[x] - pref0[0] + pref1[n] - pref1[x]);
        ans = min(ans, pref1[x] - pref1[0] + pref0[n] - pref0[x]);
    }
    cout << ans << endl;
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        solve();
    }

    return 0;
}
