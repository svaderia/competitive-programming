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

bool check_digit_sorted(int n){
    int prev = 10;
    int y = n;
    while(y > 0){
        int c = y % 10;
        if(c > prev){
            return false;
        }
        y /= 10;
        prev = c;
    }

    return true;
}

int get_first_digit(int n){
    int prev = 0;
    while(n > 0){
        prev = n % 10;
        n /= 10;
    }
    return prev;
}


void solve(){
    int n;
    cin >> n;

    vi x(n);
    rep(i, n){
        cin >> x[i];
    }

    int l = x[n - 1];
    int ans = true;
    repD(i, n - 2, 0){
        int c = x[i];
        if( c <= l){
            l = c;
            continue;
        }
        if(check_digit_sorted(c)){
            int y = c % 10;
            if (y <= l){
                l = get_first_digit(c);
                continue;
            }else{
                ans = false;
                break;
            }


        }else{
            ans = false;
            break;
        }
        l = c;
    }

    if(ans){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }



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
