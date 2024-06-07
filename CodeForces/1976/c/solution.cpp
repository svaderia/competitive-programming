// clang-format off
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vi;
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
// clang-format on

#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;

struct chash {
    const long long RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    unsigned long long operator()(pair<lli, pii> x) const {
        unsigned long long h1 = hash_f(x.f);
        unsigned long long h2 = hash_f(x.s.f);
        unsigned long long h3 = hash_f(x.s.s);
        return (((h1 * 31ULL + h2) * 31ULL) + h3)^RANDOM; 
    }
};

void solve(){

    lli n, m;
    cin >> n >> m;

    vvi a(n + m + 1, vi(2));
    rep(i, n + m + 1){
        cin >> a[i][0];
    }

    rep(i, n + m + 1){
        cin >> a[i][1];
    }

    

    // pair<index, <left_over_programmer, left_over_tester>>
    gp_hash_table<pair<lli, pair<lli, lli>>, lli, chash> mm; // Hash table, good alternative of unordered_map
    rep(i, n + m + 2){
        mm[mp(i, mp(0, 0))] = 0;
    }

    // start index, left_over_p, left_over_t
    auto dp = [&] (lli start_index, lli p, lli t, auto self) -> lli{
        auto pp = mp(start_index, mp(p, t));
        if(present(mm, pp)){
            return mm[pp];
        }

        lli ans = 0;
        if(p == 0){
            ans = a[start_index][1] + self(start_index + 1, p, t - 1, self);
        }else if(t == 0){
            ans = a[start_index][0] + self(start_index + 1, p - 1, t, self);
        }else{
            if(a[start_index][0] > a[start_index][1]){
                ans = a[start_index][0] + self(start_index + 1, p - 1, t, self);
            }else{
                ans = a[start_index][1] + self(start_index + 1, p, t - 1, self);
            }
        }
        mm[pp] = ans;
        return ans;
    };


    vi ans(n + m + 1);

    ans[0] = dp(1, n, m, dp);
    ans[n + m] = dp(0, n, m, dp);

    lli p = n, t = m;
    lli tans = 0;


    rep(i, n + m){
        ans[i] = tans + dp(i + 1, p, t, dp);

        if(p == 0){
            tans += a[i][1];
            t--;
        }else if(t == 0){
            tans += a[i][0];
            p--;
        }else{
            if(a[i][0] > a[i][1]){
                p--;
                tans += a[i][0];
            }else{
                t--;
                tans += a[i][1];
            }
        }

    }

    rep(i, n + m + 1){
        cout << ans[i] << spc;
    }
    cout << endl;

    if(sz(mm) > 4 * (m + n + 10) + 10){
        cout << sz(mm) << endl;
    }

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
