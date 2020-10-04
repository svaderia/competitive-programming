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

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}

int main(){
    fastio;

    int N;
    cin >> N;

    lli arr[N];

    for(int i = 0; i < N ; i++){
        cin >> arr[i];
    }

    stack<lli> s;

    lli max = -1;
    for(int i = 0; i < N; i++){
        while(!s.empty() && arr[i] > s.top()){
            lli now = s.top();
            s.pop();
            lli temp1 = now ^ arr[i];
            if(temp1 > max) max = temp1;
        }
        if(!s.empty()){
            lli now = s.top();
            lli temp1 = now ^ arr[i];
            if(temp1 > max) max = temp1;
        }
        s.push(arr[i]);
    }

    cout << max << endl;
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
