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

const int MAXN = 1e6 + 5;
vb mark(MAXN);
int ans = 1;

inline void update_ans(int y){
    if(mark[y]) ans = max(ans, y);
    mark[y] = true;
}

void get_divisors(int n){
    int temp = int(ceil( sqrt(n)));
    for(int i = 2; i < temp; i++){
        if(n % i == 0){
            update_ans(i);
            update_ans(n / i);
        }
    }
    if(temp * temp == n){
        update_ans(temp);
    }
    update_ans(n);
}

void solve(){
    int n;
    cin >> n;

    vi arr(n);
    rep(i, n){
        cin >> arr[i];
    }

    for(auto x : arr){
        get_divisors(x);
    }

    cout << ans << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
