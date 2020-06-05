#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define endl "\n"
#define error(x) cerr << #x << " = " << (x) << endl
#define errorp(p) cerr << #p << " = " << (p.first) << ", " << (p.second) << endl

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

const int mx = 3005;

const long long mod = 998244353; 
#define ll lli

ll euclid(ll a, ll b, ll &x, ll &y) {
    if (b) { ll d = euclid(b, a % b, y, x);
        return y -= a/b * x, d; }
    return x = 1, y = 0, a;
}

struct modint{
    long long a;
 
    modint() : a(0){}
    modint(long long t){
        a = t % mod;
        if(a < 0) a += mod;
    }
 
    operator long long() const{ return a; }
 
    bool operator==(const modint &x) const{ return a == x.a; }
    bool operator!=(const modint &x) const{ return a != x.a; }
 
    modint operator-() const{ return modint(a ? (mod - a) : 0); }
    modint operator~() const{ return invert(*this); }
 
    modint operator+(const modint &x) const{ return modint(*this) += x; }
    modint operator-(const modint &x) const{ return modint(*this) -= x; }
    modint operator*(const modint &x) const{ return modint(*this) *= x; }
    modint operator/(const modint &x) const{ return modint(*this) /= x; }
 
    modint &operator+=(const modint &x){
        a += x.a;
        if(a >= mod) a -= mod;
        return *this;
    }
    modint &operator-=(const modint &x){
        a -= x.a;
        if(a < 0) a += mod;
        return *this;
    }
    modint &operator*=(const modint &x){
        a = a * x.a % mod;
        return *this;
    }
    modint &operator/=(const modint &x){
        a = a * (~x).a % mod; 
        return *this;
    }
 
    friend ostream &operator<<(ostream &os,const modint &x){
        return os << x.a;
    }
    friend istream &operator>>(istream &is,modint &x){
        long long t;
        is >> t;
        x = modint(t);
        return is;
    }
 
    modint pow(long long x) const{
        modint ret = 1,tmp = a;
        for(;x;tmp *= tmp,x >>= 1){
            if(x & 1) ret *= tmp;
        }
        return ret;
    }

    modint invert(modint z) const{
        ll x, y, g = euclid(z.a, mod, x, y);
        assert(g == 1); return modint((x + mod) % mod);
    }
};

void solve(){
    int n, s;
    cin >> n >> s;
    vi arr(n);
    rep(i, n){
        cin >> arr[i];
    }

    vector<modint> pow2(n+1);
    repA(i, 1, n){
        pow2[i] = modint(2).pow(i);
    }
    sort(all(arr));
    vector<modint> dp(s+1, modint(0));
    vector<bool> exist(s+1, false);
    dp[0] = pow2[n];
    exist[0] = true;
    rep(i, n){
        if(arr[i] > s){
            break;
        }
        vector<modint> sdp(s + 1, modint(0));
        rep(j, s + 1){
            if(exist[j] && j + arr[i] <= s){               
                sdp[arr[i] + j] += dp[j] / modint(2);
                exist[j + arr[i]] = true;
            }
        }

        rep(j, s + 1){
            if(exist[j]){
                dp[j] += sdp[j];
            }
        }
    }

    cout << dp[s] << endl;

}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    solve();

    return 0;
}
