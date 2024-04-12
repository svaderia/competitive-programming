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
// Remove this when it's an interactive problem
#define endl "\n"
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

void solve(){

    int n, k; 
    cin >> n >> k; 
    
    vi l(n);
    set<int> lset;
    rep(i, n){
        cin >> l[i];
        lset.insert(l[i]);
    }

    vi r(n);
    set<int> rset;
    rep(i, n){
        cin >> r[i];
        rset.insert(r[i]);
    }
    int total = 2 * k;

    vi al, ar;

    rep(i, n){
        if(present(rset, l[i])){
            al.pb(l[i]);
            ar.pb(l[i]);
            total--;
            lset.erase(l[i]);
            rset.erase(l[i]);
        }
        if(total == 0){
            break;
        }
    }
    if (total % 2 == 1){
        al.pop_back();
        ar.pop_back();
        total++;
    }


    if(total != 0){
        int x = total;
        rep(i, n){
            if(present(lset, l[i])){
                al.pb(l[i]);
                al.pb(l[i]);
                x--;
                x--;
                lset.erase(l[i]);
            }
            if(x == 0){
                break;
            }
        }
        x = total;
        rep(i, n){
            if(present(rset, r[i])){
                ar.pb(r[i]);
                ar.pb(r[i]);
                x--;
                x--;
                rset.erase(r[i]);
            }
            if( x == 0){
                break;
            }
        }
    }

    rep(i, 2 * k){
        cout << al[i] << spc;
    }
    cout << endl;


    rep(i, 2 * k){
        cout << ar[i] << spc;
    }
    cout << endl;





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
