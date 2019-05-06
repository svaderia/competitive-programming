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
        int N;
        cin >> N;
        string s;
        cin >> s;

        int arr[N] = {0};
        
        for(int i = 1; i < N; i++){
            if(s[i] == s[0]){
                // cout << "count " << i << endl;
                for(int j = i, k = 0; j < N && k < i; j++, k++){
                    if(s[j] == s[k]){
                        arr[k+1]++;
                    }else{
                        break;
                    }
                }
            }
        }

        int max_length = -1;
        int max_index = 0;
        for( int k = 0; k < N; k++){
            // cout << arr[k] << endl;
            if( arr[k] >= max_length){
                max_length = arr[k];
                max_index = k;
            }
        }

        if(max_length == 0){
            cout << s << endl;
        }else{
            for(int j = 0; j < max_index; j++){
                cout << s[j];
            }
            cout << endl;
        }
    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}