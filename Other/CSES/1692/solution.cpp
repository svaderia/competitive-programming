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
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const lli INF   = 1e18;

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
struct edge{
    int to, w, id;
    edge(int ii, int ww, int idx) : to(ii), w(ww), id(idx) {}
};

struct Graph{
    int n, m;
    vector<vector<edge>> adj;

    Graph() : n(0), m(0), adj(0) {}
    Graph(int nn) : n(nn), m(0), adj(nn) {}

    void add(int u, int v, bool directed = false, int w = 0){
        adj[u].pb(edge(v, w, m));
        if(!directed)
            adj[v].pb(edge(u, w, m));
        m++;
    }
};

void solve(){

    int n;
    cin >> n;

    if(n == 1){
        cout << "01" << endl;
        return;
    }

    int MAXN = (1ll << (n - 1));

    int mask = MAXN - 1;

    stack<int> st;
    vi ans;
    st.push(0);
    vi used(MAXN);

    while(!st.empty()){
        int tp = st.top();

        if(used[tp] == 2){
            ans.pb(tp);
            st.pop();
        }else if(used[tp] == 1){
            int nextv = (tp << 1)  + 1;
            nextv = (nextv & mask);
            st.push(nextv);
            used[tp]++;
        }else if(used[tp] == 0){
            int nextv = (tp << 1);
            nextv = (nextv & mask);
            st.push(nextv);
            used[tp]++;
        }
    }

    reverse(all(ans));
    string fin;
    rep(i, n - 2){
        fin.pb('0');
    }

    int one = 1;
    for(auto x : ans){
        fin.pb((x & one) + '0');
    }

    cout << fin << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
