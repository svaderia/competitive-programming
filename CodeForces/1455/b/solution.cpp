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

const int MAXJ = 10000;

int calc(int k, int back){
    return ((k - 1) * back) + (k * (k + 1)) / 2;
}

int find_pos(int back, int x){
    int k = 0;
    for(int z = MAXJ; z > 0; z /= 2){
        while(calc(k + z, back) < x) k += z;
    }
    return k;
}

void solve(){
    int x;
    cin >> x;

    int ans = INF;
    int back = 0;
    while(back <= ans){
        int k = back;
        int pos = -back;
        int dk = find_pos(back, x) + 1;
        pos = calc(dk, back);
        k += dk;

        ans = min(ans, k + (pos - x));
        pos -= k;
        k--;
        int diff = x - pos;
        if(diff < k){
            ans = min(ans, k + 1);
        }
        back++;
    }
    cout << ans << endl;

}

signed main(){
    fastio;

    int T;
    cin >> T;

    repA(tc, 1, T){
        solve();
    }

    return 0;
}


