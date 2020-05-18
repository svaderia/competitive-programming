#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define endl "\n"
#define error(x) cerr << #x << " = " << (x) << endl
#define errorp(p) cerr << #p << " = " << (p.first) << ", " << (p.second) << endl

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }
int mul(int a, int b, int c){lli res=(lli)a*b;return (int)(res>=c?res%c:res);}
template<typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}


signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int N;
    cin >> N;
    map<pii, int> myMap;
    int zero_both = MOD - 1;
    rep(i, N){
        int A, B;
        cin >> A >> B;
        bool neg = (A < 0 && B > 0) || (A > 0 && B < 0);
        if(A == 0 && B == 0){
            zero_both++;
            continue;
        }
        A = abs(A);
        B = abs(B);
        int g = gcd(A, B);
        A /= g;
        B /= g;
        pii pr = mp((neg ? -1 : 1) * A, B);
        myMap[pr]++;
    }
    int ans = 1;
    map<pii, bool> visited;
    for(auto f : myMap){
        pii val = f.first;
        int count = f.second;
        if(visited[val] != true){
            pii counter = mp(-1 * val.second, val.first);
            if((counter.first <= 0 && counter.second <= 0) || (counter.first >= 0 && counter.second <= 0)){
                counter.first *= -1;
                counter.second *= -1;
            }
            if(present(myMap, counter)){
                ans = mul(ans, (power(2LL, count, MOD) + power(2LL, myMap[counter], MOD) - 1) % MOD, MOD);
                myMap[counter] = 0;
                visited[counter] = true;
            }else{
                ans = mul(ans, power(2LL, count, MOD), MOD);
            }
        }
    }
    ans = (zero_both + ans) % MOD;
    cout << ans << endl;

    return 0;
}
