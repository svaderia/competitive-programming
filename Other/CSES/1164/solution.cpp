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
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
const int INF   = 1e18;

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

    vector<pair<pii, int>> arr(n);
    rep(i, n){
        cin >> arr[i].f.f >> arr[i].f.s;
        arr[i].s = i;
    }

    sort(all(arr));

    vi ans(n);
    set<pii> active;
    rep(i, n){
        auto it = active.lower_bound({arr[i].f.f, 0});
        if(it != active.begin()){
            it = prev(it);
            active.insert({arr[i].f.s, (*it).s});
            ans[arr[i].s] = (*it).s;
            active.erase(it);
        }else{
            active.insert({arr[i].f.s, sz(active) + 1});
            ans[arr[i].s] = sz(active);
        }
    }

    cout << sz(active) << endl;
    rep(i, n){
        cout << ans[i] << spc;
    }
    cout << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
