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

void solve(){
    int n, m;
    cin >> n >> m;
    vector<OrderedSet> ss(n);
    vector<vi> t(n);
    rep(i, m){
        int x, y;
        cin >> x >> y;
        t[x - 1].pb(y - 1);
        t[y - 1].pb(x - 1);
    }
    vii order;
    rep(i, n){
        int temp;
        cin >> temp;
        order.eb(mp(temp - 1, i));
    }
    sort(all(order));
    vi ans;
    int pos = true;
    vector<bool> assigned(n, false);

    rep(i, n){
        int curr = order[i].first;
        int node = order[i].second;
        if(int(ss[node].order_of_key(curr)) != curr || present(ss[node], curr) ){
            pos = false;
            break;
        }
        ans.pb(node + 1);
        assigned[node] = true;
        for(auto neb : t[node]){
            if(!assigned[neb])
                ss[neb].insert(curr);
        }
    }
    if(pos){
        rep(i, n){
            cout << ans[i] << " ";
        }
        cout << endl;
    }else{
        cout << -1 << endl;
    }
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    solve();

    return 0;
}
