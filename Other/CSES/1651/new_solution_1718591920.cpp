// clang-format off
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
// Remove this when it's an interactive problem
#define endl "\n"
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

// clang-format on
struct node {
    int data;
    int lazy;

    node(int d) : data(d), lazy(0) {}
    node() {}
} typedef node;


string to_string(node a){
  return to_string(a.data);
}

struct seg_tree_lazy{
    typedef node T;

private: 
    int n;
    vector<int> lo, hi;
    vector<T> seg;

    T uint = T(0);
    T merge(T a, T b){
        return a.data + b.data;
    }

    void pull(int id){
        seg[id] = merge(seg[2 * id], seg[2 * id + 1]);
    }


    void push(int id){
        // if not leaf node
        if(lo[id] != hi[id]){
            seg[2*id].lazy += seg[id].lazy;
            seg[2*id + 1].lazy += seg[id].lazy;
        }else{
            seg[id].data += seg[id].lazy;
        }
        seg[id].lazy = 0;

    }



public:

    seg_tree_lazy(vector<int> &arr) : n(sz(arr)), lo(4 * n), hi(4 * n), seg(4 * n){ build(0, n - 1, 1, arr); }


    void build(int l, int r, int id, vector<int> &arr){
        lo[id] = l, hi[id] = r;
        if(l == r){
            seg[id] = arr[l];
            return;
        }

        int mid = (l + r) / 2;
        build(l, mid, 2 * id, arr);
        build(mid + 1, r, 2 * id + 1, arr);

        pull(id);
    }

    T query(int l, int r, int id = 1){
        if(l > hi[id] || r < lo[id]){
            return uint;
        }
        push(id);

        if(l <= lo[id] && hi[id] <= r){
            return seg[id];
        }

        T lquery = query(l, r, 2 * id);
        T rquery = query(l, r, 2 * id + 1);

        return merge(lquery, rquery);
    }

    void set(int l, int r, int val, int id = 1){
        if(l > hi[id] || r < lo[id]){
            return;
        }
        push(id);

        if(l <= lo[id] && hi[id] <= r){
            seg[id].lazy += val;
            return;
        }
        set(l, r, val, 2 * id);
        set(l, r, val, 2 * id + 1);
    }
};

void solve(){
    int n, q;
    cin >> n >> q;

    vi a(n);
    rep(i, n){
        cin >> a[i];
    }

    seg_tree_lazy s(a);

    rep(i, q){
        int op;
        cin >> op;

        if(op == 1){
            int l, r, val;
            cin >> l >> r >> val;
            l--, r--;
            s.set(l, r, val);
        }else{
            int p;
            cin >> p;
            p--;
            cout << s.query(p, p).data << endl;
        }
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
