// clang-format off
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #include "debug.h"
#else
    #define dbg(...) 0
#endif

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
void solve() {
    string s;
    cin >> s;

    s.pb('$');

    int n = sz(s);

    int alphabet = 256;

    vi p(n), c(n);
    vi cnt(max(alphabet, n));

    rep(i, n) {
        cnt[s[i]]++;
    }
    rep(i, alphabet - 1) {
        cnt[i + 1] += cnt[i];
    }
    repD(i, n - 1, 0) {
        p[--cnt[s[i]]] = i;
    }

    c[p[0]] = 0;
    repA(i, 1, n - 1) {
        if (s[p[i - 1]] == s[p[i]]) {
            c[p[i]] = c[p[i - 1]];
        } else {
            c[p[i]] = i;
        }
    }

    dbg(s);

    dbg(p, c);

    bool done = false;

    vi pn(n), cn(n);

    for (int z = 1; z < n && !done; z *= 2) {
        rep(i, n) {
            pn[i] = (p[i] - z + n) % n;
        }
        dbg(pn);

        fill(all(cnt), 0);

        rep(i, n) {
            cnt[c[pn[i]]]++;
        }
        rep(i, n - 1) {
            cnt[i + 1] += cnt[i];
        }

        // why only go till 1 ? go all the way down :)
        repD(i, n - 1, 0) {
            dbg(i, pn[i], c[pn[i]], cnt[c[pn[i]]]);
            p[--cnt[c[pn[i]]]] = pn[i];
        }

        done = true;
        cn[p[0]] = 0;
        repA(i, 1, n - 1) {
            pii curr = mp(c[p[i]], c[(p[i] + z) % n]);
            pii prev = mp(c[p[i - 1]], c[(p[i - 1] + z) % n]);

            if (prev == curr) {
                cn[p[i]] = cn[p[i - 1]];
                done = false;
            } else {
                cn[p[i]] = i;
            }
        }
        c.swap(cn);

        dbg(p, c);
    }

    rep(i, n) {
        cout << p[i] << " \n"[i == n - 1];
    }

    vi lcp(n);

    int k = 0;
    rep(i, n) {
        int pos = c[i];
        k = k < 0 ? 0 : k;
        if (pos > n - 2) {
            continue;
        }

        while (s[p[pos] + k] == s[p[pos + 1] + k] && k < n) {
            k++;
        }
        lcp[pos] = k;
        k--;
    }

    rep(i, n - 1) {
        cout << lcp[i] << " \n"[i == n - 2];
    }
}

signed main() {
    fastio;

    solve();

    return 0;
}
