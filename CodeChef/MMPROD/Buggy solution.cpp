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



int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        int N, K;
        cin >> N >> K;

        vector< lli > pos;
        vector< lli > neg;
        vector<lli > zero;
        lli temp;
        rep(i, N){
            cin >> temp;
            if(temp > 0 ){
                pos.push_back(temp);
            }else if(temp == 0){
                zero.push_back(temp);
            }else{
                neg.push_back(temp);
            }
        }

        sort(all(pos), greater<lli>());
        sort(all(neg));
        // tr(neg, it){
        //     cout << *it << " ";
        // }
        // cout << endl;
        lli ans = 1;
        int p = 0, n = 0, z = 0;
        if(K & 1){
            if(sz(pos) == 0){
                if(sz(zero) == 0){
                    for(typeof((neg).rbegin()) i = (neg).rbegin(); i != (neg).rend(); i++){
                        ans = (ans * (*i) );
                        ans = ((ans % MOD) + MOD ) % MOD;
                        K--;
                        if(K == 0)
                            break;
                    }
                    ans = ((ans % MOD) + MOD ) % MOD;
                    cout << ans << endl;
                    break;
                }else{
                    ans = 0;
                    cout << ans  << endl;
                    break;
                }
            }else{
                ans = pos[0];
                p = 1;
                K--;
            }
        }

        while(K > 0){
            lli tp = -1;
            lli tn = -1;

            if(p + 1 < sz(pos)){
                tp = pos[p] * pos[p+1];
                // cout << "tp " << tp << endl;
            }
            if(n + 1 < sz(neg)){
                tn = neg[n] * neg[n+1];
            }

            if(tp != -1 && tn != -1){
                if(tp > tn){
                    ans = (ans * tp) % MOD;
                    p += 2;
                }else{
                    ans = (ans * tn) % MOD;
                    n += 2;
                }
                K -= 2;
            }else{
                if(tp == -1 && tn == -1){
                    if(sz(zero) != 0){
                        ans = 0;
                        K = 0;
                    }else{
                        while(p < sz(pos)){
                            ans = (ans * pos[p]) % MOD;
                            p++;
                            K--;
                        }
                        while(n < sz(neg)){
                            ans = ((ans * neg[n]) % MOD ) ;
                            n++;
                            K--;
                        }
                    }
                }else{
                    if(tp == -1){
                        ans = (ans * tn) % MOD;
                        n += 2;
                    }else{
                        ans = (ans * tp) % MOD;
                        p += 2;
                    }
                    K -= 2;
                }
            }
        }

        cout << (((ans % MOD) + MOD ) % MOD) << endl;

    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}