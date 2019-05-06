#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}

class PrimePolynom{
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

    int eval_poly(int A, int B, int C, int M){
        return (A*M*M + B*M + C);
    }
    
    public:
    int reveal(int A, int B, int C){
        int M = 0;
        while(true){
            int n = eval_poly(A, B, C, M);
            bool yeah = is_prime(n);
            if(!yeah)
                break;
            M++;
        }
        cout << M;
        // cout<<"Execution time : "<<tick()<<"\n";
        return 0;
    }
};

