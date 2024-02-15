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

    vector<string> dir(n);
    vi x(n), y(n);

    rep(i, n){
        cin >> dir[i] >> x[i] >> y[i];
    }

    vi fans(n, -1);

    rep(ii, n){
        vi tans(n);
        rep(i, n){
            int ans = INF;
            rep(j, n){
                if(dir[i] != dir[j]){
                    if(dir[i] == "E"){
                        if(x[j] > x[i] && y[j] < y[i]){
                            int d1 = x[j] - x[i];
                            int d2 = y[i] - y[j];
                            if(d2 < d1 && fans[j] != -1 && fans[j] > d2){
                                ans = min(ans, d1);
                            }
                            /* cout << i << spc << j << spc << d1 << spc << d2 << endl; */
                        }
                    }else{
                        if(y[j] > y[i] && x[j] < x[i]){
                            int d1 = y[j] - y[i];
                            int d2 = x[i] - x[j];
                            if(d2 < d1 && fans[j] != -1 && fans[j] > d2){
                                ans = min(ans, d1);
                            }
                            /* cout << i << spc << j << spc << d1 << spc << d2 << endl; */
                        }
                    }
                }
            }
            tans[i] = ans;
        }
        rep(i, n){
            fans[i] = tans[i];
        }
    }

    rep(i, n){
        if(fans[i] == INF) cout << "Infinity" << endl;
        else cout << fans[i] << endl;
    }
}

signed main(){
    fastio;

    solve();

    return 0;
}
