#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}



class DivisorInc{

    void get_divisors(int n, queue<pair<int, int> > *Q, int len, int M, int N, int* visited){
        int temp = int(ceil( sqrt(n)));
        for(int i = 2; i < temp; i++){
            if(n % i == 0){
                pair<int, int> t1, t2;
                t1.first = n + i;
                t1.second = len + 1;
                t2.first = n + n/i;
                t2.second = len + 1;
                if(t1.first <=  M && visited[t1.first - N] == 0){
                    (*Q).push(t1);
                    visited[t1.first - N] = 1;
                }
                if(t2.first <=  M && visited[t2.first - N] == 0){
                    (*Q).push(t2);
                    visited[t2.first - N] = 1;
                }
            }
        }
        if(temp * temp == n){
            pair<int, int> t;
            t.first = temp + n;
            t.second = len + 1;
            if(t.first <=  M && visited[t.first - N] == 0){
                (*Q).push(t);
                visited[t.first - N] = 1;
            }
        }
        
    }
    public:
    int countOperations(int N, int M){
        fastio;
    
    // int N, M;
    // cin >> N >> M;
    int visited[M-N + 1] ;
    for(int i = 0; i < M-N+1; i++){
        visited[i] = 0;
    }
    queue<pair<int, int> > Q;
    
    pair<int, int> f;
    f.first = N;
    f.second = 0;
    Q.push(f);
    int ans = -1;
    while(!Q.empty()){
        pair<int, int> p = Q.front();
        Q.pop();
        if( p.first == M){
            // cout << p.second << endl;
            ans = p.second;
            break;
        }else {
            get_divisors(p.first, &Q, p.second, M, N, visited);
        }
    }
    
    // cout << ans << endl;
    
    // cout<<"Execution time : "<<tick()<<"\n";
    return ans;
    }
};

int main(){
    DivisorInc d;

    cout << d.countOperations(8748, 83462) << endl;
    cout<<"Execution time : "<<tick()<<"\n";

}