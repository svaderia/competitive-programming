//https://codeforces.com/contest/460/problem/C
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

int n, m, w;
vi arr;

bool ok(int fin){
    vi diff(n + 1, 0);
    int curr = 0;
    int ans = 0;
    rep(i, n){
        curr += diff[i];
        if(arr[i] + curr < fin){
            int st = (fin - arr[i] - curr);
            ans += st;
            curr += st;
            diff[i] += st;
            diff[min(i + w, n)] -= st;
        }
    }
    return ans <= m;
}

void solve(){
    cin >> n >> m >> w;
    arr.resize(n);
    rep(i, n){
        cin >> arr[i];
    }
    int r = 2e9;
    int mh = -1;
    for(int x = r; x >= 1; x/=2){
        while(ok(mh + x)) mh += x;
    }
    cout << mh << endl;
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    solve();

    return 0;
}
