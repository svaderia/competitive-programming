#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

struct chash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x)^RANDOM; }
};

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

    T unit = T(0);

    T merge(T a, T b) {
        return T((a.data + b.data));
    } // any associatinve function

    vector<T> s; int n;
    SegTree(int nn, T def) : s(2 * nn, def), n(nn) {}
    SegTree(int nn) : s(2 * nn, unit), n(nn) {}
    SegTree(vi &arr) : s(2 * sz(arr)), n(sz(arr)) { rep(i, n) s[i + n] = T(arr[i]); build(); }

    void build(){
        repD(pos, n - 1, 1)
            s[pos] = merge(s[2 * pos], s[2 * pos + 1]);
    }

    void set(int pos, int val){
        pos += n;
        s[pos].data += val;
        for(; pos /= 2;)
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

    set<int> s;
    vi p(n);
    rep(i, n){
        cin >> p[i];
        s.insert(p[i]);
    }

    vector<pair<int, pii> > query;
    rep(i, q){

        char type;
        int a, b;
        cin >> type >> a >> b;

        if(type == '!'){
            s.insert(b);
            query.pb(mp(0ll, mp(a - 1, b)));
        }else{
            s.insert(a); s.insert(b);
            query.pb(mp(1ll, mp(a, b)));
        }
    }

    gp_hash_table<int, int, chash> m; // Hash table, good alternative of unordered_map
    int counter = 0;
    for(auto x : s){
        m[x] = counter++;
    }

    vi arr(counter);

    rep(i, n){
        arr[m[p[i]]]++;
    }

    SegTree seg(arr);

    for(auto qs : query){
        if(qs.f == 0){
            seg.set(m[p[qs.s.f]], -1);
            seg.set(m[qs.s.s], 1);
            p[qs.s.f] = qs.s.s;
        } else{
            int a = m[qs.s.f], b = m[qs.s.s];
            if(a > b) swap(a, b);
            cout << seg.query(a, b + 1).data << endl;
        }
    }
}

signed main(){
    fastio;

    solve();

    return 0;
}
