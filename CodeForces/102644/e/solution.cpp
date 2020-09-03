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
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};

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

int n = 8;
bool inside(int x, int y){
    return (0 <= x && x < n) && (0 <= y && y < n);
}

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

    int k;
    cin >> k;

    vector<vector<unsigned int> > mat(65, vector<unsigned int>(65, 0));

    rep(row, 8){
        rep(col, 8){

            for(auto dx : {2, -2, 1, -1}){
                for (auto dy : {2, -2, 1, -1}){
                    if(abs(dx) == abs(dy)) continue;
                    int new_col = col + dy;
                    int new_row = row + dx;

                    if(inside(new_row, new_col)){
                        mat[row * 8 + col][new_row * 8 + new_col] = 1;
                    }
                }
            }
        }
    }
    rep(i, 65){
        mat[i][64] = 1;
    }

    k++;
    vector<vector<unsigned int> > ans(65, vector<unsigned int>(65, 0));
    ans[0][0] = 1;

    while(k > 0){
        if(k&1){
            ans = mul(ans, mat);
        }
        k /= 2;
        mat = mul(mat, mat);
    }

    cout << ans[0][64] << endl;


}

signed main(){
    fastio;

    solve();

    return 0;
}
