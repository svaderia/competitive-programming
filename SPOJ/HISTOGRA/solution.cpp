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
    
    while(true){
        int N;
        cin >> N;
        if(N == 0 ) break;

        lli arr[N+1];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        arr[N] = 0;

        stack<pair<lli, lli> > s;

        pair<lli, lli> t;
        t.first = -1;
        t.second = 0;
        s.push(t);

        lli max = 0;

        for(int i = 0; i < N + 1; i++){
            while ((!s.empty()) && arr[i] < s.top().second){
                pair<lli, lli> x = s.top();
                s.pop();
                pair<lli, lli> r;
                // r.first = -1;
                // if(!s.empty())
                r = s.top();

                lli temp = (i - r.first - 1) * x.second;
                if(temp > max){
                    max = temp;
                }
            }
            pair<lli, lli> t;
            t.first = i;
            t.second = arr[i];
            s.push(t);
        }
        // pair<lli, lli> min = s.top();
        // s.pop();
        

        cout << max << endl;
    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}