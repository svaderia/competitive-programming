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
    int n;
    cin >> n;

    vi prufer(n - 2);
    rep(i, n - 2){
        cin >> prufer[i];
        prufer[i]--;
    }

    vi out(n);
    out[n - 1]++;
    rep(i, n - 2){
        out[prufer[i]]++;
    }
    set<int> vacant;
    rep(i, n){
        if(out[i] == 0) vacant.insert(i);
    }

    vii ans;
    rep(i, n - 2){
        auto mn = vacant.begin();
        vacant.erase(mn);
        ans.pb(mp(*mn, prufer[i]));
        out[prufer[i]]--;
        if(out[prufer[i]] == 0){
            vacant.insert(prufer[i]);
        }
    }
    ans.pb(mp(*vacant.begin(), n - 1));

    for(auto e : ans){
        cout << e.f + 1 << spc << e.s + 1 << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
