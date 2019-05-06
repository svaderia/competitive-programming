#include <bits/stdc++.h>
using namespace std;
#include <algorithm>

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

        int arr[N];
        // vector<int> yoga(2001);
        // for(int i = 0; i < 2001; i++){
        //     yoga[i] = 0;
        // }

        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        vector<int> v;
        int beautiful = 0;
        for(int start = 0; start < N; start++){
            for(int end = start; end < N; end++){
                v.pb(arr[end]);
                int m = ceil(float(K)/(end - start + 1));
                vector<int> v2;
                for(int j = 0; j < m; j++){
                    v2.insert(v2.end(), all(v));
                }
                sort(all(v2));
                int x = v2[K - 1];
                // tr(v2, it){
                //     cout << *it << " ";
                // }
                // cout << endl;
                // cout << "m " << m << endl;
                // cout << "x " << x << endl;
                int count = 0;
                tr(v, it){
                    if(*it == x){
                        count++;
                    }
                }
                // cout << "F " << count << endl;
                if(std::find(all(v), count) != v.end()){
                    beautiful++;
                }
            }
            v.clear();

        }

        cout << beautiful << endl;
    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}