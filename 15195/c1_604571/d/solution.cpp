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
#define endl "\n"
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

void solve(){
    int n, k;
    cin >> n >> k;

    vi used(n, 0);
    map<int, int> positions_a;

    vi a(k);
    rep(i, k){
        cin >> a[i];
        a[i]--;
        used[a[i]] = 1;
        positions_a[a[i]] = i;
    }
    vi b(k);
    rep(i, k){
        cin >> b[i];
        b[i]--;
        used[b[i]] = 1;
    }

    map<int, int> offsets_right;
    map<int, int> offsets_left;

    rep(i, k){
        int x = b[i];

        if(present(positions_a, x)){
            int offset_right = (positions_a[x] - i + k) % k;

            int offset_left = (positions_a[x] - k + i + k) % k;

            if(!present(offsets_right, offset_right)){
                offsets_right[offset_right] = 0;
            }
            if(!present(offsets_left, offset_left)){
                offsets_left[offset_left] = 0;
            }
            offsets_right[offset_right] += 1;
            offsets_left[offset_left] += 1;
        }
    }

    int ans = 0;

    rep(i, n){
        if(!used[i])
            ans++;
    }

    int mx = 0;
    for(auto x: offsets_right){
        mx = max(mx, x.second);
    }
    for(auto x: offsets_left){
        mx = max(mx, x.second);
    }

    cout << ans + mx << endl;
}

signed main(){
    fastio;

    solve();

    return 0;
}
