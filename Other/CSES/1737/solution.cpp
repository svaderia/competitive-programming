#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD   = 1e9 + 7;
const double PI = acos(-1.0);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
const int INF   = 1e18;

#define fastio            ios_base::sync_with_stdio(false);cin.tie(0)
#define sz(a) int((a).size())
#define rsz resize
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define f first
#define s second
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define endl "\n"
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

// Persistent Segment Tree

int N;

struct node{
    node *lt, *rt;
    int data;
    node(int val) : lt(NULL), rt(NULL), data(val) {}
    node(node *l, node *r, int val) : lt(l), rt(r), data(val) {}
}typedef node;

string to_string(node c) {
    return to_string(c.data);
}

int merge(int a, int b) {
    return a + b;
} // any associatinve function

node* build(vi &arr, int l = 0, int r = N - 1){
    if(l == r){
        return new node(arr[l]);
    }
    int mid = (l + r) / 2;
    node *llt = build(arr, l, mid);
    node *rrt = build(arr, mid + 1, r);
    return new node(llt, rrt, merge(llt -> data, rrt -> data));
}

int query(node *root, int l, int r, int a = 0, int b = N - 1){
    // outside
    if(!root) return 0;

    if(a > r || b < l){
        return 0;
    }

    if(l <= a && b <= r){
        return root -> data;
    }

    int mid = (a + b) / 2;
    int leftQuery = query(root -> lt, l, r, a, mid);
    int rightQuery = query(root -> rt, l, r, mid + 1, b);

    return  merge(leftQuery, rightQuery);
}

node* update(node *root, int p, int val, int a = 0, int b = N - 1){
    if(a == b){
        return new node(val);
    }

    int mid = (a + b) / 2;
    if(p <= mid){
        node* llt = update(root -> lt, p, val, a, mid);
        return new node(llt, root -> rt, merge(llt -> data, root -> rt -> data));
    }else{
        node* rrt = update(root -> rt, p, val, mid + 1, b);
        return new node(root -> lt, rrt, merge(root -> lt -> data, rrt -> data));
    }
}

void solve(){
    int n, q;
    cin >> n >> q;
    N = n;

    vector<node*> arrk;

    vi arr(n);
    rep(i, n){
        cin >> arr[i];
    }

    arrk.pb(build(arr));

    rep(i, q){
        int type;
        cin >> type;
        if(type == 1){
            int k, a, x;
            cin >> k >> a >> x;
            k--; a--;
            arrk[k] = update(arrk[k], a, x);
        }else if(type == 2){
            int k, a, b;
            cin >> k >> a >> b;
            k--, a--, b--;
            cout << query(arrk[k], a, b) << endl;
        }else{
            int k;
            cin >> k;
            k--;
            arrk.pb(arrk[k]);
        }

    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
