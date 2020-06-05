//https://codeforces.com/contest/1363/problem/E
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

int n;
vector<vi> fin_vert;
vi a, b, c;
vector<vi> desire;
int ans;

void dfs(int root, int min_cost_par){
    for(auto child : fin_vert[root]){
        dfs(child, min(min_cost_par, a[root]));
        desire[root][0] += desire[child][0];
        desire[root][1] += desire[child][1];
    }
    if(b[root] != c[root]){
        desire[root][c[root]] += 1;
    }
    if(a[root] < min_cost_par){
        int r = min(desire[root][0], desire[root][1]);
        ans += a[root] * 2 * r;
        desire[root][0] -= r;
        desire[root][1] -= r;
    }
}


void solve(){
    cin >> n;
    fin_vert.resize(n); a.resize(n); b.resize(n); c.resize(n);
    rep(i, n){
        cin >> a[i] >> b[i] >> c[i];
    }
    desire.resize(n, vi(2, 0));
    
    int N = n;
    vi vert[N];
    int x, y;
    rep(i, N - 1){
        cin >> x >> y;
        vert[x-1].push_back(y-1);
        vert[y-1].push_back(x-1);
    }

    queue<int> q;
    vi visited(N, 0);
    q.push(0);

    visited[0] = true;

    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto it : vert[top]){
            if(visited[it] != true){
                q.push(it);
                fin_vert[top].pb(it);
                visited[it] = true;
            }
        }
    }

    ans = 0;
    dfs(0, MOD);
    if(desire[0][0] == desire[0][1]){
        ans += a[0] * 2 * desire[0][0];
    }else{
        ans = -1;
    }
    cout << ans << endl;
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    solve();

    return 0;
}
