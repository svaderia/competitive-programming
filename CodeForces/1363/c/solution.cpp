//https://codeforces.com/contest/1363/problem/C
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
    int n, x;
    cin >> n >> x;
    x--;
    if(n == 1){
        cout << "Ayush" << endl;
        return;
    }
    vector<vi> t(n);
    rep(i, n - 1){
        int u, v;
        cin >> u >> v;
        u--; v--;
        t[u].pb(v);
        t[v].pb(u);
    }
    int fx = sz(t[x]);
    int remain = n - 2;
    if(fx == 1){
        cout << "Ayush" << endl;
    }else{
        if(remain % 2 == 0){
            cout << "Ayush" << endl;
        }else{
            cout << "Ashish" << endl;
        }
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
