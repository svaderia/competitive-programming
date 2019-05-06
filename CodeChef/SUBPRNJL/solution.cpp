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
        int N, K;
        cin >> N >> K;

        int arr[N];
        rep(i, N){
            cin >> arr[i];
        }

        int beautiful = 0;
        repA(start, 0, N-1){
            int count[2001] = {0};
            set<int> s;
            int prev_m = 0;
            int prev_X = 0;
            repA(end, start, N-1){
                if(prev_m == 1 && arr[end] > prev_X){
                    s.insert(arr[end]);
                    count[arr[end]] += 1;
                    int F = count[prev_X];

                    if(count[F] > 0){
                        beautiful++;
                    }
                }else{
                    s.insert(arr[end]);
                    count[arr[end]] += 1;

                    int m = ceil( double(K) / (end - start + 1));

                    int sum = m * (end - start + 1);
                    int X;
                    for(typeof(s.rbegin()) it = (s).rbegin(); it != (s).rend(); it++){
                        sum -= count[*it] * m;
                        if(sum < K){
                            X = *it;
                            break;
                        }
                    }

                    int F = count[X];

                    if(count[F] > 0){
                        beautiful++;
                    }
                    prev_m = m;
                    prev_X = X;
 
                }
            }
        }
        cout << beautiful << endl;
    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}