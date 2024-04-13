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
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
// Remove this when it's an interactive problem
#define endl "\n"
#define spc " "
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

/*
 * implementation of this :
 * https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
 */
string next_p(int n, string s){
    int pivot = -1;
    repD(i, n - 2, 0){
        if(s[i] < s[i + 1]){
            pivot = i;
            break;
        }
    }
    if(pivot == -1){
        reverse(all(s));
        return s;
    }

    int sw = -1;
    repD(i, n - 1, pivot){
        if(s[i] > s[pivot]){
            sw = i;
            break;
        }
    }

    swap(s[pivot], s[sw]);
    reverse(s.begin() + pivot + 1, s.end());
    return s;
}


void solve(){
    string s;
    cin >> s;

    sort(all(s));
    vector<string> ans;
    ans.pb(s);
    int n = sz(s);


    string next = next_p(n, s);
    /* cout << next << endl; */
    while(s != next){
        ans.pb(next);
        next = next_p(n, next);
    }

    cout << sz(ans) << endl;

    for(auto x : ans){
        cout << x << endl;
    }

}

signed main(){
    fastio;

    solve();

    return 0;
}
