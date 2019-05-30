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

int id[10005];
int val[10005];

int root(int p){
    while(p != id[p]){
        id[p] = id[id[p]];
        p = id[p];
    }
    return p;
}

bool unite(int a, int b){
    int p1 = root(a);
    int p2 = root(b);
    if(p1 != p2){
        if(val[p1] < val[p2]){
            id[p1] = p2;
            val[p2] = max(val[p1], val[p2]);
        }else if(val[p2] < val[p1]){
            id[p2] = p1;
            val[p1] = max(val[p1], val[p2]);
        }
        return true;
    }
    return false;
}

void init_dsu(int N){
    rep(i, N){
        id[i] = i;
    }
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

        int vrr[N];
        rep(i, N){
            cin >> vrr[i];
        }

        int Q;
        cin >> Q;

        init_dsu(N);
        rep(i, N){
            val[i] = vrr[i];
        }

        rep(i, Q){
            int action;
            cin >> action;

            if(action){
                int x;
                cin >> x;

                cout << root(x-1) + 1<< endl;
            }else{
                int x, y;
                cin >> x >> y;
                x--; y--;
                if(!unite(x, y)){
                    cout << "Invalid query!" << endl;
                }
            }
        }


    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
