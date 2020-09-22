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

int k;
int n;

void solve1(){

    cin >> n;

    vi which(n);

    int x = 0;
    int l = n / 4;
    rep(i, 2 * l){
        which[i] = x;
        which[n - 1 - i] = x;
        x = 1 - x;
    }

    if(l > 0){
        int mid = 2 * l;
        if(n % 4 == 1){
            which[mid] = which[l];
            which[l] = 1 - which[mid];
        }else if(n % 4 == 2){
            which[mid] = 0;
            which[mid + 1] = 1;
        }else if(n % 4 == 3){
            which[mid + 1] = 1 - which[l];
            which[mid] = which[l];
            which[mid + 2] = which[l];
            which[l] = 1 - which[l];
        }
    }else{
        if(n == 2){
            which[0] = 0;
            which[1] = 1;
        }else if(n == 3){
            which[0] = which[1] = 0;
            which[2] = 1;
        }
    }

    int a = 0, b = 0;

    rep(i, n){
        if(which[i])
            a += i + 1;
        else
            b += i + 1;
    }

    cout << abs(a - b) << endl;
    rep(i, n){
        cout << which[i];
    }
    cout << endl;
    /* dbg(abs(a - b)); */

}

vi ans;
int absmin;

void recur(int id, vi &which){
    if(id == n){
        int a = 0, b = 0;

        rep(i, n){
            if(which[i])
                a += (i + 1) * (i + 1);
            else
                b += (i + 1) * (i + 1);
        }

        if(abs(a - b) < absmin){
            absmin = abs(a - b);
            rep(i, n) ans[i] = which[i];
        }
        return;
    }

    which[id] = 0;
    recur(id + 1, which);
    which[id] = 1;
    recur(id + 1, which);
    which[id] = 0;
}

void solve2(){

    cin >> n;

    vi which(n);
    ans.clear();
    ans.rsz(n);

    absmin = INF;

    recur(0, which);

    cout << absmin << endl;
    rep(i, n){
        cout << ans[i];
    }
    cout << endl;


}



signed main(){
    fastio;

    cin >> k;

    int T;
    cin >> T;

    repA(tc, 1, T){
        if(k == 1)
            solve1();
        else if(k == 2)
            solve2();
    }

    return 0;
}
