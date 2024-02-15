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

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vii weights(n);
    rep(i, n){
        cin >> weights[i].f >> weights[i].s;
    }

    int ans = 0;
    sort(rall(weights));

    priority_queue<pair<int, int>> pq;

    rep(i, n){
        int w = weights[i].f;
        int c = weights[i].s;
        int used_cow = 0;
        /* cout << w << spc << c << endl; */
        if(!pq.empty()){
            int how_much = 0;
            while(c > 0){
                if(pq.empty() || w + k > pq.top().f)
                    break;
                int wh = pq.top().f;
                int ch = pq.top().s;
                pq.pop();
                int deduct = min(c, ch);
                ch -= deduct;
                c -= deduct;
                how_much += deduct;
                if(ch > 0)
                    pq.push(mp(wh, ch));
                /* cout << w << spc << c << spc << wh << spc << ch << spc << deduct << endl; */
            }
            used_cow += how_much;
            /* cout << "how_much : " << how_much << endl; */
        }
        if (m > 0){
            int deduct = min(m, c);
            m -= deduct;
            c -= deduct;
            /* cout << deduct << spc << m << spc << c << endl; */
            used_cow += deduct;
        }
        if(used_cow > 0){
            pq.push(mp(w, used_cow));
            ans += used_cow;
        }
    }

    cout << ans << endl;

}

signed main(){
    fastio;

    solve();

    return 0;
}
