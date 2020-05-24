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

int N;
const int MAXN = 505;
int paths[MAXN][MAXN];
int val[MAXN][MAXN];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y){
    int z = paths[x][y] + val[x][y];

    rep(i, 4){
        int nx = x + dx[i], ny = y + dy[i];
        if(paths[nx][ny] > z){
            paths[nx][ny] = z;
            dfs(nx, ny);
        }
    }
}


signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    cin >> N;
    int n2 = N * N;
    vi perm(n2);
    rep(i, n2){
        cin >> perm[i];
        perm[i]--;
    }

    repA(i, 1, N){
        repA(j, 1, N){
            paths[i][j] = min({i - 1, j - 1, N - i, N - j});
            val[i][j] = 1;
        }
    }
    int ans = 0;
    rep(i, n2){
        int x = (perm[i] / N) + 1;
        int y = (perm[i] % N) + 1;
        ans += paths[x][y];
        val[x][y] = 0;
        dfs(x, y);
    }

    cout << ans << endl;

    return 0;
}
