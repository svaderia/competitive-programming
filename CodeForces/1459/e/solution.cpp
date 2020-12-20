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

    vvi a(n, vi(n));
    rep(i, n){
        rep(j, n){
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    vii init = {{0, 0}, {0, 1}, {0, 2}};

    string s;
    cin >> s;

    rep(i, m){
        if(s[i] == 'R'){
            init[1].f++;
        }else if(s[i] == 'L'){
            init[1].f--;
        }else if(s[i] == 'U'){
            init[0].f--;
        }else if(s[i] == 'D'){
            init[0].f++;
        }else if(s[i] == 'I'){
            swap(init[1], init[2]);
        }else{
            swap(init[0], init[2]);
        }
    }

    vvi ans(n, vi(n));
    int arr[3];
    rep(i, n){
        rep(j, n){
            arr[0] = i, arr[1] = j, arr[2] = a[i][j];
            int nx = (n + (arr[init[0].s] + init[0].f) % n) % n;
            int ny = (n + (arr[init[1].s] + init[1].f) % n) % n;
            int k = (n + (arr[init[2].s] + init[2].f) % n) % n;
            ans[nx][ny] = k;
        }
    }
    rep(i, n){
        rep(j, n){
            cout << ans[i][j] + 1 << spc;
        }
        cout << endl;
    }

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
