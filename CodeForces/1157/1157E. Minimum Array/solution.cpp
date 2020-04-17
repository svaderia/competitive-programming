#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    new_data_set; 

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



int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int N;
    cin >> N;

    int temp;
    vi a, c;
    map<int, int> b;
    new_data_set b2;
    rep(i, N){
        cin >> temp;
        a.pb(temp);
    }

    rep(i, N){
        cin >> temp;
        if(present(b, temp)){
            b[temp] += 1;
        }else{
            b[temp] = 1;
            b2.insert(temp);
        }
    }

    // sort(all(b));
    rep(i, N){
        int pos1 = b2.order_of_key(N - a[i]);
        int mins = 0;
        int p1 = *b2.find_by_order(pos1);
        int mn = *b2.find_by_order(0);
        if( pos1 != b2.size() &&  ((p1 + a[i])%N ) < (mn + a[i])%N){
            c.pb(p1);
            if(b[p1] == 1){
                b2.erase(p1);
            }
            b[p1]--;
        }else{
            c.pb(mn);
            if(b[mn] == 1){
                b2.erase(mn);
            }
            b[mn]--;
        }
    }


    rep(i, N){
        cout << (c[i] + a[i]) % N << " ";
    }
    cout << endl;


    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
