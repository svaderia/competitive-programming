// Test lli
// Test sort function for different strings


#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> 
// using namespace __gnu_pbds;
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet;

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

typedef struct node{
    string l;
    lli p;
}node;

const int MAXN = 50005;
node arr[MAXN];
int seg[4 * MAXN];
int N;


void init(){
    arr[N].p = -1;
}

bool compare(node a, node b){
    return a.l[0] < b.l[0];
}

//Complexity: O(1)
//Stores what info. segment[i..j] should store
int combine(int &a, int &b) {
    return arr[a].p < arr[b].p ? b : a;
}

//Complexity: O(n)
void build(int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        //base case : leaf node information to be stored here
        seg[id] = l;
        return;
    }

    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    build(left, l, mid);
    build(right, mid, r);
    seg[id] = combine(seg[left], seg[right]);
}


int query(int x, int y, int id = 1, int l = 0, int r = N){
    if(y <= l || r <= x){
        return N;
    }

    if(x <= l && r <= y){
        return seg[id];
    }

    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    int a = query(x, y, left, l, mid);
    int b = query(x, y, right, mid, r);
    return combine(a, b);
}


//Complexity: O(log n)
void trav(int l = 0, int r = N){
    if( r <= l){
        return;
    }

    int curr = query(l, r);
    cout << "(";    
    trav(l, curr);
    cout << arr[curr].l[0] << "/" << arr[curr].p;
    trav(curr + 1, r);
    cout << ")";
}


int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    cin >> N;
    while(N != 0){
        init();
        rep(i, N){
            string temp;
            cin >> temp;
            int shift = 0;
            vector<string> v(2);
            // cout << temp << endl;
            tr(temp, x){
                if(x == '/'){
                    shift = 1;
                }else{
                    v[shift].pb(x);
                }
            }
            arr[i].l = v[0];
            arr[i].p = stoi(v[1]);
            // error(arr[i].p);
        }
        sort(arr, arr + N, compare); // Made a mistake here
        
        build();
        trav(0, N);
        cout << endl;
        cin >> N;
    }

    return 0;
}
