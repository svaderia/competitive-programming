#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
using namespace std;

typedef long long int lli;
#define int unsigned long long int
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
#define repD(i, a, n)  for(lli i = a; i >= (n); --i)
#define endl "\n"
#define error(x) cerr << #x << " = " << (x) << endl
#define errorp(p) cerr << #p << " = " << (p.first) << ", " << (p.second) << endl

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }


int binaryToDecimal(string n) 
{ 
    string num = n; 
    int dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
    int len = num.length(); 
    for (lli i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
  
    return dec_value; 
}

string decToBinary(int n) 
{   
    string s;
    // Size of an integer is assumed to be 32 bits 

    for (lli i = 63; i >= 0; i--) { 
        int k = n >> i; 
        if (k & 1) 
            s.push_back('1'); 
        else
            s.push_back('0');
    } 
    return s;
}

int power(int m){
    int ans = 1;
    rep(i, m){
        ans *= 2;
    }
    return ans;
}

void go_right(int &a, set<int> &st){
    a++;
    while(present(st, a)){
        a++;
    }
}
void go_left(int &a, set<int> &st){
    a--;
    while(present(st, a)){
        a--;
    }
}

signed main(){
    #ifdef DEBUG
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        int n, m;
        cin >> n >> m;
        string val;
        set<int> st;
        int ans = power(m - 1) - 1;
        rep(i, n){
            cin >> val;
            int v = binaryToDecimal(val);
            int ss = st.size();
            if(v == ans){
                if(ss % 2 == 0){
                    go_right(ans, st);
                }else{
                    go_left(ans, st);
                }
            }else if( v < ans){
                if(ss % 2 == 0){
                    go_right(ans, st);
                }
            }else{
                if(ss % 2 == 1){
                    go_left(ans, st);
                }
            }
            st.insert(v);
        }
        string a = decToBinary(ans);
        
        // cout << a << endl;
        repA(i, 64 - m, 63){
            cout << a[i];
        }
        cout << endl;
    }

    return 0;
}
