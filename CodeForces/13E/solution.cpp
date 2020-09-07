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

const int MAXN = 1e5 + 5;
const int BS = 320;
int n;
bool invalid[MAXN];
int a[MAXN], steps[MAXN], reach[MAXN];

void check(int cb){

    invalid[cb] = false;
    int start = cb * BS;
    int end = min(start + BS, n);

    repD(x, end - 1, start){
        if(x + a[x] < end){
            steps[x] = 1 + steps[x + a[x]];
            reach[x] = a[x] + reach[x + a[x]];
        } else{
            steps[x] = 0;
            reach[x] = 0;
        }
    }
}

void solve(){

    int m;
    scanf("%d %d", &n, &m);

    rep(i, n){
        scanf("%d", a + i);
    }

    rep(x, n / BS + 1){
        invalid[x] = true;
    }

    rep(_, m){
        int type;
        scanf("%d", &type);
        if(type == 0){
            int x, y;
            scanf("%d %d", &x, &y);
            x--;
            a[x] = y;
            invalid[x / BS] = true;
        }else{
            int x;
            scanf("%d", &x);
            x--;
            int ans = 1;
            while(1){
                int cb = x / BS;
                if(invalid[cb])
                    check(cb);
                ans += steps[x];
                x += reach[x];
                if(x + a[x] >= n)
                    break;
                ans++;
                x += a[x];
            }
            printf("%d %d\n", x + 1, ans);
        }
    }

}

signed main(){

    solve();

    return 0;
}


