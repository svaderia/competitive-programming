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
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    rep(i, n){
        cin >> s[i];
    }

    pii st, end;

    vvi arr(n, vi(m));
    rep(i, n){
        rep(j, m){
            arr[i][j] = (s[i][j] != '#');
            if(s[i][j] == 'A') st = mp(i, j);
            if(s[i][j] == 'B') end = mp(i, j);
        }
    }

    queue<pair<pii, int> > q;
    q.push(mp(st, 0ll));

    auto inside = [&] (int x, int y){
        return (x >= 0 && x < n && y >= 0 && y < m && arr[x][y]);
    };

    vvi visited(n, vi(m, -1));
    visited[st.f][st.s] = 1;

    int ans = -1;
    while(!q.empty()){
        int x = q.front().f.f, y = q.front().f.s, d = q.front().s;
        q.pop();
        if(mp(x, y) == end){
            ans = d; break;
        }
        rep(i, 4){
            int nx = x + dx[i], ny = y + dy[i];
            if(inside(nx, ny) && (visited[nx][ny] == -1)){
                visited[nx][ny] = i;
                q.push(mp(mp(nx, ny), d + 1));
            }
        }
    }

    map<int, char> mymap = {{0, 'D'}, {1, 'R'}, {2, 'U'}, {3, 'L'}};
    if(ans != -1){
        string steps;
        pii temp = end;
        while(temp != st){
            int dir = visited[temp.f][temp.s];
            steps.pb(mymap[dir]);
            int nx = temp.f - dx[dir], ny = temp.s - dy[dir];
            temp = mp(nx, ny);
        }
        reverse(all(steps));
        cout << "YES" << endl << ans << endl << steps << endl;

    }else{
        cout << "NO" << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
