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

long long euclid(long long a, long long b, long long &x, long long &y) {
    if (b) { long long d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}

const long long mod = 998244353;
/* template<long long mod = 1000000007> */
struct modint{
    long long a;
    bool used;

    modint() : a(0), used(false){}
    modint(long long t){
        a = t % mod;
        if(a < 0) a += mod;
    }

    operator long long() const{ return a; }

    bool operator==(const modint &x) const{ return a == x.a; }
    bool operator!=(const modint &x) const{ return a != x.a; }

    modint operator-() const{ return modint(a ? (mod - a) : 0); }
    modint operator~() const{ return invert(*this); }

    modint operator+(const modint &x) const{ return modint(*this) += x; }
    modint operator-(const modint &x) const{ return modint(*this) -= x; }
    modint operator*(const modint &x) const{ return modint(*this) *= x; }
    modint operator/(const modint &x) const{ return modint(*this) /= x; }

    modint &operator+=(const modint &x){
        a += x.a;
        if(a >= mod) a -= mod;
        return *this;
    }
    modint &operator-=(const modint &x){
        a -= x.a;
        if(a < 0) a += mod;
        return *this;
    }
    modint &operator*=(const modint &x){
        a = a * x.a % mod;
        return *this;
    }
    modint &operator/=(const modint &x){
        a = a * (~x).a % mod;
        return *this;
    }

    friend ostream &operator<<(ostream &os,const modint &x){
        return os << x.a;
    }
    friend istream &operator>>(istream &is,modint &x){
        long long t;
        is >> t;
        x = modint(t);
        return is;
    }

    modint pow(long long x) const{
        modint ret = 1,tmp = a;
        for(;x;tmp *= tmp,x >>= 1){
            if(x & 1) ret *= tmp;
        }
        return ret;
    }

    modint invert(modint z) const{
        long long x, y, g = euclid(z.a, mod, x, y);
        assert(g == 1); return modint((x + mod) % mod);
    }
};

// for debug
string to_string(modint z){
    return to_string(z.a);
}

typedef vector<modint> vm;

// clang-format on

struct node{
    modint a, b, ab;
    modint la, lb;
    modint len;

    node(int aa, int bb) : a(aa), b(bb), ab(a * b), la(0), lb(0), len(1) {}
    node() : a(0), b(0), ab(0), la(0), lb(0), len(0){}
}typedef node;

struct seg_tree_lazy{
    typedef node T;

private:
    int n;
    vi lo, hi;
    vector<T> seg;

    T unit = T(0, 0);

    T merge(T x, T y){
        T fin;

        fin.a = x.a + y.a;
        fin.b = x.b + y.b;
        fin.ab = x.ab + y.ab;
        fin.len = x.len + y.len;

        return fin;
    }

    void push(int id){
        if(lo[id] != hi[id]){
            int left = 2 * id, right = left + 1;

            seg[left].la += seg[id].la, seg[left].lb += seg[id].lb;
            seg[left].ab += seg[left].b * seg[id].la + seg[left].a * seg[id].lb + seg[left].len * seg[id].la * seg[id].lb;
            seg[left].a += seg[id].la * seg[left].len, seg[left].b += seg[id].lb * seg[left].len;

            seg[right].la += seg[id].la, seg[right].lb += seg[id].lb;
            seg[right].ab += seg[right].b * seg[id].la + seg[right].a * seg[id].lb + seg[right].len * seg[id].la * seg[id].lb;
            seg[right].a += seg[id].la * seg[right].len, seg[right].b += seg[id].lb * seg[right].len;
        }
        seg[id].la = seg[id].lb = 0;
    }

    void pull(int id){
        seg[id] = merge(seg[2 * id], seg[2 * id + 1]);
    }


public:
    seg_tree_lazy(vector<T> &arr) : n(sz(arr)), lo(4 *n), hi(4 * n), seg(4 * n) {build(0, n - 1, 1, arr);}

    void build(int l, int r, int id, vector<T> &arr){
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
            return unit;
        }


        if(l <= lo[id] && hi[id] <= r){
            return seg[id];
        }
        push(id);

        T lquery = query(l, r, 2 * id);
        T rquery = query(l,r, 2 * id + 1);

        return merge(lquery, rquery);
    }

    void range_increase(int l, int r, modint val, int type, int id = 1){
        if(l > hi[id] || r < lo[id]){
            return;
        }

        if(l <= lo[id] && hi[id] <= r){
            if(type == 1){
                seg[id].la += val;
                seg[id].a += val * seg[id].len;
                seg[id].ab += seg[id].b * val;
            }else{
                seg[id].lb += val;
                seg[id].b += val * seg[id].len;
                seg[id].ab += seg[id].a * val;
            }
            return;
        }

        push(id);
        range_increase(l, r, val, type, 2 * id);
        range_increase(l, r, val, type, 2 * id + 1);

        pull(id);
    }

};


void solve(){
    int n, q;
    cin >> n >> q;

    vi a(n);
    rep(i, n){
        cin >> a[i];
    }

    vi b(n);
    rep(i, n){
        cin >> b[i];
    }

    vector<node> ab(n);
    rep(i, n){
        ab[i] = node(a[i], b[i]);
    }

    seg_tree_lazy s(ab);

    rep(i, q){
        int op;
        cin >> op;

        if(op == 3){
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << s.query(l, r).ab << endl;

        }else{
            int l, r, val;
            cin >> l >> r >> val;
            l--, r--;
            s.range_increase(l, r, val, op);
        }


    }



}

signed main(){
    fastio;

    solve();

    return 0;
}
