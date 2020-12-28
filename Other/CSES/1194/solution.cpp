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

int n, m;
vector<string> s;
vvi arr;

void bfs(queue<pair<pii, int> > &q){

    auto inside = [&] (int x, int y, int d){
        return (x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '#' && arr[x][y] > d);
    };

    while(!q.empty()){
        int x = q.front().f.f, y = q.front().f.s, d = q.front().s;
        q.pop();

        rep(i, 4){
            int nx = x + dx[i], ny = y + dy[i];
            if(inside(nx, ny, d + 1)){
                arr[nx][ny] = d + 1;
                q.push(mp(mp(nx, ny), d + 1));
            }
        }
    }
}

void solve(){

    cin >> n >> m;

    s.rsz(n);
    rep(i, n){
        cin >> s[i];
    }

    pii st, end;

    arr.rsz(n, vi(m, m * n + 1));
    queue<pair<pii, int> > monster_q;
    rep(i, n){
        rep(j, m){
            if(s[i][j] == 'A') st = mp(i, j);
            if(s[i][j] == 'M') {
                arr[i][j] = 0;
                monster_q.push(mp(mp(i, j), 0ll));
            }
        }
    }

    bfs(monster_q);

    queue<pair<pii, int> > q;
    q.push(mp(st, 0ll));

    auto inside = [&] (int x, int y, int d){
        return (x >= 0 && x < n && y >= 0 && y < m && (s[x][y] != '#') && (arr[x][y] > d));
    };

    vvi visited(n, vi(m, -1));
    visited[st.f][st.s] = 1;

    int ans = -1;
    while(!q.empty()){
        int x = q.front().f.f, y = q.front().f.s, d = q.front().s;
        q.pop();
        if(x == n - 1 || x == 0 || y == 0 || y == m - 1){
            end = mp(x, y);
            ans = d; break;
        }
        rep(i, 4){
            int nx = x + dx[i], ny = y + dy[i];
            if(inside(nx, ny, d + 1) && (visited[nx][ny] == -1)){
                visited[nx][ny] = i;
                q.push(mp(mp(nx, ny), d + 1));
            }
        }
    }

    map<int, char> mymap = {{0, 'D'}, {1, 'R'}, {2, 'U'}, {3, 'L'}};
    if(ans != -1){
        string steps;
        pii temp = end;
        while(temp != st){
            int dir = visited[temp.f][temp.s];
            steps.pb(mymap[dir]);
            int nx = temp.f - dx[dir], ny = temp.s - dy[dir];
            temp = mp(nx, ny);
        }
        reverse(all(steps));
        cout << "YES" << endl << ans << endl << steps << endl;

    }else{
        cout << "NO" << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
