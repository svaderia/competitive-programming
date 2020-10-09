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

const int block_size = 700;
struct Query{
    int l, r, id;

    Query() {}
    Query(int ll, int rr, int idd) : l(ll), r(rr), id(idd) {}

    pii toPair(){
        return mp(l / block_size, ((l / block_size) & 1) ? -r : r);
    }

    bool operator<(Query &other){
        return this->toPair() < other.toPair();
    }

};

void solve(){

    int n, q;
    cin >> n >> q;

    vi c(n);
    rep(i, n){
        cin >> c[i];
        c[i]--;
    }

    vector<Query> qu;

    rep(i, q){
        int l, r;
        cin >> l >> r;
        l--, r--;
        qu.pb(Query(l, r, i));
    }

    vi ans(q);

    sort(all(qu));

    int curr_l = 0, curr_r = -1;

    vi colors(n);
    int active = 0;

    for(auto qs : qu){
        while(curr_r < qs.r){
            curr_r++;
            int cc = c[curr_r];
            if(colors[cc] == 0) active++;
            colors[cc]++;
        }
        while(curr_l > qs.l){
            curr_l--;
            int cc = c[curr_l];
            if(colors[cc] == 0) active++;
            colors[cc]++;
        }
        while(curr_r > qs.r){
            int cc = c[curr_r];
            colors[cc]--;
            if(colors[cc] == 0) active--;
            curr_r--;
        }
        while(curr_l < qs.l){
            int cc = c[curr_l];
            colors[cc]--;
            if(colors[cc] == 0) active--;
            curr_l++;
        }

        ans[qs.id] = active;

    }

    rep(i, q){
        cout << ans[i] << endl;
    }


}

signed main(){
    fastio;

    solve();

    return 0;
}
