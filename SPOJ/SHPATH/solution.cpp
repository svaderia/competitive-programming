#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

struct chash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(pii x) const { return hash_f(x.f)^hash_f(x.s)^RANDOM; }
};

void solve(){

    int n;
    cin >> n;
    int idx = 1;
    vvi g(n + 1);

    unordered_map<string, int> city;
    gp_hash_table<pii, int, chash> dist; // Hash table, good alternative of unordered_map

    rep(i, n){
        string name;
        cin >> name;
        city[name] = idx;
        int p;
        cin >> p;
        rep(j, p){
            int x, c;
            cin >> x >> c;
            g[idx].pb(x);
            dist[mp(idx, x)] = c;
        }
        idx++;
    }

    int r;
    cin >> r;
    rep(i, r){
        string s1, s2;
        cin >> s1 >> s2;
        int source = city[s1], dest = city[s2];
        vb used(n + 1);
        vi fin(n + 1, INF);
        fin[source] = 0;
        priority_queue<pii> pq;
        pq.push(mp(0, source));
        int ans;

        while(!pq.empty()){
            int d = -pq.top().f, root = pq.top().s;
            pq.pop();
            if(root == dest){
                ans = d;
                break;
            }
            if(used[root]) continue;
            used[root] = true;
            for(auto child : g[root]){
                if(d + dist[mp(root, child)] < fin[child]){
                    fin[child] = d + dist[mp(root, child)];
                    pq.push(mp(-fin[child], child));
                }
            }
        }
        cout << ans << endl;
    }

}

signed main(){
    fastio;

    int T;
    cin >> T;

    repA(tc, 1, T){
        solve();
    }

    return 0;
}
