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
    // TO_STRING
    string to_string(char c) { return string(1,c); }
    string to_string(const char* s) { return (string)s; }
    string to_string(string s) { return s; }
    string to_string(bool b) {
        #ifdef DEBUG
            return b ? "true" : "false";
        #else
            return to_string((int)b);
        #endif
    }
    template<class A> string to_string(complex<A> c) {
        stringstream ss; ss << c; return ss.str(); }
    string to_string(vector<bool> v) {
        string res = "{"; rep(i,sz(v)) res += char('0'+v[i]);
        res += "}"; return res; }
    template<size_t SZ> string to_string(bitset<SZ> b) {
        string res = ""; rep(i,SZ) res += char('0'+b[i]);
        return res; }
    template<class A, class B> string to_string(pair<A,B> p);
    template<class T> string to_string(T v) { // containers with begin(), end()
        #ifdef DEBUG
            bool fst = 1; string res = "{";
            for (const auto& x: v) {
                if (!fst) res += ", ";
                fst = 0; res += to_string(x);
            }
            res += "}"; return res;
        #else
            bool fst = 1; string res = "";
            for (const auto& x: v) {
                if (!fst) res += " ";
                fst = 0; res += to_string(x);
            }
            return res;

        #endif
    }
    template<class A, class B> string to_string(pair<A,B> p) {
        #ifdef DEBUG
            return "("+to_string(p.f)+", "+to_string(p.s)+")";
        #else
            return to_string(p.f)+" "+to_string(p.s);
        #endif
    }

    // DEBUG
    void DBG() { cerr << "]" << endl; }
    template<class H, class... T> void DBG(H h, T... t) {
        cerr << to_string(h); if (sizeof...(t)) cerr << ", ";
        DBG(t...); }
#ifdef DEBUG // compile with -DDEBUG
    #define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
    #define dbg(...) 0
#endif

const int MAXN = 1e10;
//Segment tree operations: Point update and Range Query

struct node{
    lli data;

    void assign(lli val){
        data = val;
    }
}typedef node;

vector<node> seg;
int N = 2e5 + 2;
vli arr;

//Complexity: O(1)
//Stores what info. segment[i..j] should store
node merge(node &left, node &right){
    node id;
    id.data = min(left.data, right.data);
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
        node id;
        id.assign(MAXN);
        return id;
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

void solve(){
    int n, q;
    cin >> n >> q;
    vi rating(n);
    vi belong(n);

    vector<priority_queue<pii>> pq(N);
    seg.resize(4 * N);
    arr.resize(N, MAXN);
    rep(i, n){
        cin >> rating[i] >> belong[i];
        pq[belong[i]].push(mp(rating[i], i));
        arr[belong[i]] = pq[belong[i]].top().f;
    }
    build();

    rep(i, q){
        int which, where;
        cin >> which >> where;
        which--;
        int curr = belong[which];
        belong[which] = where;
        while(!pq[curr].empty() && belong[pq[curr].top().s] != curr) pq[curr].pop();
        pq[where].push(mp(rating[which], which));
        while(!pq[where].empty() && belong[pq[where].top().s] != where) pq[where].pop();
        dbg(curr, pq[curr].empty() ? MAXN : pq[curr].top().f);
        dbg(where, pq[where].empty() ? MAXN : pq[where].top().f);
        update(curr, pq[curr].empty() ? MAXN : pq[curr].top().f);
        update(where, pq[where].empty() ? MAXN : pq[where].top().f);
        cout << query(0, N).data << endl;
    }




}

signed main(){
    fastio;

    solve();

    return 0;
}

