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

typedef pair<int, pii> tmp;
typedef pair<int, tmp> state;
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
    int h, w, k;
    cin >> h >> w >> k;

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;

    vector<vector<char>> mat(h, vector<char>(w));
    vvi dist(h, vi(w, -1));

    rep(i, h){
        rep(j, w){
            cin >> mat[i][j];
        }
    }

    priority_queue<state, vector<state>, greater<state>> pq;
    dist[sx][sy] = 0;
    pq.push(state(0, tmp(-1, mp(sx, sy))));
    while(!pq.empty()){
        int d = pq.top().f;
        int dir = pq.top().s.f;
        int x = pq.top().s.s.f, y = pq.top().s.s.s;
        pq.pop();
        if(d != dist[x][y]) continue;
        if(x == ex && y == ey) break;
        rep(where, 4){
            if(where == dir || (where + 2) % 4 == dir ) continue;
            repA(kidhar, 1, max(h, w)){
                int nx = x + kidhar * dx[where];
                int ny = y + kidhar * dy[where];
                dbg(x, y, nx, ny, kidhar, where);
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) break;
                if(mat[nx][ny] == '@') break;
                int nd = d + (kidhar - 1) / k + 1;
                if(dist[nx][ny] == -1 || dist[nx][ny] > nd){
                    dist[nx][ny] = nd;
                    pq.push(state(nd, tmp(where, mp(nx, ny))));
                }
            }
        }
    }
    cout << dist[ex][ey] << endl;






}

signed main(){
    fastio;

    solve();

    return 0;
}
