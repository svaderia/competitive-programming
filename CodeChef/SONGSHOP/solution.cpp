#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define fill(a)  memset(a, 0, sizeof (a))

double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }
template<typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}

lli dp[2005][1005];
vii fin;
int N, M, P;

lli solve(int i, int P, int* va, int* pa, int* vs, int* ps, int* sz){
    if(dp[i][P] != -1){
        return dp[i][P];
    }
    if(i >= N+M)
        return 0;
    
    if(fin[i].first == 0){
        int v = vs[fin[i].second];
        int p = ps[fin[i].second];

        dp[i][P] = solve(i+1, P, va, pa, vs, ps, sz);

        if(p <= P){
            lli n = solve(i+1, P-p, va, pa, vs, ps, sz) + v;
            dp[i][P] = max(dp[i][P], n);
        }
    }else{
        int v = va[fin[i].second];
        int p = pa[fin[i].second];

        dp[i][P] = solve(i+1, P, va, pa, vs, ps, sz);

        if(p <= P){
            int s = sz[fin[i].second];
            lli n = solve(i+s+1, P-p, va, pa, vs, ps, sz) + v;
            dp[i][P] = max(dp[i][P], n);
        }
    }

    return dp[i][P];
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    cin >> N >> M >> P;


    vi albums[M];
    int va[M];
    fill(va);
    int pa[M];
    
    int vs[N];
    int ps[N];

    int sz[M];

    int a, p, v;
    rep(i, N){
        cin >> a >> p >> v;
        a--;
        albums[a].pb(i);
        va[a] += v;
        vs[i] = v;
        ps[i] = p;
    }
    rep(i, M){
        cin >> pa[i];
    }

    rep(i, M){
        fin.pb(mp(1, i));
        tr(albums[i], it){
            fin.pb(mp(0, *it));
        }
    }
    rep(i, M){
        sz[i] = albums[i].size();
    }

    rep(i, fin.size()){
        rep(j, P+1){
            dp[i][j] = -1;
        }
    }

    cout << solve(0, P, va, pa, vs, ps, sz) << endl;
        
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
