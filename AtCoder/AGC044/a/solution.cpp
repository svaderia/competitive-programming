#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet;

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

unordered_map<int, int> dp;
int A, B, C, D;

int cost(int n){
    if (n == 0) return 0;
    if(n == 1) return D;
    if(dp[n]) return dp[n];

    int ans = 1e18;
    if(n < ans / D) ans = n * D;
    
    int l2 = (n /2) * 2;
    int r2 = ((n + 1)/2) * 2;

    int l3 = (n/3)*3;
    int r3 = ((n + 2)/3) * 3;

    int l5 = (n/5)*5;
    int r5 = ((n+4)/5)*5;

    ans = min(ans, abs(l2 - n) * D + A + cost(l2 / 2));
    ans = min(ans, abs(r2 - n) * D + A + cost(r2 / 2));

    ans = min(ans, abs(l3 - n) * D + B + cost(l3 / 3));
    ans = min(ans, abs(r3 - n) * D + B + cost(r3 / 3));

    ans = min(ans, abs(l5 - n) * D + C + cost(l5 / 5));
    ans = min(ans, abs(r5 - n) * D + C + cost(r5 / 5));

    dp[n] = ans;
    return ans;
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        int N;
        cin >> N;
        cin >> A >> B >> C >> D;
        dp[1] = D;
        cout << cost(N) << endl;
        dp.clear();
    }

    return 0;
}
