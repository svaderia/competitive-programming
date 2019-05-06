#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
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

        char arr[N];
        rep(i, N){
            cin >> arr[i];
        }
        int cnt1=0;
        int cnt2=0;
        rep(i, N){
            if(i%2==0){
                if(arr[i]=='1'){
                    cnt1++;
                }
                else{
                    cnt2++;
                }
            }
            else{
                if(arr[i]=='0'){
                    cnt1++;
                }
                else{
                    cnt2++;
                }
            }
        }
        //cout<<cnt1<<" "<<cnt2<<endl;
        if(K >= min(cnt1,cnt2)){
            cout<<1<<endl;
            continue;
        }

        priority_queue< pair<int, pair<int, int> > > pq;

        int curr = 0;
        int prev = arr[0];
        int id = 0;
        vi val;
        rep(i, N){
            if(prev == arr[i]){
                curr++;
            }else{
                val.pb(curr);
                pq.push(mp(curr, mp(100000, id++) ));
                curr = 1;
                prev = arr[i];
            }
        }
        val.pb(curr);
        pq.push(mp(curr, mp(100000, id++) ));
        
        rep(i, K){
            int mx = pq.top().first;
            if(mx != 2){
                int id = pq.top().second.second;
                int v = val[id];
                int d1 = pq.top().second.first;
                d1 --;
                int d = 100000 - d1;
                int m1 = v / (d+1);
                pq.pop();
                pq.push(mp(m1, mp(d1, id)));
            }else{
                break;
            }
            
        }

        cout << pq.top().first << endl;
    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
