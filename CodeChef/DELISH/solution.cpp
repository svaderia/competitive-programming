#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;

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

void print_vec(const vli arr){
    tr(arr, i){
        cout << *i << " ";
    }
    cout << endl;
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

        vli D;
        vli Dneg;
        lli temp;

        rep(i, N){
            cin >> temp;
            D.push_back(temp);
            Dneg.push_back(temp*-1);
        }

        // int len2 = sz(arr2);
        vector<lli> max_right_sum(N);
        lli msum = 0;
        repD(i, N-1, 0){
            msum += D[i];
            max_right_sum[i] = msum;
            if(msum < 0){
                msum = 0;
            }
        }

        vector<lli> max_left_sum(N);
        msum = 0;
        rep(i, N){
            msum += D[i];
            max_left_sum[i] = msum;
            if(msum < 0){
                msum = 0;
            }
        }

        vector<lli> min_right_sum(N);
        msum = 0;
        repD(i, N-1, 0){
            msum += D[i];
            min_right_sum[i] = msum;
            if(msum > 0){
                msum = 0;
            }
        }

        vector<lli> min_left_sum(N);
        msum = 0;
        rep(i, N){
            msum += D[i];
            min_left_sum[i] = msum;
            if(msum > 0){
                msum = 0;
            }
        }
        
        lli min = min_left_sum[0];
        rep(i, N){
            if(min > min_left_sum[i]){
                min = min_left_sum[i];
            }
            min_left_sum[i] = min;
        }

        min = min_right_sum[N-1];
        repD(i, N-1, 0){
            if(min > min_right_sum[i]){
                min = min_right_sum[i];
            }
            min_right_sum[i] = min;
        }

        lli ans = -1;

        repA(k, 1, N - 1){
            ans = max(ans, abs(max_right_sum[k] - min_left_sum[k-1]));
        }

        repA(k, 0, N-2){
            ans = max(ans, abs(max_left_sum[k] - min_right_sum[k+1]));
        }

        cout << ans << endl;
        // print_vec(max_right_sum);
        // print_vec(max_left_sum);
        // print_vec(min_right_sum);
        // print_vec(min_left_sum);
        // cout << endl;


    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
