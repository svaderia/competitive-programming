#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
using namespace std;

typedef long long int lli;
#define int lli
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet;

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
#define endl "\n"
#define error(x) cerr << #x << " = " << (x) << endl
#define errorp(p) cerr << #p << " = " << (p.first) << ", " << (p.second) << endl

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

const int MAXN = 2 * 1e5 * 32 + 20;

int triee[MAXN][2];
int suf_count[MAXN];
int last_used = 1;

void insert(int num){
    int next = 0;
    repD(bit, 31, 0){
        int ch = (num & (1 << bit)) > 0;
        if(triee[next][ch] == 0){
            triee[next][ch] = last_used++;
        }
        next = triee[next][ch];
        suf_count[next]++;
    }
}

void del(int num){
    int next = 0;
    repD(bit, 31, 0){
        int ch = (num & (1 << bit)) > 0;
        next = triee[next][ch];
        suf_count[next]--;
    }
}

int find(int num){
    int max_xor = 0;
    int next = 0;
    repD(bit, 31, 0){
        int ch = (num & (1 << bit)) > 0;
        int expected_ch = 1 - ch;
        if(triee[next][expected_ch] != 0 && suf_count[triee[next][expected_ch]] > 0){
            ch = expected_ch;
        }
        next = triee[next][ch];
        max_xor |= (ch << bit);
    }
    return max_xor;
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int q;
    cin >> q;
    insert(0LL);
    rep(i, q){
        char ch;
        int num;
        cin >> ch >> num;
        if(ch == '+'){
            insert(num);
        }else if(ch == '-'){
            del(num);
        }else{
            cout << (num ^ find(num)) << endl;
        }
    }

    return 0;
}
