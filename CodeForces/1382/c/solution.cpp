#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD    = 1e9 + 7;
const double PI = acos(-1.0);

#define fastio            ios_base::sync_with_stdio(false);cin.tie(0)
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

void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    rep(i, n){
        char x;
        cin >> x;
        a[i] = x - '0';
    }
    rep(i, n){
        char x;
        cin >> x;
        b[i] = x - '0';
    }
    vi ans;
    int dir = 1;
    int val[2] = {0, n - 1};
    int cnt = 0;
    repD(len, n - 1, 0){
        error(len, dir, val[0],val[1], a[val[dir]], cnt);
        if((a[val[dir]] ^ (cnt % 2 ? 1 : 0)) != b[len]){
            if((a[val[1 - dir]] ^ (cnt % 2 ? 1 : 0)) == b[len]){
                ans.pb(1);
            }
            dir = (1 - dir);
            cnt++;
            error(cnt);
            ans.pb(abs(val[0] - val[1]) + 1);
            if(dir) val[dir]--;
            else val[dir]++;
        }
        else{
            if(dir) val[dir]--;
            else val[dir]++;
        }
    }

    cout << sz(ans) << " ";
    for(auto x : ans){
        cout << x << " ";
    }
    cout << endl;
}

signed main(){
    #ifdef DEBUG
        freopen("test", "r", stdin);
    #endif
    fastio;

    int T;
    cin >> T;

    repA(tc, 1, T){
        solve();
    }

    return 0;
}

