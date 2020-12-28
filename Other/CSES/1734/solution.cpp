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

const int block_size = 555;

struct Query{
    int l, r, id;

    Query() {}
    Query(int ll, int rr, int idd) : l(ll), r(rr), id(idd) {}

    pii toPair(){
        return mp(l / block_size, ((l / block_size) & 1) ? -r : r);
    }

    bool operator<(Query &other){
        return this->toPair() < other.toPair();
    }

};

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
gp_hash_table<int, int, chash> m; // Hash table, good alternative of unordered_map

void solve(){

    int n, q;
    cin >> n >> q;
    vi a(n);
    int counter = 0;
    set<int> s;
    rep(i, n){
        cin >> a[i];
        s.insert(a[i]);
    }

    for(auto x : s) m[x] = counter++;
    rep(i, n){
        a[i] = m[a[i]];
    }

    vector<Query> queries(q);
    rep(i, q){
        int l, r;
        cin >> l >> r;
        l--; r--;
        queries[i].l = l;
        queries[i].r = r;
        queries[i].id = i;
    }

    sort(all(queries));

    vi ans(q);

    vi currVal(counter);
    int different = 0;
    int curr_l = 0;
    int curr_r = -1;

    for(auto qr : queries){
        while(curr_l > qr.l){
            curr_l--;
            currVal[a[curr_l]]++;
            if(currVal[a[curr_l]] == 1) different++;
        }
        while(curr_r < qr.r){
            curr_r++;
            currVal[a[curr_r]]++;
            if(currVal[a[curr_r]] == 1) different++;
        }
        while(curr_l < qr.l){
            currVal[a[curr_l]]--;
            if(currVal[a[curr_l]] == 0){
                different--;
            }
            curr_l++;
        }
        while(curr_r > qr.r){
            currVal[a[curr_r]]--;
            if(currVal[a[curr_r]] == 0){
                different--;
            }
            curr_r--;
        }

        ans[qr.id] = different;
    }

    rep(i, q){
        cout << ans[i] << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
