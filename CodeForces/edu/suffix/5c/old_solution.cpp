// clang-format off
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
    #define dbg(...) 0
    // #include "debug.h"
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
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

template <typename T> struct sparse_table {
    const int LOG = 20; // should be okay until 10^6 arrays

    T n;
    vector<vector<T>> dp;

    // this is the merge function
    // TODO: Something you might need to change
    T merge(T a, T b) {
        return min(a, b);
    }

    sparse_table(const vector<T> &a = {}) {
        if (!a.empty())
            build(a);
    }

    void build(const vector<T> &a = {}) {
        n = sz(a);
        dp.resize(LOG);
        dp[0].rsz(n);
        rep(i, n){
            dp[0][i] = a[i];
        }

        repA(id, 1, LOG - 1) {
            dp[id].resize(n);
            rep(j, n) {
                dp[id][j] = dp[id - 1][j];
                int next_id = j + (1L << (id - 1));
                if (next_id < n) {
                    dp[id][j] = merge(dp[id][j], dp[id - 1][next_id]);
                }
            }
        }
        dbg(dp);
    }

    // query of the form [l, r]
    T query(int l, int r) {
        int d = r - l + 1;
        int id = __builtin_clzll(1) - __builtin_clzll(d);
        int shift = (1LL << id);
        return merge(dp[id][l], dp[id][r - shift + 1]);
    }
};

struct suffix_array {
    int n = 0;
    string str;
    vector<int> suffix; // p from the algorithm you remember
    vector<int> rank;   // c from the algorithm you remember
    vector<int> lcp;
    sparse_table<int> rmq;

    suffix_array() {}

    suffix_array(const string &inp, bool build_rmq = false) {
        build(inp, build_rmq);
    }

    void build(const string &inp, bool build_rmq = false) {
        str = inp;
        str.pb(char(31)); // assumes that the char(31) is not part of the string and smallest.

        n = sz(str);
        suffix.rsz(n);
        rank.rsz(n);
        iota(suffix.begin(), suffix.end(), 0);
        // first level sort, rather than doing O(n) with counting, we just do O(n logn)
        sort(suffix.begin(), suffix.end(), [&](int a, int b) { return str[a] < str[b]; });

        rank[suffix[0]] = 0;
        repA(i, 1, n - 1) {
            if (str[suffix[i - 1]] == str[suffix[i]]) {
                rank[suffix[i]] = rank[suffix[i - 1]];
            } else {
                rank[suffix[i]] = i;
            }
        }

        vector<int> trank(n);
        vector<int> tsuffix(n);

        vector<int> count(n);

        bool done = false;
        for (int len = 1; len < n && !done; len *= 2) {
            // second half sorted
            rep(i, n) {
                tsuffix[i] = (suffix[i] - len + n) % n;
            }

            fill(count.begin(), count.end(), 0);
            rep(i, n) {
                count[rank[tsuffix[i]]]++;
            }
            rep(i, n - 1) {
                count[i + 1] += count[i];
            }

            repD(i, n - 1, 0) {
                suffix[--count[rank[tsuffix[i]]]] = tsuffix[i];
            }

            done = true;
            trank[suffix[0]] = 0;
            repA(i, 1, n - 1) {
                auto curr = mp(rank[suffix[i]], rank[(suffix[i] + len) % n]);
                auto prev = mp(rank[suffix[i - 1]], rank[(suffix[i - 1] + len) % n]);

                if (prev == curr) {
                    trank[suffix[i]] = trank[suffix[i - 1]];
                    done = false;
                } else {
                    trank[suffix[i]] = i;
                }
            }
            rank.swap(trank);
        }

        compute_lcp();

        if (build_rmq)
            rmq.build(lcp);
    }

    // assumes suffix and rank are populated
    void compute_lcp() {
        lcp.rsz(n);

        int k = 0;

        dbg(suffix, rank);
        rep(i, n - 1) {
            int a = i + k;
            dbg(rank[i], n, i, k);
            assert(rank[i] - 1 < n);
            int b = suffix[rank[i] - 1] + k;
            while (a < n - 1 && b < n - 1 && str[a] == str[b]) {
                k++, a++, b++;
            }

            lcp[rank[i] - 1] = k;

            k = k == 0 ? k : k - 1;
        }
    }

    int get_lcp(int i, int j){
        int ri = min(rank[i], rank[j]);
        int rj = max(rank[i], rank[j]);
        assert(rj > ri);
        return  rmq.query(ri, rj - 1);
    }

};

// clang-format on
void solve() {
    string s1;
    cin >> s1;

    suffix_array SA(s1, true);

    int m;
    cin >> m;

    vii arr(m);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        dbg(a, b);
        assert(a <= b && 1 <= a && b <= sz(s1));
        a--, b--;
        arr[i] = mp(a, b);
    }

    auto comp = [&](int i, int j) {
        dbg(i, j);
        pii x = arr[i], y = arr[j];

        if(x == y){
            return i < j;
        }

        if (x.first == y.first) {
            return x.second <= y.second;
        }

        int common = SA.get_lcp(x.first, y.first);
        int d1 = x.second - x.first + 1, d2 = y.second - y.first + 1;

        if(common < d1 && common < d2){
            return SA.rank[x.first] < SA.rank[y.first];
        }

        if (d1 <= common && d2 <= common) {
            if(d1 == d2){
                return x.first < y.first;
            }
            return d1 < d2;
        }
        return d1 < d2;

    };
    dbg(s1);

    vi idx(m);
    iota(all(idx), 0);

    sort(all(idx), comp);

    rep(i, m){
        pii x = arr[idx[i]];
        cout << x.first + 1 << spc << x.second + 1 << endl;
    }
}

signed main() {
    fastio;

    solve();

    return 0;
}

