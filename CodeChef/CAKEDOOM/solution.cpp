#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define fill(a)  memset(a, 0, sizeof (a))

double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }
template<typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}

const string no = "NO";

bool check_validity(string s, int K){
    K--;
    char k = K + '0';
    int n = s.length();
    rep(i, n){
        if(s[i] > k){
            return false;
        }
        if(i == 0){
            if(s[i] == s[n-1] ){
                return false;
            }
        }else{
            if(s[i] == s[i-1]){
                return false;
            }
        }
    }
    return true;
}

string fix(string s, int left, int mid, int right) {
    if(s[mid]!='?')
	return s;
    for(char cur='0'; cur <='2'; cur++)
	if(s[left]!=cur && s[right]!=cur) {
	    s[mid] = cur;
	    break;
	}
    return s;
}


string solve(string s, int K){
    int l = s.length();
    if(l == 1){
        if(s[0] == '?'){
            s[0] = '0';
        }
        return s;
    }
    if( K == 1){
        return no;
    }

    if( K == 2){
        if(l % 2 == 1){
            return no;
        }

        string temp = s;
        int fucked = 1;
        for(char c = '0'; c <= '1'; c++){
            if(s[0] == '?')
                s[0] = c;
            char curr = c;
            int i;
            for(i = 1; i < l; i++){
                if(s[i] == '?'){
                    s[i] = s[i-1] + (s[i - 1] == '0' ? 1 : -1);
                }
                if(s[i] == s[i - 1]){
                    break;
                }
            }

            if(i == l){
                return s;
            }
            s = temp;
        }
        return no;
    }

    for(int i=1;i<l;i++) {
        if(s[i]==s[i-1] && s[i]!='?')
            return no;
    }
    if(s[l-1]==s[0] && s[0]!='?')
	    return no;

    if(s[0] == '?')
        s = fix(s, l-1, 0, 1);
    repA(i, 1, l-2)
        s = fix(s, i-1, i, i+1);
    
    s = fix(s, 0, l-1, l-2);

    return s;


}
int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        int K;
        cin >> K;

        string s;
        cin >> s;

        cout << solve(s, K) << endl;
        

    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}