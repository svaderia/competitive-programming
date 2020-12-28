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

// 2D Segment Tree

const int SIZE = 1e3 + 5;
int seg[4 * SIZE][4 * SIZE];
int arr[SIZE][SIZE];
int N;

int merge(int a, int b){
    return a + b;
}
void build_y(int idx, int x1, int x2, int idy = 1, int a = 0, int b = N - 1){
    if(a == b){
        if(x1 == x2){
            seg[idx][idy] = arr[x1][a];
        }else{
            seg[idx][idy] = merge(seg[2 * idx][idy],  seg[2 * idx + 1][idy]);
        }
        return;
    }
    int mid = (a + b) / 2;
    build_y(idx, x1, x2, 2 * idy, a, mid);
    build_y(idx, x1, x2, 2 * idy + 1, mid + 1, b);
    seg[idx][idy] = merge(seg[idx][2 * idy], seg[idx][2 * idy + 1]);
}

void build(int idx = 1, int a = 0, int b = N - 1){
    if(a != b){
        int mid = (a + b) / 2;
        build(2 * idx, a, mid);
        build(2 * idx + 1, mid + 1, b);
    }
    build_y(idx, a, b);
}

int query_y(int idx, int x1, int x2, int y1, int y2, int idy = 1, int a = 0, int b = N - 1){

    if(a > y2 || b < y1){
        return 0;
    }

    if(y1 <= a && b <= y2){
        return seg[idx][idy];
    }

    int mid = (a + b) / 2;
    int lq = query_y(idx, x1, x2, y1, y2, 2 * idy, a, mid);
    int rq = query_y(idx, x1, x2, y1, y2, 2 * idy + 1, mid + 1, b);
    return merge(lq, rq);
}

int query(int x1, int x2, int y1, int y2, int idx = 1, int a = 0, int b = N - 1){

    if(a > x2 || b < x1){
        return 0;
    }

    if(x1 <= a && b <= x2){
        return query_y(idx, x1, x2, y1, y2);
    }

    int mid = (a + b) / 2;
    int lq = query(x1, x2, y1, y2, 2 * idx, a, mid);
    int rq = query(x1, x2, y1, y2, 2 * idx + 1, mid + 1, b);
    return merge(lq, rq);
}

void update_y(int idx, int x1, int x2, int y, int idy = 1, int a = 0, int b = N - 1){
    if(a == b){
        if(x1 == x2){
            arr[x1][a] = 1 - arr[x1][a];
            seg[idx][idy] = arr[x1][a];
        } else{
            seg[idx][idy] = merge(seg[2 * idx][idy],  seg[2 * idx + 1][idy]);
        }
        return;
    }

    int mid = (a + b) / 2;
    if(y <= mid) update_y(idx, x1, x2, y, 2 * idy, a, mid);
    else update_y(idx, x1, x2, y, 2 * idy + 1, mid + 1, b);
    seg[idx][idy] = merge(seg[idx][2 * idy], seg[idx][2 * idy + 1]);
}

void update(int x, int y, int idx = 1, int a = 0, int b = N - 1){
    if(a != b){
        int mid = (a + b) / 2;
        if(x <= mid) update(x, y, 2 * idx, a, mid);
        else update(x, y, 2 * idx + 1, mid + 1, b);
    }
    update_y(idx, a, b, y);
}

void solve(){
    int n, q;
    cin >> n >> q;
    N = n;

    vector<string> trees(n);
    rep(i, n){
        cin >> trees[i];
    }

    rep(i, n){
        rep(j, n){
            arr[i][j] = (trees[i][j] == '*');
        }
    }

    build();

    rep(i, q){
        int type;
        cin >> type;
        if(type == 1){
            int x, y;
            cin >> x >> y;
            x--; y--;
            update(x, y);
        }else{
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--, x2--, y2--;
            cout << query(x1, x2, y1, y2) << endl;
        }
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
