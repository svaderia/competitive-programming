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
    lli data;
    node(lli val) : data(val) {}
}typedef node;

struct SegTree{
    typedef node T;

    T unit = T(INF);

    T merge(T a, T b) {
        return T(min(a.data, b.data));
    } // any associatinve function

    vector<T> s; int n;
    SegTree(int nn, T def) : s(2 * nn, def), n(nn) {}
    SegTree(int nn) : s(2 * nn, unit), n(nn) {}

    void build(){
        repD(pos, n - 1, 1)
            s[pos] = merge(s[2 * pos], s[2 * pos + 1]);
    }

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

    vi arr(n);
    rep(i, n){
        cin >> arr[i];
    }

    SegTree seg(n);
    rep(i, n){
        seg.s[i + n] = arr[i];
    }
    seg.build();

    rep(i, q){
        int x, y;
        cin >> x >> y;
        x--;
        cout << seg.query(x, y).data << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
