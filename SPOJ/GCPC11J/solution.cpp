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

vector<vi> g;
vi mx;
int dia;

void dfs(int root, int p){
    int m1 = 0, m2 = 0;
    for(auto child : g[root]){
        if(child != p){
            dfs(child, root);
            if(mx[child] >= m1){
                m2 = m1; m1 = mx[child];
            }else if(mx[child] > m2){
                m2 = mx[child];
            }
        }
    }
    mx[root] = 1 + m1;
    dia = max(dia, m1 + m2 + 1);
    error(root, m1, m2, dia);
}

void solve(){
    int n;
    cin >> n;
    g.clear();
    mx.clear();
    g.resize(n); mx.resize(n, 0);
    rep(i, n - 1){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dia = 0;
    dfs(0, 0);

    cout << (dia)/2 << endl;
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

