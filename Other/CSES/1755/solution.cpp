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

const int MAXL = 26;

void solve(){

    string s;
    cin >> s;

    vi freq(MAXL);
    for(auto c : s){
        freq[c - 'A']++;
    }

    int temp = -1;
    if(sz(s) & 1){
        rep(i, MAXL){
            if(freq[i] % 2){
                freq[i]--;
                temp = i;
                break;
            }
        }
    }

    bool can = true;

    string fin;
    rep(i, MAXL){
        if(freq[i] % 2) can = false;
        else{
            rep(j, freq[i] / 2) fin.pb(char(i + 'A'));
        }
    }

    if(can){
        string ans = fin;
        if(sz(s) % 2) ans += char(temp + 'A');
        reverse(all(fin));
        ans += fin;

        cout << ans << endl;
    }else{
        cout << "NO SOLUTION" << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
