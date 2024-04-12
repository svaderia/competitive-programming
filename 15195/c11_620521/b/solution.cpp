#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD   = 1e9 + 7;
const double PI = acos(-1.0);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const lli INF   = 1e18;

#define fastio            ios_base::sync_with_stdio(false);cin.tie(0)
#define sz(a) int((a).size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define f first
#define s second
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
// Remove this when it's an interactive problem
/* #define endl "\n" */
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

char query(int a, int b, int c, int d){
    cout << "?" << spc << a << spc << b << spc << c << spc << d << endl;
    cout.flush();
    char cr;
    cin >> cr;
    return cr;
}

void solve(){

    int n;
    cin >> n;


    // 1. find the index of n - 1
    int mx = 0;
    rep(i, n){
        char c = query(mx, mx, i, i);

        if (c == '<'){
            mx = i;
        }
    }

    // 2. find the indices i, such that mx | i is maximum
    vi curr;
    int x = 0;
    rep(i, n){
        char c = query(mx, x, mx, i);

        if( c == '='){
            curr.pb(i);
        }else if(c == '<'){
            vi ncurr;
            ncurr.pb(i);
                curr = ncurr;
            x = i;
        }
    }
    
    // find the min out of curr
    int mn = curr[0];
    rep(j, sz(curr)){
        char c = query(mn, mn, curr[j], curr[j]);
        if(c == '>'){
            mn = curr[j];
        }
    }

    cout << '!' << spc << mx << spc << mn << endl;
    cout.flush();
}

signed main(){
    fastio;

    int T;
    cin >> T;

    repA(tc, 1, T){
        solve();
    }

    return 0;
}
