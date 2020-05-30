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

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        double h, c, t;
        cin >> h >> c >> t;
        double min = (h + c) / 2;
        if(t <= min){
            cout << 2 << endl;
        }else if(t >= h){
            cout << 1 << endl;
        }else{
            double x = (t - h) / (c + h - 2 * t);
            int x1 = int(ceil(x));
            int x2 = int(floor(x));
            double m1 = (x1 + 1) * h + x1 * c;
            m1 /= (2 * x1 + 1);
            double m2 = (x2 + 1) * h + x2 * c;
            m2 /= (2 * x2 + 1);
            if(abs(t - m1) < abs(t - m2)){
                cout << 2 * x1 + 1 << endl;
            }else{
                cout << 2 * x2 + 1 << endl;
            }
        }
    }

    return 0;
}
