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
    
    int T;
    cin >> T;

    while(T-- > 0){
        int N;
        cin >> N;

        vector< lli > arr;
        lli temp;
        rep(i, N){
            cin >> temp;
            arr.push_back(temp);
        }
        
        vector<lli> arr2;
        lli sum = 0;

        tr(arr, it){
            if(*it < 0){
                if(sum > 0)
                    arr2.push_back(sum);
                sum = 0;
                arr2.push_back(*it);
            }else{
                sum += *it;
            }
        }
        if( sum > 0)
            arr2.push_back(sum);

        int len2 = sz(arr2);
        vector<lli> right_sum(len2);
        lli msum = 0;
        repD(i, len2-1, 0){
            msum += arr2[i];
            right_sum[i] = msum;
            if(msum < 0){
                msum = 0;
            }
        }

        vector<lli> left_sum(len2);
        msum = 0;
        rep(i, len2){
            msum += arr2[i];
            left_sum[i] = msum;
            if(msum < 0){
                msum = 0;
            }
        }

        lli ans = *max_element(all(left_sum));

        rep(i, len2){
            if(arr2[i] < 0){
                lli temp = 0;
                if(i - 1 >= 0){
                    temp += left_sum[i-1];
                }
                if(i + 1 < len2){
                    temp += right_sum[i+1];
                }
                if( temp != 0){
                    ans = max(ans, temp);
                }
            }
        }
        cout << ans <<  endl;


    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}