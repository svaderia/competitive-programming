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
        int non_sorted_L[N], L[N];
        int non_sorted_R[N], R[N];
        int max_R = 0;
        for(int i = 0 ; i < N; i++){
            cin >> L[i] >> R[i];
            L[i]--; R[i]--;
            non_sorted_L[i] = L[i];
            non_sorted_R[i] = R[i];
            if(R[i] > max_R) max_R = R[i];
        }
        max_R++;
        int cakes[max_R] = {0};
        int left_K[max_R] = {0};
        int left_K_plus[max_R] = {0};
        int cur = 0;
        sort(L, L+N);
        sort(R, R+N);
        int l = 0, r = 0;
        for(int i = 0; i < max_R; i++ ){
            while(L[l] == i && l < N){
                l++;
                cur++;
            }
            if(i > 0){
                if(cur == K ){
                    left_K[i] = left_K[i - 1] + 1;
                }else{
                    left_K[i] = left_K[i - 1];
                }
                if(cur == K + 1){
                    left_K_plus[i] = left_K_plus[i - 1] + 1;
                }else{
                    left_K_plus[i] = left_K_plus[i - 1];
                }
            }else{
                if(cur == K){
                    left_K[0] = 1;
                }
                if(cur == K+1)
                    left_K_plus[0] = 1 ;
            }
            cakes[i] = cur;
            
            while(R[r] == i && r <N ){
                cur--;
                r++;
            }
        }

        int max_K = 0;

        for(int i = 0; i < N; i++){
            int c_max = left_K[max_R - 1];
            if(non_sorted_L[i] > 0){
                c_max += left_K[non_sorted_L[i] - 1];
                c_max -= left_K_plus[non_sorted_L[i] - 1];
            }
            c_max += left_K_plus[non_sorted_R[i]];
            c_max -= left_K[non_sorted_R[i]];
            // cout << c_max << endl;
            if( c_max > max_K) max_K = c_max;
        }

        cout << max_K << endl;

        // for(int i = 0; i < max_R; i++){
            // cout << cakes[i] << endl;
            // cout << left_K[i] << "  " << left_K_plus[i] << endl;
        // }
        
    
    }

    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}