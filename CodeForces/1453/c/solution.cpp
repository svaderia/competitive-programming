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

void solve(){
    int n;
    cin >> n;

    vector<string> s(n);
    rep(i, n){
        cin >> s[i];
    }

    vector<vii> x(10);
    vector<vii> y(10);
    rep(i, n){
        rep(j, n){
            int a = s[i][j] - '0';
            x[a].eb(mp(i, j));
            y[a].eb(mp(j, i));
        }
    }

    rep(i, 10){
        sort(all(x[i]));
        sort(all(y[i]));
    }


    rep(i, 10){
        int ans = 0;
        for(auto p : x[i]){
            int tans = max(p.s, n - 1 - p.s) * max(p.f - (*x[i].begin()).f, (*x[i].rbegin()).f - p.f);
            ans = max(ans, tans);
        }
        for(auto p : y[i]){
            int tans = max(p.s, n - 1 - p.s) * max(p.f - (*y[i].begin()).f, (*y[i].rbegin()).f - p.f);
            ans = max(ans, tans);
        }
        cout << ans << spc;
    }
    cout << endl;





}

signed main(){
    fastio;

    int T;
    cin >> T;

    repA(tc, 1, T){
        solve();
    }

    return 0;
}
