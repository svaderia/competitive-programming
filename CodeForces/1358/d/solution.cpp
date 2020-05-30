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

int f(int n){
    return ((n+1)*n)/2;
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    
    int n, x;
    cin >> n >> x;
    vi d(n);
    rep(i, n){
        cin >> d[i];
    }
    vi prefd(2 * n + 1, 0);
    rep(i, 2 * n){
        prefd[i + 1] = prefd[i] + d[i % n];
    }

    vi prefh(2 * n + 1, 0);
    rep(i, 2 * n){
        prefh[i + 1] = prefh[i] + f(d[i % n]);
    }

    int ans = 0;
    rep(i, n){
        int idx = i + n;
        int d1 = d[i];
        int tans = f(d1);
        if(x <= d1){
            tans -= f(d1 - x);
        }else{
            int required_x = prefd[idx] - (x - d1);
            int pos = lower_bound(all(prefd), required_x) - prefd.begin();
            int days_spent = prefd[idx] - prefd[pos];
            int remaining = x - days_spent - d1;
            tans += prefh[idx] - prefh[pos];
            pos--;
            tans += f(d[pos % n]) - f(d[pos % n] - remaining);
        }
        ans = max(ans, tans);
    }
    cout << ans << endl;

    return 0;
}
