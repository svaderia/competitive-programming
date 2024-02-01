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
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
const int INF   = 1e18;

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

bool check(vi &a){
    int n = sz(a);
    bool can = true;
    vb vis(n + 1, false);
    rep(i, n - 1){
        if(a[i] & a[i + 1]); else can = false;
        if(vis[a[i]]) can = false;
        vis[a[i]] = true;
    }
    return can;
}

vi tans[8];

void prepare(){
    tans[5] = {4, 5, 1, 3, 2};
    tans[7] = {4, 5, 6, 7, 1, 3, 2};
}

void solve(){

    int n;
    cin >> n;

    if(n == 1){
        cout << 1 << endl;
        return;
    }

    if(__builtin_popcountll(n) != 1){
        int mx = 1;
        while(mx < n){
            mx = mx << 1;
        }
        mx = mx >> 1;
        vi ans;
        repA(i, mx, n){
            ans.pb(i);
        }

        while(mx > 1){
            int temp = n - mx;
            temp |= mx >> 1;
            ans.pb(temp);
            repA(i, mx >> 1, mx - 1){
                if(i != temp) ans.pb(i);
            }
            mx = mx >> 1;
            n = mx;
        }

        if(sz(ans) == 5 || sz(ans) == 7){
            ans = tans[sz(ans)];
        }

        // assert(check(ans));

        for(auto x : ans){
            cout << x << spc;
        }
        cout << endl;

    }
    else{
        cout << -1 << endl;
    }

}

signed main(){
    fastio;

    int T;
    cin >> T;

    prepare();

    repA(tc, 1, T){
        solve();
    }

    return 0;
}
