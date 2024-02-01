#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
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
#define endl "\n"
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

typedef pair<pii, int> state;
typedef pair<state, state> pss;

const int MX = 20;

int get_id(pss s1){
    int id = s1.f.f.f;
    id *= MX;
    id += s1.f.f.s;
    id *= MX;
    id += s1.f.s;
    id *= MX;
    id += s1.s.f.f;
    id *= MX;
    id += s1.s.f.s;
    id *= MX;
    id += s1.s.s;
    return id;
}

int ark[100];

struct chash {
    const int RANDOM = (long long)(ark) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(pss x) const { return hash_f(get_id(x))^RANDOM; }
};
gp_hash_table<pss, int, chash> dp; // Hash table, good alternative of unordered_map

void solve(){
    int n;
    cin >> n;

    vector<string> s(n);
    rep(i, n){
        cin >> s[i];
    }

    vvi arr(n, vi(n));
    rep(i, n){
        rep(j, n){
            arr[i][j] = (s[i][j] == 'E');
        }
    }

    pii end = {0, n - 1};
    auto turn_left = [&](state s1) -> state {
        if(s1.f == end) return s1;
        return {{s1.f.f, s1.f.s}, (s1.s - 1 + 4) % 4};
    };

    auto turn_right = [&](state s1) -> state {
        if(s1.f == end) return s1;
        return {{s1.f.f, s1.f.s}, (s1.s + 1) % 4};
    };

    auto inside = [&](int x, int y) -> bool {
        return 0 <= x && x < n && 0 <= y && y < n && arr[x][y] == 1;
    };

    auto forward = [&](state s1) -> state {
        if(s1.f == end) return s1;
        int dir = s1.s;
        int x1 = s1.f.f + dx[dir];
        int y1 = s1.f.s + dy[dir];
        if(inside(x1, y1))
            return {{x1, y1}, dir};
        return s1;
    };

    pss start = { {{n - 1, 0}, 0}, {{n - 1, 0}, 1} };

    dp[start] = 0;

    queue<pss> q;
    q.push(start);

    int ans = 0;
    while(!q.empty()){
        state s1 = q.front().f, s2 = q.front().s;
        int w = dp[q.front()];
        q.pop();
        if(s1.f == end && s2.f == end){
            ans = w;
            break;
        }
        vector<pss> new_states;
        new_states.pb(mp(turn_left(s1), turn_left(s2)));
        new_states.pb(mp(turn_right(s1), turn_right(s2)));
        new_states.pb(mp(forward(s1), forward(s2)));

        for(auto ss : new_states){
            if(!present(dp, ss) || dp[ss] > w + 1){
                dp[ss] = w + 1;
                q.push(ss);
            }
        }
    }

    cout << ans << endl;

}

signed main(){
#ifndef DEBUG
    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);
#endif

    fastio;

    solve();

    return 0;
}
