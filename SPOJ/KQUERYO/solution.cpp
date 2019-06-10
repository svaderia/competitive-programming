#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto &i : c)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define fill(a)  memset(a, 0, sizeof (a))
#define error(x) cerr << #x << " = " << (x) <<endl

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }
int mul(int a, int b, int c){lli res=(lli)a*b;return (int)(res>=c?res%c:res);}
template<typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}

const int MAXN = 30005;
vi t[4*MAXN];
vi arr;
int N;

void build(int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        t[id].pb(arr[l]);
        return;
    }

    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id + 1, mid, r);
    merge(all(t[2*id]), all(t[2*id+1]), back_inserter(t[id]));
}

int cnt(int k, int x, int y, int id = 1, int l = 0, int r = N){
    if(x >= r || y <= l){
        return 0;
    }

    if(x <= l && r <= y){
        return t[id].size() - (upper_bound(all(t[id]), k) - t[id].begin());
    }

    int mid = (l+r)/2;
    return cnt(k, x, y, 2*id, l, mid) + cnt(k, x, y, 2*id + 1, mid, r);
}


int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    // fastio;
    
    // cin >> N;
    scanf("%d", &N);
    
    arr.resize(N);
    rep(i, N){
        // cin >> arr[i];
        scanf("%d", &arr[i]);
    }

    build();

    int Q;
    scanf("%d", &Q);

    int ans = 0;
    rep(i, Q){
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        l ^= ans;
        r ^= ans;
        k ^= ans;

        ans = cnt(k, l-1, r);
        cout << ans << endl;
    }
    

    return 0;
}
