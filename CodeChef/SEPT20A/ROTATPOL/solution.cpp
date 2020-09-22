
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef long double ld;
#define double ld
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD   = 1e9 + 7;
const double PI = acos(-1.0);
const int dx[7] = {1, 0, -1, 0, 0, 1, -1}, dy[7] = {0, 1, 0, -1, 0, 1, -1};
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

struct Point{
    int x, y;
    int id;
    double theta;

    void calTheta(){
        double costheta = (double) x / sqrt( (double)(x * x + y * y));
        theta = acos(costheta);
        if(y < 0) theta = 2 * PI - theta;
    }

    Point() : x(0), y(0), id(0), theta(0.0) {}
    Point(int x_, int y_) : x(x_), y(y_) {calTheta();}

    bool operator<(Point &b){
        return this->theta < b.theta;
    }

    Point& operator += (const Point& p) { x += p.x, y += p.y; return *this;}
    Point& operator -= (const Point& p) { x -= p.x, y -= p.y; return *this;}
    Point& operator *= (const int& t) { x *= t, y *= t; return *this;}
    Point& operator /= (const int& t) { x /= t, y /= t; return *this;}

    friend Point operator + (const Point& a, const Point& b) { return Point(a.x+b.x, a.y+b.y); }
    friend Point operator - (const Point& a, const Point& b) { return Point(a.x-b.x, a.y-b.y); }
    friend Point operator * (const Point& a, const int& t) { return Point(a.x*t, a.y*t); }
    friend Point operator * (const int& t ,const Point& a) { return Point(t*a.x, t*a.y); }
    friend Point operator / (const Point& a, const int& t) { return Point(a.x/t, a.y/t); }

    friend int dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
};

string ts(vector<Point> ps){
    string result = "{ ";
    for(auto p : ps){
        result +=  "x: " + to_string(p.x);
        result +=  " y: " + to_string(p.y);
        result +=  " theta: " + to_string(p.theta);
        result +=  " id: " + to_string(p.id);
        result += ", \n";
    }
    result += "}";

    return result;
}

void solve(){
    int n;
    cin >> n;

    vector<Point> points;

    rep(i, n){
        int x, y;
        cin >> x >> y;
        points.pb(Point(x, y));
        points[i].id = i;
    }

    vector<Point> diff;
    rep(i, n - 1){
        diff.pb(points[i + 1] - points[i]);
        diff[i].id = i;
    }
    diff.pb(points[0] - points[n - 1]);
    diff[n - 1].id = n - 1;

    sort(all(diff));

    /* cout << ts(diff) << endl; */

    int p = n - 1;
    vector<double> candidate;
    const double eps = 0.0001;

    rep(i, n){
        double x1 = diff[p].theta, x2 = diff[i].theta;
        candidate.pb((x1 + x2) / 2.0);
        candidate.pb(x1);
        candidate.pb(x2);
        x1 += PI; x2 += PI;
        candidate.pb(x1);
        candidate.pb(x2);
        candidate.pb((x1 + x2) / 2.0);
        candidate.pb(x2 + PI / 2);
        candidate.pb(x1 + PI / 2);
        if(x1 > 2 * PI) x1 -= 2 * PI;
        if(x2 > 2 * PI) x2 -= 2 * PI;
        rep(k, n){
            double th = diff[k].theta;
            if(abs(x1 - th) + abs(x2 - th) <= abs(x1 - x2)){
                double p1 = th + PI / 2 + eps;
                double p2 = th + PI / 2 - eps;
                double p3 = th - PI / 2 + eps;
                double p4 = th - PI / 2 - eps;
                for(auto yy : {p1, p2, p3, p4})
                    candidate.pb(yy);
            }
        }
        p = i;
    }

    candidate.pb(0);
    candidate.pb(PI / 2);
    candidate.pb(PI);
    candidate.pb(3*PI / 2);

    const double mx = 2000000000.0;
    Point ans(0, 0);
    for(auto th : candidate){
        vb inside(n);
        vb outside(n, true);

        double tx = mx * cos(th);
        double ty = mx * sin(th);
        rep(_, 7){
            Point temp((int)(tx) + dx[_], (int)(ty) + dy[_]);;

            bool is_zero = false;

            rep(i, n){
                int val = dot(temp, diff[i]);
                if(val > 0){
                    inside[diff[i].id] = true;
                    outside[diff[i].id] = false;
                }
                if(val == 0) is_zero = true;
            }
            bool first = false;
            int exist = true;
            rep(i, n){
                if(inside[i]){
                    if(first && inside[i - 1] != inside[i]){
                        exist = false;
                        break;
                    }
                    if(!first){
                        first = true;
                    }
                }
            }
            if(first && exist && !is_zero){
                dbg(inside);
                ans = temp;
                break;

            }
            first = false;
            exist = true;
            rep(i, n){
                if(outside[i]){
                    if(first && outside[i - 1] != outside[i]){
                        exist = false;
                        break;
                    }
                    if(!first){
                        first = true;
                    }
                }
            }
            if(first && exist && !is_zero){
                dbg(outside);
                ans = temp;
                break;

            }
        }
        if(ans.x != 0 && ans.y != 0) break;

    }

    int xv = ans.x, yv = ans.y;
    cout << xv << spc << yv << endl;

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
