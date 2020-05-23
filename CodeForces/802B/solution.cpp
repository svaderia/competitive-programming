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

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int N, K;
    cin >> N >> K;
    int ans;
    ans = 0;

    vi arr(N);
    rep(i, N){
        cin >> arr[i];
        arr[i]--;
    }

    vi used(N, N + 1);
    vi next_used(N);

    repD(i, N - 1, 0){
        next_used[i] = used[arr[i]];
        used[arr[i]] = i;
    }

    set<int> curr;
    priority_queue<pii> pq;
    rep(i, N){
        if(!present(curr, arr[i])){
            ans++;
            if(sz(curr) == K){
                pii p = pq.top();
                pq.pop();
                curr.erase(p.second);
            }
            curr.insert(arr[i]);
        }
        pq.push({next_used[i], arr[i]});
    }

    cout << ans << endl;

    return 0;
}
