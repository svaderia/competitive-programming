#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
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


int arr[6] = {16, 8, 15, 4, 23, 42};

bool p(int x){
    rep(i, 6){
        if(arr[i] == x)
            return true;
    }

    return false;
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;


    int a1, a2, a3, a4, a5, a6;

    cout << "? 1 2" << endl;

    int a12;
    cin >> a12;

    rep(i, 6){
        if(a12 % arr[i] == 0 && p(a12/arr[i]) && arr[i] != a12/arr[i]){
            a1 = arr[i];
            a2 = a12/arr[i];
        }
    }
    cout << "? 1 3" << endl;

    int a13;
    cin >> a13;

    if(a13 % a1 == 0 && p(a13/a1) && a1 != a13/a1){
        a3 = a13/a1;
    }else{
        swap(a1, a2);
        a3 = a13/a1;
    }

    cout << "? 4 5" << endl;

    int a45;
    cin >> a45;

    rep(i, 6){
        if(a45 % arr[i] == 0 && p(a45/arr[i]) && arr[i] != a45/arr[i]){
            a4 = arr[i];
            a5 = a45/arr[i];
        }
    }
    cout << "? 4 6" << endl;

    int a46;
    cin >> a46;

    if(a46 % a4 == 0 && p(a46/a4) && a4 != a46/a4){
        a6 = a46/a4;
    }else{
        swap(a4, a5);
        a6 = a46/a4;
    }

    cout << "! " << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << " " << a6 << endl;



    
        
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
