#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
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

const int MAXK = 1e9 + 5;
void solve(){

    int n, q;
    cin >> n >> q;

    int lg = 63 - __builtin_clzll(MAXK);
    vvi child(n, vi(lg + 1));
    rep(i, n){
        cin >> child[i][0];
        child[i][0]--;
    }

    repA(st, 1, lg){
        rep(i, n){
            child[i][st] = child[child[i][st - 1]][st - 1];
        }
    }

    auto find = [&] (int root, int k){

        repD(st, lg, 0){
            if((k & (1ll << st)) > 0){
                root = child[root][st];
            }

        }
        return root + 1;
    };

    rep(i, q){
        int u, k;
        cin >> u >> k;
        u--;
        cout << find(u, k) << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
