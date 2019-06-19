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
#define error(x) cerr << #x << " = " << (x) <<endl

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

//Segment tree operations: Point update and Range Query

const int MAXN = 200005;
int arr[MAXN];
int seg[4*MAXN];
int N;

//Complexity: O(1)
//Stores what info. segment[i..j] should store
int combine(int &a, int &b) {
    return a + b;
}

//Complexity: O(n)
void build(){
    memset(seg, 0, sizeof(int) * 4 * (N+1));
    memset(arr, 0, sizeof(int)*(N+1));
}

//Complexity: O(log n)
void update(int p, int y, int id = 1, int l = 0, int r = N){
    if(r - l < 2){ 
        //base case : leaf node information to be stored here
        seg[id] = y;
        arr[l] = y;
        // error(l);
        return;
    }

    int mid = (l+r)/2;
    int left = 2*id, right = left + 1;
    if(p < mid){
        update(p, y, left, l, mid);
    }else{
        update(p, y, right, mid, r);
    }
    seg[id] = combine(seg[left], seg[right]);
}

//Complexity: O(log n)
int query(int x, int y, int id = 1, int l = 0, int r = N){
    if(r <= x || y <= l){ // No overlap, return useless
        return 0;
    }

    if(x <= l && r <= y){ // overlap
        return seg[id];
    }

    int mid = (l+r)/2;
    int left = 2*id, right = left + 1;
    int a = query(x,  y, left, l, mid);
    int b = query(x, y, right, mid, r);
    return combine(a, b);
}

int right_bound(int val, int id = 1, int l = 0, int r = N){
    if(r - l < 2){
        return l;
    }

    int mid = (l + r) / 2;
    int left = 2*id, right = left + 1;

    if(val <= seg[left]){
        return right_bound(val, left, l, mid);
    }else{
        return right_bound(val - seg[left], right, mid, r);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int Q;
    cin >> Q;

    set<int> vals;
    vector<pair<char, int> > qs;
    rep(i, Q){
        char ac;
        int val;
        cin >> ac >> val;
        if(ac != 'K'){
            vals.insert(val);
        }
        qs.eb(mp(ac, val));
    }

    N = sz(vals);
    unordered_map<int, int> my;
    vi rev_my;
    int c = 0;
    tr(vals, it){
        my[it] = c++;
        rev_my.pb(it);
    }

    build();
    
    tr(qs, p){
        char ac = p.first;
        int val = p.second;

        if(ac == 'I'){
            if(arr[my[val]] != 1){
                update(my[val], 1);
            }
        }else if(ac == 'D'){
            if(arr[my[val]] != 0){
                update(my[val], 0);
            }
        }else if(ac == 'C'){
            cout << query(0, my[val]) << endl;
        }else{
            if(val > seg[1]){
                cout << "invalid" << endl;
            }else{
                cout << rev_my[right_bound(val)] << endl;
            }
        }
    }
    


    return 0;
}
