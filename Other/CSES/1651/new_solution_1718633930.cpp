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

struct node{
    int data;
    int delta;
    bool lazyset;
    node(int val) : data(val) , delta(0), lazyset(false) {}
    node() {}
}typedef node;

string to_string(node c) {
    return to_string(c.data);
}

struct seg_tree_lazy{
    typedef node T;

private:
    int n;
    vi lo, hi;
    vector<T> seg;

    T unit = T(0); 
    T merge(T a, T b) {
        return T(a.data + b.data);
    } // any associatinve function

    inline void pull(int id){
        seg[id] = merge(seg[2 * id], seg[2 * id + 1]);
    }

    inline void update_lazy(int id, int val){
        seg[id].data += (hi[id] - lo[id] + 1) * val;
    }

    // supports both range_increase and range_set together.
    // lazyset bool is used to differentiate between set and increase
    void push(int id){
        if(lo[id] != hi[id]){
            int left = 2 * id, right = left + 1;
            if(seg[id].lazyset){
                seg[left].lazyset = seg[right].lazyset = true;
                seg[left].delta = seg[right].delta = seg[left].data = seg[right].data = 0;
            }
            seg[left].delta += seg[id].delta;
            seg[right].delta += seg[id].delta;
            update_lazy(left, seg[id].delta);
            update_lazy(right, seg[id].delta);
        }
        seg[id].lazyset = false;
        seg[id].delta = 0;
    }

public:
    void build(int id, int l, int r){
        lo[id] = l, hi[id] = r;
        if(l == r) return;
        int mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id, mid + 1, r);
    }

    void build(int id, int l, int r, vi &arr){
        lo[id] = l, hi[id] = r;
        if(l == r){
            seg[id] = T(arr[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id, l, mid, arr);
        build(2 * id + 1, mid + 1, r, arr);
        pull(id);
    }

    T query(int l, int r, int id = 1){
        // outside
        if(lo[id] > r || hi[id] < l)
            return unit;

        push(id);

        if(l <= lo[id] && hi[id] <= r)
            return seg[id];

        T lquery = query(l, r, 2 * id);
        T rquery = query(l, r, 2 * id + 1);
        pull(id);

        return  merge(lquery, rquery);
    }

    void range_increase(int l, int r, int val, int id = 1){
        // outside
        if(lo[id] > r || hi[id] < l) return;

        if(l <= lo[id] && hi[id] <= r){
            seg[id].delta += val;
            update_lazy(id, val);
            return;
        }

        push(id);
        range_increase(l, r, val, 2 * id);
        range_increase(l, r, val, 2 * id + 1);
        pull(id);
    }

    void range_set(int l, int r, int val, int id = 1){
        // outside
        if(lo[id] > r || hi[id] < l) return;

        if(l <= lo[id] && hi[id] <= r){
            seg[id].data = 0;
            seg[id].delta = val;
            seg[id].lazyset = true;
            update_lazy(id, val);
            return;
        }

        push(id);
        range_set(l, r, val, 2 * id);
        range_set(l, r, val, 2 * id + 1);
        pull(id);
    }

    void set(int p, int val, int id = 1){
        // No overlap
        if(p < lo[id] || p > hi[id])
            return;

        if(lo[id] == hi[id]){
            seg[id] = val;
            return;
        }

        push(id);
        set(p, val, 2 * id);
        set(p, val, 2 * id + 1);
        pull(id);
    }

    seg_tree_lazy(int nn, T def) : n(nn), lo(4 * n), hi(4 * n), seg(4 * n, def) { build(1, 0, n - 1); }
    seg_tree_lazy(int nn) : n(nn), lo(4 * n), hi(4 * n), seg(4 * n)  { build(1, 0, n - 1); }
    seg_tree_lazy(vi &arr) : n(sz(arr)), lo(4 * n), hi(4 * n), seg(4 * n)  { build(1, 0, n - 1, arr); }

};

// clang-format on
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
            int x, y, val;
            cin >> x >> y >> val;
            x--, y--;
            s.range_increase(x, y, val);
        }else{
            int k;
            cin >> k;
            k--;
            cout << s.query(k, k).data << endl;
        }
    }
}

signed main(){
    fastio;

    solve();

    return 0;
}
