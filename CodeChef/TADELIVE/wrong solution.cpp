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
    
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<pii> A;
    vector<pii> B;

    int temp;
    rep(i, N){
        cin >> temp;
        A.push_back(mp(temp, i));
    }
    rep(i, N){
        cin >> temp;
        B.pb(mp(temp, i));
    }

    sort(all(A), greater<pii>());
    sort(all(B), greater<pii>());

    
    int visited[N];
    fill(visited);
    int count = 0;
    int x = 0, y = 0;
    lli ans = 0;
    int x1 = 0, y1 = 0;

    // cout << X << "   " << Y << endl;
    while(count < N && x1 < X && y1 < Y){
        if(A[x].first > B[y].first){
            int order_no = A[x].second;
            if(visited[order_no] != 1){
                visited[order_no] = 1;
                count++;
                // cout << "A " << order_no << endl;
                ans += A[x].first;
                x1++;
            }
            x++;
            
        }else if ( A[x].first < B[y].first){
            int order_no = B[y].second;
            if(visited[order_no] != 1){
                visited[order_no] = 1;
                count++;
                // cout << "B " << order_no << endl;
                ans += B[y].first;
                y1++;
            }
            y++;
        }
        else{
            int winner = -1;
            int t1 = x, t2 = y;
            while(A[t1].first == B[t2].first && visited[A[t1].second] == visited[B[t2].second]){
                t1++; t2++;
            }

            if(A[t1] > B[t2]){
                int order_no = B[y].second;
                if(visited[order_no] != 1){
                    visited[order_no] = 1;
                    count++;
                    // cout << "B " << order_no << endl;
                    ans += B[y].first;
                    y1++;
                }
                y++;
            }else if (A[t1] < B[t2]){
                int order_no = A[x].second;
                if(visited[order_no] != 1){
                    visited[order_no] = 1;
                    count++;
                    // cout << "A " << order_no << " t1 " << t1 << endl;
                    ans += A[x].first;
                    x1++;
                }
                x++;
            }else{
                if(visited[A[t1].second] == 0){
                    int order_no = B[y].second;
                    if(visited[order_no] != 1){
                        visited[order_no] = 1;
                        count++;
                        // cout << "B " << order_no << endl;
                        ans += B[y].first;
                        y1++;
                    }
                    y++;
                }else{
                    int order_no = A[x].second;
                    if(visited[order_no] != 1){
                        visited[order_no] = 1;
                        count++;
                        // cout << "A " << order_no << " t1 " << t1 << endl;
                        ans += A[x].first;
                        x1++;
                    }
                    x++;
                }
            }
            
        }
    }

    if(count != N){
        if(x1 == X){
            while(count < N){
                int order_no = B[y].second;
                if(visited[order_no] != 1){
                    visited[order_no] = 1;
                    count++;
                    // cout << "B1 " << order_no << endl;
                    ans += B[y].first;
                }
                y++;
            }
        }else if( y1 == Y){
            while(count < N){
                int order_no = A[x].second;
                if(visited[order_no] != 1){
                    visited[order_no] = 1;
                    count++;
                    // cout << "A1 " << order_no << endl;
                    ans += A[x].first;
                }
                x++;
            }
        }
    }

    cout << ans << endl;

    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}