#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto &i : c)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define fill(a)  memset(a, 0, sizeof (a))
#define error(x) cerr << #x << " = " << (x) << endl
#define errorp(p) cerr << #p << " = " << (p.first) << ", " << (p.second) << endl

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }
int mul(int a, int b, int c){lli res=(lli)a*b;return (int)(res>=c?res%c:res);}
template<typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}

struct node{
    lli sum, minsum;

    void assign(lli val){
        sum = minsum = val;
    }
}typedef node;

vector<node> seg;
int N;
vli arr;

//Complexity: O(1)
//Stores what info. segment[i..j] should store
node merge(node &left, node &right){
    node id;
    id.sum = left.sum + right.sum;
    id.minsum = min(left.minsum, left.sum + right.minsum);
    return id;
}

//Complexity: O(n)
void build(int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        //base case : leaf node information to be stored here
        seg[id].assign(arr[l]);
        return;
    }

    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    build(left, l, mid);
    build(right, mid, r);
    seg[id] = merge(seg[left], seg[right]);
}

//Complexity: O(log n)
void update(int p, int id = 1, int l = 0, int r = N){
    if(r - l < 2){ 
        //base case : leaf node information to be stored here
        seg[id].assign(-seg[id].sum);
        return;
    }

    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    if(p < mid){
        update(p, left, l, mid);
    }else{
        update(p, right, mid, r);
    }
    seg[id] = merge(seg[left], seg[right]);
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    T = 1;

    while(T <= 10){
        cin >> N;
        arr.resize(N);
        seg.resize(4 * N);
        string s;
        cin >> s;
        rep(i, N){
            arr[i] = (s[i] == '(' ? 1 : -1);
        }

        build();

        cout << "Test " << T++ << ":" << endl;
        int Q;
        cin >> Q;
        int p;
        rep(i, Q){
            cin >> p;
            if(p == 0){
                if(seg[1].sum == 0 && seg[1].minsum == 0){
                    cout << "YES" << endl;
                }else{
                    cout << "NO" << endl;
                }
            }else{
                p--;
                update(p);
            }
        }
    }

    return 0;
}
