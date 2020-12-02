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

    const int n = 4;
    vii p(n);
    rep(i, n){
        cin >> p[i].f >> p[i].s;
    }

    array<int, 4> perm = {0, 1, 2, 3};

    vi cx(n), cy(n);
    auto cost = [&](int k){
        rep(i, n){
            cx[i] = p[perm[i]].f;
            cy[i] = p[perm[i]].s;
        }

        cx[0] -= k, cx[2] -= k;
        cy[1] -= k, cy[2] -= k;
        sort(all(cx));
        sort(all(cy));

        int cst = 0;
        rep(i, n)
            cst += abs(cx[i] - cx[1]) + abs(cy[i] - cy[1]);
        return cst;
    };

    int ans = INF;
    do{
        int l = 0, r = MOD;

        while(l < r){
            int mid = (l + r) / 2;
            if(cost(mid) < cost(mid + 1))
                r = mid;
            else
                l = mid + 1;
        }
        ans = min(ans, cost(l));
        if(ans == 0) break;

    }while(next_permutation(all(perm)));

    cout << ans << endl;

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
