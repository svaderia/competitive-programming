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
enum{ D, R, U, L};
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

const int n = 7;
string arr;
int ans = 0;
map<char, int> my;
int visited[n + 1][n + 1];

inline bool inside(int x, int y){
    if(x < 1 || x > 7 || y < 1 || y > 7) return false;
    return true;
}

/* we are effectively trying to prune the search as much as possible.
 * Here is a nice doc that explains it for this problem :
 *  https://usaco.guide/problems/cses-1625-grid-paths/solution
 */
void recur(int step, int x, int y){
    /* rep(i, 4){ */
    /*     if(inside(x + dx[i], y + dy[i]) && !visited[x + dx[i]][y + dy[i]]) pos[i] = true; */
    /*     else pos[i] = false; */
    /* } */
    /* if((!pos[D] && !pos[U] && pos[L] && pos[R]) || (pos[D] && pos[U] && !pos[L] && !pos[R])){ */
    /*     return; */
    /* } */

    // This is nothing but writing the above condition without using loops and extra variable
    if( ((x == 7 || visited[x + 1][y]) && (x == 1 || visited[x - 1][y]) && (y != 1 && !visited[x][y - 1]) && (y != 7 && !visited[x][y + 1]))  ||
        (!(x == 7 || visited[x + 1][y]) && !(x == 1 || visited[x - 1][y]) && !(y != 1 && !visited[x][y - 1]) && !(y != 7 && !visited[x][y + 1])))
        return;

    if(x == 7 && y == 1){
        /* dbg(step); */
        if(step == 48) ans++;
        return;
    }

    visited[x][y] = true;

    if(arr[step] == '?'){
        rep(c, 4){
            if(inside(x + dx[c], y + dy[c]) && !visited[x + dx[c]][y + dy[c]])
                recur(step + 1, x + dx[c], y + dy[c]);
        }
    } else{
        int c = my[int(arr[step])];
        if(inside(x + dx[c], y + dy[c]) && !visited[x + dx[c]][y + dy[c]])
            recur(step + 1, x + dx[c], y + dy[c]);
    }

    visited[x][y] = false;
}

void solve(){

    cin >> arr;
    my['U'] = U, my['R'] = R, my['L'] = L, my['D'] = D;

    recur(0, 1, 1);

    cout << ans << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
