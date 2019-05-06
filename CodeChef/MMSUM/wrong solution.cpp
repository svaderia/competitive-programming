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

        vi arr(N+2);
        rep(i, N){
            cin >> arr[i];
        }

        vi all_sum;
        int max_sum = arr[0];
        int sum = 0;
        int left = 0, right;
        int fin_left;
        map <int, int> rights;
        rep(i, N){
            int temp = sum;
            sum = sum + arr[i];
            if(sum >= max_sum ){
                max_sum = sum;
                right = i;
                fin_left = left;
            }
            if(sum >= temp){
                rights[left] = i;
            }
            all_sum.push_back(sum);
            if(sum < 0){
                left = i+1;
                sum = 0;
            }
        }

        int min_ele;
        int ans = -1000;
        // cout << "yolo" << endl;
        // cout << fin_left << endl;
        tr(all_sum, it){
            cout << *it << " " ;
        }
        cout << endl;

        if(fin_left != right){
            min_ele = *min_element(arr.begin() + fin_left, arr.begin() + right);
            ans = max_sum;

            if(min_ele < 0){
                ans = max(ans, max_sum - min_ele);
            }
            if((fin_left - 2 >= 0) && all_sum[fin_left - 2] > 0){
                ans = max(ans, max_sum + all_sum[fin_left - 2]);
                // cout << "left " << max_sum + all_sum[fin_left - 2] << endl;
            }

            if(right + 2 < N && present(rights, right + 2) && all_sum[rights[right+2]] > 0){
                ans = max(ans, max_sum + all_sum[rights[right+2]]);
                // cout << "right " << max_sum + all_sum[rights[right+2]] << endl;
            }else if(right + 2 < N){
                int j = right + 2;
                int m = all_sum[j];
                while(j < N && all_sum[j] > 0){
                    m = max(m, all_sum[j]);
                    j++;
                }
                ans = max(ans, max_sum + m - all_sum[right+1]);
                // cout << "right "  << max_sum + m - all_sum[right+1] << endl;
            }
        }
        else{
            min_ele = arr[fin_left];
            ans = min_ele;
            if(fin_left - 2 >= 0 && all_sum[fin_left - 2] > 0){
                ans = max_sum + all_sum[fin_left - 2];
            }

            if(right + 2 < N && present(rights, right + 2) && all_sum[rights[right+2]] > 0){
                ans = max(ans, max_sum + all_sum[rights[right+2]]);
                // cout << "right " << max_sum + all_sum[rights[right+2]] << endl;
            }else if(right + 2 < N){
                int j = right + 2;
                int m = all_sum[j];
                while(j < N && all_sum[j] > 0){
                    m = max(m, all_sum[j]);
                    j++;
                }
                ans = max(ans, max_sum + m - all_sum[right+1]);
                // cout << "right "  << max_sum + m - all_sum[right+1] << endl;
            }
        }
                
        // cout << min_ele << endl;
        // cout << fin_left << " " << right << endl;
        cout << ans << endl;
    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}