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

    vector<char> temp(n);
    vi data(n);

    rep(i, n){
        cin >> temp[i];
        data[i] = temp[i] == '1';
    }

    int curr = 0;
    bool l = true;
    int mn_nights = INF;

    vi nights;

    rep(i,n){
        if(data[i] == 0){
            if(l){
                if(curr) mn_nights = min(mn_nights, (curr - 1));
                l = false;
            }else{
                if(curr) mn_nights = min(mn_nights, (curr - 1) / 2);
            }
            if(curr) nights.pb(curr);
            curr = 0;
        }else{
            curr++;
        }
    }
    if(curr) mn_nights = min(mn_nights, (curr - 1));
    if(curr) nights.pb(curr);

    int ans = 0;

    for(auto x : nights){
        ans += (x + 2*mn_nights) / (2 * mn_nights + 1);
    }

    cout << ans << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
