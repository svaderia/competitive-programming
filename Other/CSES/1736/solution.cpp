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
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
const int INF   = 1e18;

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
#define endl "\n"
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

struct node{
    int data;
    node(int val) : data(val) {}
    node() {}
}typedef node;

string to_string(node c) {
    return to_string(c.data);
}

struct SegTree{
    typedef node T;

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
        update(id);
    }

    T query(int l, int r, int id = 1){
        // outside
        if(lo[id] > r || hi[id] < l)
            return unit;

        propagate(id);

        if(l <= lo[id] && hi[id] <= r)
            return seg[id];

        T leftQuery = query(l, r, 2 * id);
        T rightQuery = query(l, r, 2 * id + 1);
        update(id);

        return  merge(leftQuery, rightQuery);
    }

    void increase(int l, int r, int val, int id = 1){
        // outside
        if(lo[id] > r || hi[id] < l) return;

        if(l <= lo[id] && hi[id] <= r){
            cons[id] += val;
            mult[id]++;
            update_lazy(id, val, 1ll);
            return;
        }

        propagate(id);
        increase(l, r, val, 2 * id);
        increase(l, r, val, 2 * id + 1);
        update(id);
    }

    SegTree(int nn, T def) : n(nn), lo(4 * n), hi(4 * n), cons(4 * n), mult(4 * n), seg(4 * n, def) { build(1, 0, n - 1); }
    SegTree(int nn) : n(nn), lo(4 * n), hi(4 * n), cons(4 * n), mult(4 * n), seg(4 * n)  { build(1, 0, n - 1); }
    SegTree(vi &arr) : n(sz(arr)), lo(4 * n), hi(4 * n), cons(4 * n), mult(4 * n), seg(4 * n)  { build(1, 0, n - 1, arr); }

private:
    T unit = T(0);

    T merge(T a, T b) {
        return T(a.data + b.data);
    } // any associatinve function

    int n;
    vi lo, hi, cons, mult;
    vector<T> seg;

    inline void update(int idx){
        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }

    int calc(int v){
        return (v * (v + 1)) / 2;
    }

    inline void update_lazy(int idx, int val, int mul){
        int len = (hi[idx] - lo[idx] + 1);
        seg[idx].data += mul * (calc(hi[idx] + 1) - calc(lo[idx])) - len * val;
    }

    void propagate(int idx){
        if(lo[idx] != hi[idx]){
            int left = 2 * idx, right = left + 1;
            cons[left] += cons[idx];
            cons[right] += cons[idx];
            mult[left] += mult[idx];
            mult[right] += mult[idx];
            update_lazy(left, cons[idx], mult[idx]);
            update_lazy(right, cons[idx], mult[idx]);
        }
        mult[idx] = 0;
        cons[idx] = 0;
    }
};

void solve(){

    int n, q;
    cin >> n >> q;

    vi arr(n);
    rep(i, n){
        cin >> arr[i];
    }

    SegTree seg(arr);

    rep(i, q){
        int type, a, b;
        cin >> type >> a >> b;
        a--; b--;
        if(type == 1){
            seg.increase(a, b, a);
        }else{
            cout << seg.query(a, b).data << endl;
        }
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
