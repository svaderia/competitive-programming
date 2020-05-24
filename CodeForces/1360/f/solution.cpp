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

int n, m;
vector<string> s;


int diff(string &a, string &b){
    int diff = 0;
    rep(i, m){
        if(a[i] != b[i])
            diff++;
    }
    return diff;
}

bool check(string ans){
    bool pos = true;
    rep(i, n){
        if(diff(s[i], ans) > 1){
            pos = false;
        }
    }
    return pos;
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        cin >> n >> m;
        s.resize(n);
        rep(i, n){
            cin >> s[i];
        }
        string ans = s[0];
        if(check(ans)){
            cout << ans << endl;
            
        }else{
            bool found = false;
            rep(p, m){
                rep(c, 26){
                    char ch = 'a' + c;
                    ans[p] = ch;
                    if(check(ans)){
                        found = true;
                        break;
                    }
                }
                if(found){
                    break;
                }
                ans[p] = s[0][p];
            }
            if(found){
                cout << ans << endl;
            }else{
                cout << -1 << endl;
            }
            // cout << s[0] << endl;
        }
    }

    return 0;
}
