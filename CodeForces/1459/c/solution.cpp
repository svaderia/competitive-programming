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
#define endl "\n"
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

void solve(){
    int n, m;
    cin >> n >> m;

    set<int> s;
    rep(i, n){
        int x;
        cin >> x;
        s.insert(x);
    }
    vi a;
    for(auto x : s){
        a.pb(x);
    }

    vi b(m);
    rep(i, m){
        cin >> b[i];
    }

    vi d;
    rep(i, sz(a) - 1){
        d.pb(a[i + 1] - a[i]);
    }
    int gcdD = 0;

    if(sz(a) != 1)
        gcdD = d[0];

    for(auto x : d){
        gcdD = gcd(gcdD, x);
    }

    rep(i, m){
        cout << gcd(a[0] + b[i], gcdD) << spc;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
