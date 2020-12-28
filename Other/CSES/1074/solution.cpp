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

vi arr;

int cost(int val){
    int temp = 0;
    for(auto x : arr){
        temp += abs(x - val);
    }
    return temp;
}

void solve(){

    int n;
    cin >> n;

    arr.rsz(n);
    rep(i, n){
        cin >> arr[i];
    }

    int l = 0, r = MOD;
    int eps = 60;

    while(r - l > eps){
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int v1 = cost(m1);
        int v2 = cost(m2);

        if(v1 < v2){
            r = m2;
        }else{
            l = m1;
        }
    }
    int ans = INF;
    repA(i, l, r){
        int v = cost(i);
        if(v < ans){
            ans = v;
        }
    }

    cout << ans << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
