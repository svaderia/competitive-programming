
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


void solve(){

    int n, q;
    cin >> n >> q;

    multiset<int> gaps;
    set<int> positions;

    auto &&add_pos = [&](int pos){
        auto nit = positions.upper_bound(pos);
        if(nit != positions.end()) gaps.insert((*nit - pos));
        if(nit != positions.begin()){
            auto pit = nit;
            pit--;
            gaps.insert((pos - *pit));
        }

        if(nit != positions.begin() && nit != positions.end()){
            auto pit = nit;
            pit--;
            gaps.erase(gaps.find(*nit - *pit));
        }
        positions.insert(pos);
    };

    auto &&remove_pos = [&](int pos){
        auto it = positions.find(pos);
        auto nit = it; nit++;
        auto pit = it;

        if(nit != positions.end()){
            gaps.erase(gaps.find(*nit - pos));
        }
        if(it != positions.begin()){
            pit--;
            gaps.erase(gaps.find(pos - *pit));
            if(nit != positions.end()){
                gaps.insert(*nit - *pit);
            }
        }
        positions.erase(pos);
    };

    auto &&query = [&]{
        if(sz(positions) <= 2) return 0LL;
        else{
            return *positions.rbegin() - *positions.begin() - *gaps.rbegin();
        }
    };

    rep(i, n){
        int x;
        cin >> x;
        add_pos(x);
    }

    cout << query() << endl;

    rep(i, q){
        int type, x;
        cin >> type >> x;
        if(!type)
            remove_pos(x);
        else
            add_pos(x);
        cout << query() << endl;

    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
