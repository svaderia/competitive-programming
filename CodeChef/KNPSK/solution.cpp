#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
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



int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int N;
    cin >> N;

    vi c1, c2;

    int w, c;
    int M = 0;
    rep(i, N){
        cin >> w >> c;
        M += w;
        if(w == 1){
            c1.push_back(c);
        }else{
            c2.push_back(c);
        }
    }

    sort(all(c1), greater<int>());
    vi v1(all(c2));
    vi v2(all(c2));
    
    lli ans[M + 1];

    int s1 = sz(c1);
    int s2 = sz(c2);
    ans[0] = 0;
    for(int i = 0; i < s1; i+=2){
        v1.push_back(c1[i] + c1[i+1]);
    }

    ans[1] = s1 > 0 ? c1[0] : 0;
    for(int i = 1; i < s1; i += 2){
        v2.push_back(c1[i] + c1[i+1]);
    }

    sort(all(v1), greater<int> ());
    sort(all(v2), greater<int> ());

    int i1 = 0;
    tr(v1, it){
        ans[2*i1 + 2] = ans[2*i1] + *it;
        i1++;
    }
    i1 = 1;
    tr(v2, it){
        ans[2*i1 + 1] = ans[2*i1 - 1] + *it;
        i1++;
    }

    repA(i, 1, M){
        cout << ans[i] << " ";
    }

    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}