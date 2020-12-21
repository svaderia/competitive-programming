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
    string s;
    cin >> s;

    int x, y;
    cin >> x >> y;

    int n = sz(s);
    vi arr(n);
    rep(i, n){
        arr[i] = s[i] == '0' ? 0 : (s[i] == '1' ? 1 : 2);
    }

    vvi pref(n + 1, vi(3));
    rep(i, n){
        rep(j, 3){
            pref[i + 1][j] = pref[i][j];
        }
        pref[i + 1][arr[i]]++;
    }

    vvi suf(n + 1, vi(3));
    repD(i, n - 1, 0){
        rep(j, 3){
            suf[i][j] = suf[i + 1][j];
        }
        suf[i][arr[i]]++;
    }

    // treat each question mark as zero
    int sum = 0;
    rep(i, n){
        if(arr[i] == 0 || arr[i] == 2){
            sum += pref[i][1] * y;
        }else{
            sum += (pref[i][0] + pref[i][2]) * x;
        }
    }

    int ans = sum;
    int tsum = sum;
    // replace prefix ? with 1 and compare the cost;
    rep(i, n){
        if(arr[i] == 2){
            tsum -= (suf[i + 1][1] * x) + (pref[i][1] + pref[i][2]) * y;
            tsum += pref[i][0] * x + (suf[i + 1][0] + suf[i + 1][2]) * y;
            ans = min(ans, tsum);
        }
    }
    // replace suffix ? with 1 and compare the cost;
    tsum = sum;
    repD(i, n - 1, 0){
        if(arr[i] == 2){
            tsum -= (suf[i + 1][1] + suf[i + 1][2]) * x + pref[i][1] * y;
            tsum += (pref[i][0] + pref[i][2]) * x + suf[i + 1][0] * y;
            ans = min(ans, tsum);
        }
    }

    cout << ans << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
