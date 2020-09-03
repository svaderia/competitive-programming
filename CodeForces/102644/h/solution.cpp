#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD   = 1e9 + 7;
const double PI = acos(-1.0);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};

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

#define ll lli

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (b) { ll d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}

const ll mod = 1000000007;
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
        ll x, y, g = euclid(z.a, mod, x, y);
        assert(g == 1); return modint((x + mod) % mod);
    }
};

typedef vector<modint> vm;

struct Matrix {
    modint a[2][2] = {{modint(0), modint(0)}, {modint(0), modint(0)}};
    Matrix operator *(const Matrix& other) {
        Matrix product;
        rep(i,N)rep(j,N)rep(k,N) {
            product.a[i][k] += a[i][j] * other.a[j][k];
        }
        return product;
    }
};

/* Matrix expo_power(Matrix a, long long k) { */
/*     Matrix product; */
/*     REP(i,N) product.a[i][i] = 1; */
/*     while(k > 0) { */
/*         if(k % 2) { */
/*             product = product * a; */
/*         } */
/*         a = a * a; */
/*         k /= 2; */
/*     } */
/*     return product; */
/* } */

struct node{
    Matrix data;
    node(Matrix val) : data(val) {}
    node(int x){
        rep(i, N) data.a[i][i] = modint(x);
    }
}typedef node;

struct SegTree{
    typedef node T;

    T unit = T(1L);

    T merge(T a, T b) {
        return T(a.data * b.data);
    } // any associatinve function

    vector<T> s; int n;
    SegTree(int nn, T def) : s(2 * nn, def), n(nn) {}
    SegTree(int nn) : s(2 * nn, unit), n(nn) {}

    void update(int pos, T val){
        for(s[pos += n] = val; pos /= 2;)
            s[pos] = merge(s[2 * pos], s[2 * pos + 1]);
    }

    T query(int l, int r){ // [l, r)
        T vl = unit, vr = unit;
        for(l += n, r += n; l < r; l /= 2, r /= 2){
            if(l % 2) vl = merge(vl, s[l++]);
            if(r % 2) vr = merge(s[--r], vr);
        }
        return merge(vl, vr);
    }
};

void solve(){

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    Matrix happy;
    Matrix sad;
    Matrix flip;
    Matrix anything;
    Matrix unit;

    unit.a[0][0] = 1;
    unit.a[1][1] = 1;

    happy.a[0][0] = modint(1);
    happy.a[1][0] = modint(1);

    sad.a[0][1] = modint(1);
    sad.a[1][1] = modint(1);

    flip.a[0][1] = modint(1);
    flip.a[1][0] = modint(1);

    anything.a[0][0] = modint(19);
    anything.a[0][1] = modint(7);
    anything.a[1][1] = modint(20);
    anything.a[1][0] = modint(6);

    SegTree seg(n);

    rep(i, sz(s)){
        if(s[i] == 'S' || s[i] == 'D'){
            seg.update(i, sad);
        } else if(s[i] == 'H'){
            seg.update(i, happy);
        } else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
            seg.update(i, flip);
        } else if(s[i] == '?'){
            seg.update(i, anything);
        }
    }

    cout << seg.query(0, n).data.a[0][0] << endl;

    rep(i, q){
        int id;
        cin >> id;
        char c;
        cin >> c;

        id--;
        s[id] = c;

        if(s[id] == 'S' || s[id] == 'D'){
            seg.update(id, sad);
        } else if(s[id] == 'H'){
            seg.update(id, happy);
        } else if(s[id] == 'A' || s[id] == 'E' || s[id] == 'I' || s[id] == 'O' || s[id] == 'U'){
            seg.update(id, flip);
        } else if(s[id] == '?'){
            seg.update(id, anything);
        } else{
            seg.update(id, unit);
        }

        cout << seg.query(0, n).data.a[0][0] << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
