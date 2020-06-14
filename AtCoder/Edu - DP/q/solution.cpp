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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet; // order_of_key find_by_order

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(false);cin.tie(0)
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
#define error_old(x) cerr << #x << " = " << (x) << endl
#define errorp(p) cerr << #p << " = " << (p.first) << ", " << (p.second) << endl
#ifdef DEBUG
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {it++; cout << endl;}
template<typename T, typename... Args> void err(istream_iterator<string> it, T a, Args... args) { cerr << " [ " << *it << " = " << a << " ] "; err(++it, args...); }
#else
#define error(args...)
#endif
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

struct node{
    lli data;

    void assign(lli val){
        data = val;
    }
}typedef node;

vector<node> seg;
int N;
vli dp;

//Complexity: O(1)
//Stores what info. segment[i..j] should store
node merge(node &left, node &right){
    node temp;
    temp.data = max(left.data, right.data);
    return temp;
}

//Complexity: O(n)
void build(int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        //base case : leaf node information to be stored here
        seg[id].assign(dp[l]);
        return;
    }

    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    build(left, l, mid);
    build(right, mid, r);
    seg[id] = merge(seg[left], seg[right]);
}

//Complexity: O(log n)
void update(int p, int y, int id = 1, int l = 0, int r = N){
    if(r - l < 2){ 
        //base case : leaf node information to be stored here
        seg[id].assign(y);
        return;
    }

    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    if(p < mid){
        update(p, y, left, l, mid);
    }else{
        update(p, y, right, mid, r);
    }
    seg[id] = merge(seg[left], seg[right]);
}

//Complexity: O(log n)
node query(int x, int y, int id = 1, int l = 0, int r = N){
    if(r <= x || y <= l){ // No overlap, return useless
        node temp;
        temp.assign(0);
        return temp;
    }

    if(x <= l && r <= y){ // overlap
        return seg[id];
    }

    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    node a = query(x,  y, left, l, mid);
    node b = query(x, y, right, mid, r);
    return merge(a, b);
}


void solve(){
    int n;
    cin >> n;
    vi h(n);
    rep(i, n){
        cin >> h[i];
    }
    vi val(n);
    rep(i, n){
        cin >> val[i];
    }

    N = n + 1;
    dp.resize(N, 0);
    seg.resize(4 * N);
    build();

    rep(flower, n){
        int smax = query(0, h[flower]).data;
        dp[h[flower]] = max(dp[h[flower]], smax + val[flower]);
        update(h[flower], dp[h[flower]]);
    }

    // OrderedSet s;
    // rep(i, n){
    //     s.insert(a[i]);
    //     int it = s.order_of_key(a[i] + 1);
    //     dp[it] = max(dp[it], (it > 0 ? dp[it - 1] : 0) + val[i]);
    //     ans = max(ans, dp[it]);
    //     if(it != sz(s) + 1){
    //         s.erase(s.find_by_order(it));
    //     }
    //     error(a[i], it, dp[it], sz(s))
    // }

    int ans = 0;
    repA(i, 1, n){
        ans = max(ans, dp[i]);
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
