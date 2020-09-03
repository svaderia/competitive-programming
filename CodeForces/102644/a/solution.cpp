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

template<typename T>
vector<T> mul(vector<T> a1, vector<T> a2){
    int dim = sz(a1);
    vector<T> ans(dim, T(dim));

    rep(i, dim){
        rep(j, dim){
            rep(k, dim){
                ans[i][j] += a1[i][k] * a2[k][j];
            }
        }
    }
    return ans;
}

void solve(){

    int n;
    cin >> n;
    long double p;
    cin >> p;

    cout.precision(12);
    cout << fixed;

    vector<vector<long double>> mat(2, vector<long double>(2));
    mat[0][0] = (1.0 - p);
    mat[0][1] = p;
    mat[1][0] = p;
    mat[1][1] = (1.0 - p);

    vector<vector<long double>> ans(all(mat));
    n--;
    while(n > 0){
        if(n&1){
            ans = mul(ans, mat);
        }
        n /= 2;
        mat = mul(mat, mat);
    }

    cout << ans[0][0] << endl;


}

signed main(){
    fastio;

    solve();

    return 0;
}
