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

int recur(int c, int k, vvi &dp, vvi &cost, vi &vol, vi &count){

    if(c == sz(dp)) return 0;
    dbg(c, k);
    if(dp[c][k] != -1) return dp[c][k];

    dp[c][k] = cost[c][0] + recur(c + 1, k, dp, cost, vol, count);
    repA(l, 1, count[c]){
        if(k < l * vol[c]) break;
        dp[c][k] = min(dp[c][k], cost[c][l] + recur(c + 1, k - l * vol[c], dp, cost, vol, count));
    }
    dbg(c, k, dp[c][k]);
    return dp[c][k];

}

int cal(vi &v){
    dbg(v);
    int s1 = 0;
    int n = sz(v);
    rep(i, n){
        s1 += v[i];
    }
    dbg(s1, n);

    int s2 = 0;
    vi temp(n);
    rep(i, n){
        temp[i] = v[i] * (s1 - v[i]);
        s2 += temp[i];
    }
    s2 /= 2;
    dbg(s2);

    int s3 = 0;
    rep(i, n){
        s3 += v[i] * (s2 - temp[i]);
    }
    s3 /= 3;
    return s3;
}


void solve(){

    int n, C, k;
    cin >> n >> C >> k;

    vector<map<int, int> > lines(C);
    vvi fin(C);
    vi counter(C, 0);
    rep(i, n){
        int a, b, c;
        cin >> a >> b >> c;
        c--;
        if(!present(lines[c], a)) lines[c][a] = 0;
        lines[c][a]++;
        counter[c]++;
    }
    rep(i, C){
        for(auto p : lines[i]){
            fin[i].pb(p.s);
        }
        sort(all(fin[i]));
    }


    vi v(C);
    rep(i, C){
        cin >> v[i];
    }
    
    vvi cost(C, vi(n + 1, 0));

    rep(i, C){
        vi temp(all(fin[i]));
        int tc = 0;
        cost[i][0] = cal(temp);
        dbg(cost[i][0]);
        repA(l, 1, counter[i]){
            temp[tc]--;
            if(temp[tc] == 0) tc++;
            cost[i][l] = cal(temp);
            dbg(cost[i][l] );
            if(cost[i][l] == 0) break;
        }
    }
    
    vvi dp(C, vi(k + 1, -1));

    cout << recur(0, k, dp, cost, v, counter) << endl;

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
