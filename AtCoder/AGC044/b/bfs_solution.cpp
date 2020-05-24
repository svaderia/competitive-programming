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

void childs(int num, vi &child){
    int row = num / N;
    int col = num % N;
    if(row > 0){
        child.pb((row - 1)* N + col);
    }
    if(row < N - 1){
        child.pb((row + 1) * N + col);
    }
    if(col > 0){
        child.pb(row * N + col - 1);
    }
    if(col < N - 1){
        child.pb(row * N + col + 1);
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

    vi paths(n2);
    rep(i, n2){
        int row = i / N;
        int col = i % N;
        paths[i] = min({row, N - 1 - row, col, N - 1 - col});
    }

    int ans = 0;
    vi vals(n2, 1);

    queue<int> q;
    for(auto p : perm){
        ans += paths[p];
        vals[p] = 0;
        q.push(p);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            vi child;
            childs(x, child);
            for(auto c : child){
                if(paths[c] > vals[x] + paths[x]){
                    paths[c] = vals[x] + paths[x];
                    q.push(c);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
