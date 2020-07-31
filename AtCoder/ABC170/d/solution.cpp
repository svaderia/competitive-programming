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

const int MAXN = 1e6 + 5;
void solve(){
    int n;
    cin >> n;
    vi a(n);
    if(n == 1){
        cout << 1 << endl;
        return;
    }

    rep(i, n){
        cin >> a[i];
    }
    int ans = 0;

    sort(all(a));

    vi mark(MAXN);
    set<int> done;

    if(a[0] == 1){
        ans = a[1] == 1 ? 0 : 1;
    }else{
        rep(i, n){
            int num = a[i];
            if(present(done, num)){
                mark[num] = 1;
            }
            else{
                for(int j = 2 * num; j < MAXN; j += num){
                    mark[j] = 1;
                }
                done.insert(num);
            }
        }
        rep(i, n)
            if(!mark[a[i]]) ans++;
    }
    cout << ans << endl;
}

signed main(){
    fastio;

    solve();

    return 0;
}
