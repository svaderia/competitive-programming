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
void solve() {
    string s;
    cin >> s;

    s.pb('$');

    int alphabet = 256;

    int n = sz(s);

    vi p(n), c(n);

    // size 1 sort with counting;

    vi cnt(alphabet);

    rep(i, n) {
        cnt[s[i]]++;
    }

    rep(i, alphabet - 1) {
        cnt[i + 1] += cnt[i];
    }

    repD(i, n - 1, 0) {
        p[--cnt[s[i]]] = i;
    }

    int classes = 0;

    c[p[0]] = 0;
    repA(i, 1, n - 1) {
        if (s[p[i]] != s[p[i - 1]])
            classes++;

        c[p[i]] = classes;
    }

    // size 2^(k + 1) sorting with 2^k available

    vi pn(n);
    vi cntn(n);
    vi cn(n);
    for (int z = 1; z < n; z *= 2) {

        // sorted by second element
        rep(i, n) {
            pn[i] = (p[i] - z + n) % n;
        }

        fill(cntn.begin(), cntn.end(), 0);

        rep(i, n) {
            int idx = pn[i];
            cntn[c[idx]]++;
        }

        rep(i, n - 1) {
            cntn[i + 1] += cntn[i];
        }

        repD(i, n - 1, 0) {
            int idx = pn[i];
            p[--cntn[c[idx]]] = idx;
        }

        classes = 0;

        cn[p[0]] = 0;

        repA(i, 1, n - 1) {
            int idx = p[i];
            int pidx = p[i - 1];
            pii curr = mp(c[idx], c[(idx + z) % n]);
            pii prev = mp(c[pidx], c[(pidx + z) % n]);
            if (curr != prev) {
                classes++;
            }

            cn[p[i]] = classes;
        }
        if (classes == n - 1) {
            break;
        }
        c.swap(cn);
    }

    rep(i, n) {
        cout << p[i] << spc;
    }
    cout << endl;
}

signed main() {
    fastio;

    solve();

    return 0;
}
