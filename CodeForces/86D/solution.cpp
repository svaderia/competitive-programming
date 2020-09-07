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

const int MAXN = 2e5 + 5;
const int MAXK = 1e6 + 5;
int arr[MAXN];
int active[MAXK];

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? (
        (y < hpow) ? 0 : 3
    ) : (
        (y < hpow) ? 1 : 2
    );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct Query{
    int l, r, id;
    int64_t ord;

    void calcOrder(){
        ord = gilbertOrder(l, r, 21, 0);
    }

    Query() {}
    Query(int ll, int rr, int idd) : l(ll), r(rr), id(idd) {calcOrder();}

    bool operator<(Query &other){
        return ord < other.ord;
    }

};

void solve(){

    int n, m;
    cin >> n >> m;

    rep(i, n){
        cin >> arr[i];
    }

    vector<Query> qr;
    rep(i, m){
        int l, r;
        cin >> l >> r;
        l--; r--;
        qr.pb(Query(l, r, i));
    }

    sort(all(qr));

    int cl = 0, cr = -1;
    int ans = 0;

    vi fin(m);

    for(auto q : qr){
        while(cl > q.l){
            cl--;
            int ks = active[arr[cl]];
            ans -= ks * ks * arr[cl];
            active[arr[cl]]++;
            ks++;
            ans += ks * ks * arr[cl];
        }
        while(cr < q.r){
            cr++;
            int ks = active[arr[cr]];
            ans -= ks * ks * arr[cr];
            active[arr[cr]]++;
            ks++;
            ans += ks * ks * arr[cr];
        }
        while(cl < q.l){
            int ks = active[arr[cl]];
            ans -= ks * ks * arr[cl];
            ks--;
            ans += ks * ks * arr[cl];
            active[arr[cl]]--;
            cl++;
        }
        while(cr > q.r){
            int ks = active[arr[cr]];
            ans -= ks * ks * arr[cr];
            ks--;
            ans += ks * ks * arr[cr];
            active[arr[cr]]--;
            cr--;
        }

        fin[q.id] = ans;
    }

    rep(i, m){
        cout << fin[i] << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
