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

int id[10005];
int enemy[10005];
int sz[10005];

int root(int p){
    if(p != -1){
        while(p != id[p]){
            id[p] = id[id[p]];
            p = id[p];
        }
    }
    return p;
}

void unite(int a, int b){
    int p1 = root(a);
    int p2 = root(b);
    if(p1 != p2){
        if(sz[p1] < sz[p2]){
            id[p1] = p2;
            sz[p2] += sz[p1];
        }else{
            id[p2] = p1;
            sz[p1] += sz[p2];
        }
    }
}

void init_dsu(int N){
    rep(i, N){
        id[i] = i;
        enemy[i] = -1;
        sz[i] = 1;
    }
}


void makeFriends(int x, int y){
    int px = root(x);
    int py = root(y);

    if(px == py)
        return;
    
    int ex = root(enemy[px]);
    int ey = root(enemy[py]);

    if(px == ey || py == ex){
        cout << -1 << endl; // enemies can't be friends;
        return;
    }

    unite(px, py);

    enemy[root(px)] = (ex == -1) ? ey : ex; // update the enemy

    if(ex != -1 && ey != -1){
        makeFriends(ex, ey);
    }
}


int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int N;
    cin >> N;

    init_dsu(N);

    int c, x, y;
    while(true){
        cin >> c >> x >> y;
        if(c == 0)
            break;
        // cerr << "c=" << c << ", x=" << x << ", y=" << y << endl;
        int px = root(x);
        int py = root(y);
        int ex = root(enemy[px]);
        int ey = root(enemy[py]);
        // cerr << "x=" << px << ", y=" << py << ", ex=" << ex << ", ey=" << ey << endl;
        if(px == py && ex != ey)
            break;
        if((px == ey) != (py == ex))
            break;

        switch(c){
            case 1:
                makeFriends(px, py);
                break;
            case 2:
                if(px == py || (ey != -1 && ex == ey)){
                    cout << -1 << endl; // friends can't be enemies
                    break;
                }

                enemy[px] = py;
                enemy[py] = px;
                
                if(ex != -1){
                    makeFriends(ex, py);
                }
                if(ey != -1){
                    makeFriends(ey, px);
                }
                break;
            case 3:
                cout << (px == py) << endl;
                break;
            case 4:
                cout << (px == ey) << endl;
                break;
        }
    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
