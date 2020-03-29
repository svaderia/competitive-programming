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

const lli MIN_INF = -1e18;

struct node{
    lli leftsum, rightsum, allsum, maxsum;

    void assign(lli val){
       leftsum = rightsum = allsum = maxsum = val;
    }
}typedef node;

void print(node e){
    // error(e.allsum)<<
    cerr << e.leftsum << " " << e.rightsum << " " << e.allsum << " " << e.maxsum << endl;
}

vector<node> seg;
int N;
vli arr;

//Complexity: O(1)
//Stores what info. segment[i..j] should store
node merge(node &left, node &right){
    node fin;
    fin.leftsum = max(left.leftsum, left.allsum + right.leftsum);
    fin.rightsum = max(right.rightsum, left.rightsum + right.allsum);
    fin.allsum = left.allsum + right.allsum;
    fin.maxsum = max({fin.leftsum, fin.rightsum, fin.allsum, left.maxsum, right.maxsum, left.rightsum + right.leftsum}); 
    return fin;
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
void update(int p, int y, int id = 1, int l = 0, int r = N){
    if(r - l < 2){ 
        //base case : leaf node information to be stored here
        seg[id].assign(y);
        return;
    }

    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    if(p < mid){
        update(p, y, left, l, mid);
    }else{
        update(p, y, right, mid, r);
    }
    seg[id] = merge(seg[left], seg[right]);
}

//Complexity: O(log n)
node query(int x, int y, int id = 1, int l = 0, int r = N){
    if(r <= x || y <= l){ // No overlap, return useless
        node temp;
        temp.assign(MIN_INF);
        temp.allsum = 0;
        return temp;
    }

    if(x <= l && r <= y){ // overlap
        return seg[id];
    }

    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    node a = query(x,  y, left, l, mid);
    node b = query(x, y, right, mid, r);
    return merge(a, b);
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        cin >> N;
        arr.resize(N);
        seg.resize(4 * N);
        rep(i, N){
            cin >> arr[i];
        }

        build();

        int M;
        cin >> M;
        int x1, y1, x2, y2;
        rep(i, M){
            cin >> x1 >> y1 >> x2 >> y2;
            x1--; y1--; x2--; y2--;
            lli ans;
            if(y1 < x2){
                node mid = query(y1 + 1, x2);
                // print(mid);
                node left = query(x1, y1 + 1);
                // print(left);
                node right = query(x2, y2 + 1);
                // print(right);
                ans = left.rightsum + mid.allsum + right.leftsum;
            }else{
                node mid = query(x2, y1 + 1);
                // print(mid);
                node left = query(x1, x2);
                // print(left);
                node right = query(y1 + 1, y2 + 1);
                // print(right);
                node left2 = merge(left, mid);
                node right2 = merge(mid, right);
                ans = max({mid.maxsum, left.rightsum + right2.leftsum, left2.rightsum + right.leftsum});
            }
            cout << ans << endl;
        }
    }
    return 0;
}
