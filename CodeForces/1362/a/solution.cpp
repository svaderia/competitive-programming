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
    int a, b;
    cin >> a >> b;
    int aa = 0;
    int bb = 0;
    while((a & 1) <= 0){
        a = a >> 1;
        aa++;
    }

    while((b & 1) <= 0){
        b = b >> 1;
        bb++;
    }

    if(a == b){
        int shift = abs(aa - bb);
        int ans = 0;
        ans += shift / 3;
        shift %= 3;
        ans += shift / 2;
        shift %= 2;
        ans += shift;
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
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
