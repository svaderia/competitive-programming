//https://codeforces.com/contest/1365/problem/F
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
void err(istream_iterator<string> it) {it++;}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...); }
#else
#define error(args...)
#endif
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    rep(i, n){
        cin >> a[i];
    }
    rep(i, n){
        cin >> b[i];
    }

    bool ans = true;
    if(n % 2 == 1){
        int mid = (n) / 2;
        if(a[mid] != b[mid]){
            ans = false;
        }
    }
    map<pii, int> s;
    rep(i, n / 2){
        int j = n - 1 - i;
        int x = a[i], y = a[j];
        if(x > y) swap(x, y);
        s[mp(x, y)]++;
    }
    rep(i, n / 2){
        int j = n - 1 - i;
        int x = b[i], y = b[j];
        if(x > y) swap(x, y);
        if(s[mp(x, y)] <= 0){
            ans = false;
            break;
        }
        s[mp(x, y)]--;
    }

    cout << (ans ? "yes" : "No") << endl;
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
