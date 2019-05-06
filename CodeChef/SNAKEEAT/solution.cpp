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


bool p(int i, int pos, vli &acc_L, lli K){
    lli tp = ((pos - i + 1) * K - (acc_L[i] - acc_L[pos+1]));
    // cout << "i " << i << " val " << tp << endl;
    return tp <= (i);
}

int bin_search(vli &L, vli &acc_L, int pos, int K){
    int lo = 0;
    int hi = pos;
    while (lo < hi){
      int mid = lo + (hi-lo)/2 ;
      if(p(mid, pos, acc_L, K) == true)
         hi = mid;
      else
         lo = mid+1;
    }
         
    if (p(lo, pos, acc_L, K) == false)
      lo = pos+1;                // p(x) is false for all x in S!
   return lo;         // lo is the least x for which p(x) is true
}

int solve(vli &L, vli &acc_L, lli K){
    K--;
    int pos = upper_bound(all(L), K) - L.begin();
    int ans = L.size() - pos;
    // cout << ans << endl;
    ans += (pos - bin_search(L, acc_L, pos-1, K+1));
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        int N, Q;
        cin >> N >> Q;

        vli L;
        lli temp;
        rep(i, N){
            cin >> temp;
            L.pb(temp);
        }

        sort(all(L));
        vli acc_L(N+1);
        acc_L[N] = 0;
        repD(i, N-1, 0){
            acc_L[i] = acc_L[i+1] + L[i];
        } 

        rep(i, Q){
            lli K;
            cin >> K;
            cout << solve(L, acc_L, K) << endl;
        }
    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
