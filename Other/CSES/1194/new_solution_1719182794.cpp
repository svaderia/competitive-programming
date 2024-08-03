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

// clang-format on
void solve(){
    int n, m;
    cin >> n >> m;

    map<int, char> mm = {{0, 'D'}, {1, 'R'}, {2, 'U'}, {3, 'L'}};

    vvi a(n, vi(m));

    queue<pair<int, pii>> q;
    vvi dp(n, vi(m, INF));

    pii start;
    rep(i, n){
        rep(j, m){
            char x;
            cin >> x;
            if(x == '#'){
                a[i][j] = 1;
            } else if(x == 'M'){
                q.push(mp(0, mp(i, j)));
                dp[i][j] = 0;
            } else if(x == 'A'){
                start = mp(i, j);
            }
        }
    }

    while(!q.empty()){
        auto val = q.front();
        q.pop();
        int d = val.f, x = val.s.f, y = val.s.s;

        rep(i, 4){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || a[nx][ny] == 1){
                continue;
            }
            if(dp[nx][ny] > d + 1){
                dp[nx][ny] = d + 1;
                q.push(mp(d + 1, mp(nx, ny)));
            }
        }
    }
    rep(i, n){
        dbg(dp[i]);
    }


    q.push(mp(0, start));

    vvi ans(n, vi(m, -1));
    pii end = mp(-1, -1);

    while(!q.empty()){
        auto val = q.front();
        q.pop();
        int d = val.f, x = val.s.f, y = val.s.s;

        if(x == n - 1 || y == m - 1 || x == 0 || y == 0){
            end = mp(x, y);
            break;
        }

        rep(i, 4){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1 || a[nx][ny] == 1){
                continue;
            }
            if(d + 1 < dp[nx][ny] && ans[nx][ny] == -1){
                ans[nx][ny] = i;
                q.push(mp(d + 1, mp(nx, ny)));
            }
        }
    }
    

    if(end.f != -1){
        cout << "YES" << endl;
        vector<char> print;
        while(end != start){
            int dir = ans[end.f][end.s];
            print.pb(mm[dir]);
            end = mp(end.f - dx[dir], end.s - dy[dir]);
        }
        reverse(all(print));
        cout << sz(print) << endl;
        for(auto c : print){
            cout << c;
        }
        cout << endl;
    }else{
        cout << "NO" << endl;
    }
}

signed main(){
    fastio;

    solve();

    return 0;
}
