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

vi flow_start;
vi flow_end;
vi prefSum;
int N, h;

bool cost(int start, int curr, int start_pos){
    int pos = upper_bound(all(flow_end), curr) - flow_end.begin();
    if(pos > 0) pos--;
    int height = h - (curr - start) + prefSum[pos];
    if(start_pos > 0)
        height -= prefSum[start_pos - 1];
    if(pos < N - 1 && curr > flow_start[pos + 1]){
        height += curr - flow_start[pos + 1];
    }
    return height <= 0;
}


signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    cin >> N >> h;
    prefSum.resize(N);
    flow_start.resize(N);
    flow_end.resize(N);

    rep(i, N){
        cin >> flow_start[i] >> flow_end[i];
    }

    prefSum[0] = flow_end[0] - flow_start[0];

    repA(i, 1, N - 1){
        prefSum[i] = prefSum[i - 1] + flow_end[i] - flow_start[i];
    }

    int ans = 0;
    for(int start : flow_start){
        int x = start - 1;
        int start_pos = lower_bound(all(flow_start), start) - flow_start.begin();
        for(int b = 2e9 + 5; b >= 1; b /= 2){
            while(!cost(start, x + b, start_pos)) x += b;
        }
        int end = x + 1;
        ans = max(ans, end - start);
    }

    cout << ans << endl;


    return 0;
}
