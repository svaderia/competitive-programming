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
    
    int N;
    cin >> N;
    vi arr(N);
    rep(i, N){
        cin >> arr[i];
    }
    stack<int> s;
    vii ans;
    int prev_bin = 0;
    rep(i, N){
        if(arr[i] > prev_bin){
            int diff = arr[i] - prev_bin;
            while(diff--){
                s.push(i);
            }
        }else if(arr[i] < prev_bin){
            int diff = prev_bin - arr[i];
            while(diff--){
                int start = s.top();
                s.pop();
                ans.pb({start, i - 1});
            }
        }
        prev_bin = arr[i];
    }
    while(!s.empty()){
        int start = s.top();
        s.pop();
        ans.pb({start, N - 1});
    }
    cout << sz(ans) << endl;
    for(auto x : ans){
        cout << x.first + 1 << " " << x.second + 1 << endl;
    }



    return 0;
}
