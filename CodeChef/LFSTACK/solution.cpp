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

int is_possible(stack<int>* s, int N, int* fin, int total, int curr){
    int done = 0;
    if(curr >= total){
        done = 1;
    }else{
        for(int i = 0; i < N; i++){
            if(!s[i].empty() && s[i].top() == fin[curr]){
                int temp = s[i].top();
                s[i].pop();
                done = is_possible(s, N, fin, total, curr+1);
                if(done == 1){
                    break;
                }else{
                    s[i].push(temp);
                }
            }
        }
    }

    return done;
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
        stack<int> arr[N];
        int total = 0;

        for(int i = 0; i < N; i++){
            int l;
            cin >> l;
            total += l;
            int ele;
            for(int j = 0; j < l; j++){
                cin >> ele;
                arr[i].push(ele);
            }
        }

        int fin[total];

        for(int i = 0; i < total ; i++){
            cin >> fin[i];
        }

        int done = is_possible(arr, N, fin, total, 0);
        if(done == 1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }

    }
    
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}