//https://codeforces.com/contest/1363/problem/D
#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define error(x) cerr << #x << " = " << (x) << endl
#define errorp(p) cerr << #p << " = " << (p.first) << ", " << (p.second) << endl

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

int query(vi &s){
    int c = sz(s);
    cout << "? ";
    cout << c << " ";
    rep(i, c){
        cout << s[i] << " ";
    }
    cout << endl;
    int mx;
    cin >> mx;
    return mx;
}

int numquery(int l, int r){
    vi q;
    repA(i, l, r){
        q.pb(i);
    }
    return query(q);
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<vi> s(k);

    rep(i, k){
        int c;
        cin >> c;
        s[i].resize(c);
        rep(j, c){
            cin >> s[i][j];
        }
    }
    vi q;
    rep(i, n){
        q.pb(i + 1);
    }
    int mx = query(q);
    int l = 1, r = n + 1;
    while(r - l > 1){
        int mid = l + (r - l) / 2;
        if(numquery(l, mid - 1) == mx){
            r = mid;
        }else{
            l = mid;
        }
    }

    vi ans(k);
    rep(i, k){
        bool pos = true;
        for(auto x : s[i]){
            if(x == l){
                pos = false;
            }
        }
        if(pos){
            ans[i] = mx;
        }else{
            vi qq;
            set<int> ss(all(s[i]));
            repA(z, 1, n){
                if(!present(ss, z)){
                    qq.pb(z);
                }
            }
            ans[i] = query(qq);
        }
    }

    cout << "! ";
    rep(i, k){
        cout << ans[i] << " ";
    }
    cout << endl;
    string aa;
    cin >> aa;
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        solve();
    }

    return 0;
}
