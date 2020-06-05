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
#define endl "\n"
#define error(x) cerr << #x << " = " << (x) << endl
#define errorp(p) cerr << #p << " = " << (p.first) << ", " << (p.second) << endl

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }

const int mx = 50;
vi pref_sum(mx + 1);
int f(int n){
    return ((n + 1) * n) / 2;
}


bool is_prime(lli n){
    bool yeah = true;
    if( n <= 1){
        yeah = false;
    }else{
        lli temp = lli(ceil(sqrt(n)));
        for(lli i = 2; i < temp; i++){
            if(n % i == 0){
                yeah = false;
                break;
            }
        }
        if( temp * temp == n){
            yeah = false;
        }
    }

    return yeah;
}


int get_divisors(int n){
    int ans = 0;
    int temp = int(ceil( sqrt(n)));
    // error(temp);
    for(int i = 2; i < temp; i++){
        int tmp = 0;
        while(n % i == 0){
            n /= i;
            tmp++;
        }
        if(tmp > 0){
            int pos = upper_bound(all(pref_sum), tmp) - pref_sum.begin();
            pos--;
            ans += pos;
        }
    }
    if(is_prime(n)){
        ans++;
    }
    return ans;
}


void solve(){
    int N;
    cin >> N;
    pref_sum[0] = 0;
    repA(i, 1,  mx){
        pref_sum[i] = f(i);
        // cout << pref_sum[i] <<" ";
    }
    // cout << endl;
    if(N == 1){
        cout << 0 << endl;
    }else if(is_prime(N)){
        cout << 1 << endl;    
    }else{
        cout << get_divisors(N) << endl;
    }
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    solve();

    return 0;
}
