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
// clang-format on

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


int recur(int next_num, int digit_left, vvi &memo){
    if(digit_left == 0){
        return 1;
    }
    if(memo[next_num][digit_left] != -1){
        return memo[next_num][digit_left];
    }

    int ans = 0;
    rep(i, 10){
        if(i != next_num){
            ans += recur(i, digit_left - 1, memo);
        }
    }

    return memo[next_num][digit_left] = ans;
}


void solve(){
    /* const int n = 19; // basically the number can be maximum 19 digit */

    int a, b;
    cin >> a >> b;

    vvi memo(10, vi(21, -1));

    int da = 0;
    int temp = a;
    while(temp > 0){
        da++;
        temp /= 10;
    }

    int db = 0;
    temp = b;
    while(temp > 0){
        db++;
        temp /= 10;
    }

    auto lower = [&] (int x) -> int {
        if(x == 0){
            return 0;
        }

        vi dig;
        temp = x;
        while(temp > 0){
            dig.pb(temp % 10);
            temp = temp/10;
        }
        int dx = sz(dig);
        int ans = 1;

        rep(d, dx - 1){
            repA(num, 1, 9){
                ans += recur(num, d, memo);
            }
        }
        dbg(ans);

        dbg(dig);
        repD(d, sz(dig) - 1, 0){
            rep(num, dig[d]){
                if(d == sz(dig) - 1 && num == 0){
                    continue;
                }
                if(d < sz(dig) - 1 && num == dig[d + 1]){
                    continue;
                }

                dbg(d, num, recur(num, d, memo));
                ans += recur(num, d, memo);
            }
            if(d < sz(dig) - 1 && dig[d] == dig[d + 1]){
                break;
            }
        }
        dbg(ans);
        return ans;

    };

    /* cout << lower(a) << endl; */
    /* cout << lower(b + 1) << endl; */

    cout << lower(b + 1) - lower(a) << endl;
}

signed main(){
    fastio;

    solve();

    return 0;
}
