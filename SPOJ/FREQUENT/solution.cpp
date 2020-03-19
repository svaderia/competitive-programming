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


const int MAXN = 100005;
int arr[MAXN];
int seg_sum[4 * MAXN];
int seg_max[4 * MAXN];
int N;

//Complexity: O(1)
//Stores what info. segment[i..j] should store
int combine(int* seg, int &a, int &b) {
    if(seg == seg_sum)
        return a + b;
    else
        return max(a, b);
}

//Complexity: O(n)
void build(int* seg, int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        //base case : leaf node information to be stored here
        seg[id] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    build(seg, left, l, mid);
    build(seg, right, mid, r);
    seg[id] = combine(seg, seg[left], seg[right]);
}

//Complexity: O(log n)
void update(int* seg, int p, int y, int id = 1, int l = 0, int r = N){
    if(r - l < 2){ 
        //base case : leaf node information to be stored here
        seg[id] = y;
        return;
    }

    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    if(p < mid){
        update(seg, p, y, left, l, mid);
    }else{
        update(seg, p, y, right, mid, r);
    }
    seg[id] = combine(seg, seg[left], seg[right]);
}

//Complexity: O(log n)
int query(int* seg, int x, int y, int id = 1, int l = 0, int r = N){
    if(r <= x || y <= l){ // No overlap, return useless
        if(seg == seg_max)
            return INT_MIN;
        else
            return 0;
    }

    if(x <= l && r <= y){ // overlap
        return seg[id];
    }

    int mid = (l + r) / 2;
    int left = 2 * id, right = left + 1;
    int a = query(seg, x,  y, left, l, mid);
    int b = query(seg, x, y, right, mid, r);
    return combine(seg, a, b);
}

// seg_sum only
int kth(int* seg, int p, int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        return l;
    }

    int mid = (l + r)/2;
    int left = 2 * id, right = left + 1;
    if(seg[left] >= p){
        return kth(seg, p, left, l, mid);
    }else{
        return kth(seg, p - seg[left], right, mid, r);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    while(cin >> T){ 
        if(T == 0) break;
        int Q;
        cin >> Q;

        int curr;
        int prev;
        cin >> prev;
        fill(arr);
        arr[0]++;
        N = 0;
        rep(i, T - 1){
            cin >> curr;
            if(curr != prev){
                N++;
                prev = curr;
            }
            arr[N]++;
        }
        N++;


        build(seg_sum);
        build(seg_max);

        // error(seg_max[1]);
        // error(seg_sum[1]);

        rep(i, Q){
            int l, r;
            cin >> l >> r;
            int indx_left = kth(seg_sum, l);
            int indx_right = kth(seg_sum, r);
            if(indx_left != indx_right){
                int sm_left = query(seg_sum, 0, indx_left + 1);
                int sm_right = query(seg_sum, 0, indx_right);
                // error(indx_left); error(indx_right); error(sm_left); error(sm_right);

                int cache_left = arr[indx_left];
                int cache_right = arr[indx_right];
                update(seg_max, indx_left, sm_left - l + 1);
                update(seg_max, indx_right, r - sm_right);
                cout << query(seg_max, indx_left, indx_right + 1) << endl;
                update(seg_max, indx_left, cache_left);
                update(seg_max, indx_right, cache_right);
            }else{
                cout << r - l + 1 << endl;
            }
        }
        
    }
    return 0;
}
