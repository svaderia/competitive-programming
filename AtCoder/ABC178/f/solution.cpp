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

void solve(){

    int n;
    cin >> n;

    vi a(n);
    rep(i, n){
        cin >> a[i];
    }
    vi b(n);
    rep(i, n){
        cin >> b[i];
    }
    reverse(all(b));

    int c = -1;
    int l = n + 1;
    int r = -1;

    rep(i, n){
        if(a[i] == b[i]){
            c = a[i];
            l = min(l, i);
            r = max(r, i);
        }
    }

    int pos = true;

    if(c != -1){
        vb mark(n);
        rep(i, n){
            if(a[i] != c && b[i] != c){
                mark[i] = true;
            }
        }

        int st = l;
        rep(i, n){
            if(mark[i]){
                swap(b[i], b[st++]);
                if(st > r) break;
            }
        }

        if(st <= r) pos = false;
    }

    if(pos){
        cout << "Yes" << endl;
        rep(i, n) cout << b[i] << spc;
        cout << endl;
    }else{
        cout << "No" << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
