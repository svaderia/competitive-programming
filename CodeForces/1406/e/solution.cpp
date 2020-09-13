
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

vi SieveOfEratosthenes(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

    vi all_primes;
    for (int p=2; p<=n; p++)
       if (prime[p])
            all_primes.pb(p);
    return all_primes;
}

vi arr;
int xx;
int psuedo_quer(int type, int which){
    int count = 0;
    vi temp;
    for(auto yy : arr){
        if(yy % which == 0){
            count++;
            if(type == 2){
                if(yy == xx) temp.pb(yy);
                continue;
            }

        }
        temp.pb(yy);
    }
    /* dbg(type, arr, temp); */
    arr = temp;
    if(type == 3){
        cout << which << endl;
        assert(xx == which);
    }

    return count;
}

int query(int type, int x){
#ifdef DEBUG
    int val = psuedo_quer(type, x);
    dbg(type, x, val);
    return val;
#else
    int rep = 0;
    if(type == 1){
        cout << "A " << x << endl;
        cin >> rep;
    }else if(type == 2){
        cout << "B " << x << endl;
        cin >> rep;
    }else{
        cout << "C " << x << endl;
    }
    return rep;
#endif
}

void solve(){

    int n;
    cin >> n;
#ifdef DEBUG
    rep(i, n) arr.pb(i + 1);
    cin >> xx;
#endif

    vi primes = SieveOfEratosthenes(n);

    int bigp = 0;
    for(auto x : primes){
        if(x * x > n) bigp++;
    }

    int ans = 1;

    for(auto x : primes){
        if(x * x > n) break;
        int temp = query(2LL, x);
        if(x * ans > n) continue;
        int rep = query(1LL, x);
        if(rep > 0){
            temp = x * x;
            while(true){
                if(temp * ans > n) break;
                rep = query(1LL, temp);
                if(rep == 0) break;
                temp *= x;
            }
            temp /= x;
            ans *= temp;
        }

    }

    int rep = query(1LL, 1LL);
    dbg(rep, bigp);
    const int block_size = 100;
    int idx = 0;
    if(rep == 1 + bigp){
        rep(i, sz(primes)){
            int x = primes[i];
            if(ans * x  > n) break;
            if(x * x > n){
                rep = query(2LL, x);
                idx++;
                bigp--;
            }
            if(idx == block_size){
                rep = query(1LL, 1LL);
                if(rep != 1 + bigp){
                    repA(j, i - idx - 1, i){
                        rep = query(1LL, primes[j]);
                        if(rep == 1){
                            ans = primes[j];
                            break;
                        }
                    }
                }
                idx = 0;
            }
        }
        int i = sz(primes) - 1;
        if(idx != 0){
            rep = query(1LL, 1LL);
            if(rep != 1 + bigp){
                repA(j, max(0LL, i - idx - 1), i){
                    rep = query(1LL, primes[j]);
                    if(rep == 1){
                        ans = primes[j];
                        break;
                    }
                }
            }
            idx = 0;
        }
    }else{
        for(auto x : primes){
            if(x * x > n){
                if(ans * x > n) break;
                rep = query(1LL, x);
                if(rep > 1){
                    ans *= x;
                    break;
                }
            }
        }

    }

    rep = query(3LL, ans);

}

signed main(){
    fastio;

    solve();

    return 0;
}
