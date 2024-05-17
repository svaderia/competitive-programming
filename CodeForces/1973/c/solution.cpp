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
// clang-format on

int brute_force(int fact, vi p) {
    int curr = 0;
    vi ans;
    int n = sz(p);

    vi tans(sz(p));

    rep(i, sz(p)) {
        tans[i] = i + 1;
    }

    rep(j, fact) {
        next_permutation(all(tans));

        int tcurr = 0;
        repA(i, 1, n - 2) {
            if (p[i] + tans[i] > p[i - 1] + tans[i - 1] && p[i] + tans[i] > p[i + 1] + tans[i + 1]) {
                tcurr++;
            }
        }
        if (tcurr > curr) {
            curr = tcurr;
            ans = tans;
        }
    }

    cout << curr << endl;

    rep(i, sz(ans)) {
        cout << ans[i] << spc;
    }
    cout << endl;
    return curr;
}

void solve() {

    int n;
    cin >> n;

    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }

    int current = 0;
    repA(i, 1, n - 2) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            current++;
        }
    }

    vi ans = a;
    int mx = (n - 1) / 2;

    for(int mmx = n + 1; mmx < 2 * n; mmx += 2){
        if(current == mx){
            break;
        }

        rep(k, 2) {

            vi tans(n, -1);
            set<int> s;
            repA(i, 1, n) {
                s.insert(i);
            }

            int st = 1;
            if (k == 0) {
                st = 2;
            }

            for (int i = st; i < n; i += 2) {
                int d = mmx - a[i];
                auto it = s.lower_bound(d);
                if(it == s.end()){
                    it--;
                }
                tans[i] = *it;
                s.erase(it);
            }
            rep(i, n) {
                if (tans[i] == -1) {
                    int where  = INF;
                    if(i > 0){
                        where = min(where, a[i - 1] + tans[i - 1]);
                    }
                    if(i < n - 1){
                        where = min(where, a[i + 1] + tans[i + 1]);
                    }

                    int d = where -1 - a[i];
                    auto it = s.upper_bound(d);
                    if (it != s.begin()) {
                        it--;
                        tans[i] = *it;
                        s.erase(it);
                    }
                }
            }
            rep(i, n) {
                if (tans[i] == -1) {
                    auto it = s.end();
                    it--;
                    tans[i] = *it;
                    s.erase(it);
                }
            }

            int tcurrent = 0;
            repA(i, 1, n - 2) {
                if (a[i] + tans[i] > a[i - 1] + tans[i - 1] && a[i] + tans[i] > a[i + 1] + tans[i + 1]) {
                    tcurrent++;
                }
            }

            if (tcurrent > current) {
                current = tcurrent;
                ans = tans;
            }
        }
    }

    /* cout << "my" << endl; */
    /* cout << current << endl; */

    rep(i, n) {
        cout << ans[i] << spc;
    }
    cout << endl;

    /* int fact = 1; */
    /* rep(i, n){ */
    /*     fact *= i + 1; */
    /* } */

    /* int bt = brute_force(fact, a); */
    /* if(bt != current){ */
    /*     cout << "FOUND IT" <<endl; */
    /*     rep(i, n){ */
    /*         cout << a[i] << spc; */
    /*     } */
    /*     cout << endl; */
    /*     cout << "act end" << endl; */
    /* } */

}

signed main() {
    fastio;

    int T;
    cin >> T;

    repA(tc, 1, T) {
        solve();
    }

    return 0;
}
