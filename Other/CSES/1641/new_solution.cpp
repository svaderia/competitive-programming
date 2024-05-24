// clang-format off
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;

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
// clang-format on

struct chash {
    const int RANDOM =
        (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) {
        return a * 31 + b;
    }
    int operator()(int x) const {
        return hash_f(x) ^ RANDOM;
    }
};

void solve() {
    int n, x;
    cin >> n >> x;

    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    bool found = false;
    // this is not required for this problem at least
    /* gp_hash_table<int, vi, chash> mm; // Hash table, good alternative of unordered_map */

    map<int, vi> mm;
    rep(i, n) {
        rep(j, i) {
            int sum = a[i] + a[j];
            int fd = x - sum;
            if (present(mm, fd)) {
                for (auto y : mm[fd]) {
                    if (y != j) {
                        cout << y + 1 << spc << i + 1 << spc << j + 1 << endl;
                        found = true;
                        break;
                    }
                }
            }
            if (found) {
                break;
            }
        }
        mm[a[i]].pb(i);
        if (found) {
            break;
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }
}

signed main() {
    fastio;

    solve();

    return 0;
}
