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


// TO_STRING
string to_string(char c) { return string(1,c); }
string to_string(const char* s) { return (string)s; }
string to_string(string s) { return s; }
string to_string(bool b) {
    #ifdef DEBUG
        return b ? "true" : "false";
    #else
        return to_string((int)b);
    #endif
}
template<class A> string to_string(complex<A> c) {
    stringstream ss; ss << c; return ss.str(); }
string to_string(vector<bool> v) {
    string res = "{"; rep(i,sz(v)) res += char('0'+v[i]);
    res += "}"; return res; }
template<size_t SZ> string to_string(bitset<SZ> b) {
    string res = ""; rep(i,SZ) res += char('0'+b[i]);
    return res; }
template<class A, class B> string to_string(pair<A,B> p);
template<class T> string to_string(T v) { // containers with begin(), end()
    #ifdef DEBUG
        bool fst = 1; string res = "{";
        for (const auto& x: v) {
            if (!fst) res += ", ";
            fst = 0; res += to_string(x);
        }
        res += "}"; return res;
    #else
        bool fst = 1; string res = "";
        for (const auto& x: v) {
            if (!fst) res += " ";
            fst = 0; res += to_string(x);
        }
        return res;

    #endif
}
template<class A, class B> string to_string(pair<A,B> p) {
    #ifdef DEBUG
        return "("+to_string(p.f)+", "+to_string(p.s)+")";
    #else
        return to_string(p.f)+" "+to_string(p.s);
    #endif
}

// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
    DBG(t...); }
#ifdef DEBUG // compile with -DDEBUG
    #define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif


typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet; // order_of_key find_by_order

int block_size;

void solve(){

    int n;
    cin >> n;

    block_size = (int) sqrt(n);

    int nblocks = (int)ceil((double) n / (double) block_size);

    vi blocks[nblocks + 1];
    dbg(block_size, nblocks);

    vi arr(n);
    rep(i, n){
        cin >> arr[i];
        int cb = i / block_size;
        blocks[cb].pb(arr[i]);
    }

    rep(i, nblocks + 1){
        sort(all(blocks[i]));
    }

    int q;
    cin >> q;

    rep(_, q){
        int type;
        cin >> type;
        if(type == 0){
            int a, b, c;
            cin >> a >> b >> c;
            a--; b--;

            int cl = a / block_size, cr = b / block_size;

            dbg(a, b, cl, cr);
            int ans = 0;

            if(cl == cr){
                repA(i, a, b){
                    if(arr[i] >= c) ans++;
                }
            }else {
                repA(i, a, (cl + 1) * block_size - 1){
                    dbg(i);
                    if(arr[i] >= c) ans++;
                }

                repA(i, cr * block_size, b){
                    dbg(i);
                    if(arr[i] >= c) ans++;
                }

                repA(i, cl + 1, cr - 1){
                    ans += blocks[i].end() - lower_bound(all(blocks[i]), c);
                }
            }

            cout << ans << endl;
        }else {
            int a, b;
            cin >> a >> b;
            a--;
            int cb = a / block_size;

            int v = lower_bound(all(blocks[cb]), arr[a]) - blocks[cb].begin();
            blocks[cb][v] = b;
            sort(all(blocks[cb]));

            arr[a] = b;
        }
    }



}

signed main(){
    fastio;

    solve();

    return 0;
}
