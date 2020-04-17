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

bool is_prime(int n){
    bool yeah = true;
    if( n <= 1){
        yeah = false;
    }else{
        int temp = int(ceil(sqrt(n)));
        for(int i = 2; i < temp; i++){
            if(n % i == 0){
                yeah = false;
                break;
            }
        }
        if( temp * temp == n){
            yeah = false;
        }
    }

    return yeah;
}

vli get_divisors(lli n){
    vli ans;
    lli temp = lli(ceil( sqrt(n)));
    for(lli i = 2; i < temp; i++){
        if(n % i == 0){
            ans.pb(i);
            ans.pb(n/i);
        }
    }
    if(temp * temp == n){
        ans.pb(temp);
    }
    sort(all(ans));
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
        int N;
        cin >> N;

        vi di(N);
        rep(i, N){
            cin >> di[i];
        }

        sort(all(di));

        lli ans = -1;

        if(is_prime(di[0])){
            lli tp = di[N-1] * (lli)di[0];
            vli tp2 = get_divisors(tp);
            if(tp2.size() == N){
                ans = tp;
                rep(i, N){
                    if(tp2[i] != di[i]){
                        ans = -1;
                        break;
                    }
                }
            }
        }



        cout << ans << endl;
    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
