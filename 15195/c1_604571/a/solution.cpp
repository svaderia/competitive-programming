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
    int N;
    cin >> N;

    vi gallons(3, 7);

    vector<pair<int, pii>> inp;

    rep(ii, N){
        int day, up, whoi;
        string who;
        cin >> day;
        cin >> who;
        cin >> up;

        if(who == "Elsie") whoi = 0;
        if(who == "Mildred") whoi = 1;
        if(who == "Bessie") whoi = 2;

        inp.pb(mp(day, mp(whoi, up)));
        sort(all(inp));
    }

    int current_winner = 0;

    int ans = 0;

    rep(i, N){
        int whoi = inp[i].second.first;
        int up = inp[i].second.second;
        gallons[whoi] += up;

        int mx_val = -1;
        rep(j, 3){
            mx_val = max(mx_val, gallons[j]);
        }

        int winner = 0;
        /* cout << endl << i << endl; */
        rep(j, 3){
            if(gallons[j] == mx_val){
                winner += 1 << j;
            }
            /* cout << gallons[j] << spc; */
        }
        if(winner != current_winner){
            ans += 1;
        }
        current_winner = winner;
    }

    cout << ans;

}

signed main(){
    /* fastio; */
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    solve();

    return 0;
}
