#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vli;
typedef vector<pii> vii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> OrderedSet;

const int MOD	= 1e9 + 7;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(auto &i : c)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define fill(a)  memset(a, 0, sizeof (a))
#define error(x) cerr << #x << " = " << (x) <<endl

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }
int mul(int a, int b, int c){lli res=(lli)a*b;return (int)(res>=c?res%c:res);}
template<typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}
template <class T>  inline void smax(T &x,T y){ x = max((x), (y));}
template <class T>  inline void smin(T &x,T y){ x = min((x), (y));}


const int MAXN = 1000005;
int id[MAXN];
int sz[MAXN];
bool visited[MAXN];
bool dn[MAXN];
bool rg[MAXN];
int N, M;
int maxSize;

int root(int p){
    while(p != id[p]){
        id[p] = id[id[p]];
        p = id[p];
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
            smax(maxSize, sz[p2]);
        }else{
            id[p2] = p1;
            sz[p1] += sz[p2];
            smax(maxSize, sz[p1]);
        }
    }
}

void my_unite(int p, int b){
    id[b] = p;
    sz[p]++;
}

void init_dsu(int n){
    rep(i, n){
        id[i] = i;
        sz[i] = 1;
    }
}

int get_node(int i, int j){
    return i * M + j;
}

void get_childs(int node, vi &childs){
    if(node > M){
        if(!dn[node-M]){
            childs.pb(node - M);
        }
    }
    if(node < (N-1)*M){
        if(!dn[node]){
            childs.pb(node + M);
        }
    }
    int a = node % M;
    if(a > 0){
        if(!rg[node-1]){
            childs.pb(node-1);
        }
    }
    if(a < M - 1){
        if(!rg[node]){
            childs.pb(node+1);
        }
    }
}

void mark_bfs(int node){
    queue<int> q;
    visited[node] = true;
    q.push(node);
    vi childs;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        childs.clear();
        get_childs(n, childs);
        assert(childs.size() <= 4);
        tr(childs, i){
            if(visited[i] != true){
                q.push(i);
                visited[i] = true;
                my_unite(node, i);
            }
        }
    }
    smax(maxSize, sz[node]);
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        int Q;
        cin >> N >> M >> Q;
        maxSize = 1;
        
        vector<pair<int, pii> > queries;
        memset(dn, 0, N*M*sizeof(bool));
        memset(rg, 0, N*M*sizeof(bool));
        rep(i, Q){
            int action;
            cin >> action;

            if(action == 1){
                int x, y;
                cin >> x >> y;
                x--; y--;
                int n = get_node(x, y);
                pii p = mp(action, n);
                if(!rg[n]){
                    queries.eb(mp(0, p));
                    rg[n] = true;
                }
            }else if(action == 2){
                int x, y;
                cin >> x >> y;
                x--; y--;
                int n = get_node(x, y);
                pii p = mp(action, n);
                if(!dn[n]){
                    queries.eb(mp(0, p));
                    dn[n] = true;
                }
            }else if(action == 3){
                int x1, x2, y1, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                x1--; y1--; x2--; y2--;
                queries.eb(mp(3, mp(get_node(x1, y1), get_node(x2, y2))));
            }else{
                queries.eb(mp(4, mp(0,0)));
            }
        }

        init_dsu(N * M);
        memset(visited, 0, N*M*sizeof(bool));
        rep(i, N*M){
            if(!visited[i]){
                mark_bfs(i);
            }
        }

        // rep(i, N*M){
        //     error(id[i]);
        // }

        Q = (int)queries.size();
        int n1, n2, p1, p2;
        lli ans = 0;

        repD(i, Q-1, 0){
            auto p = queries[i];
            switch (p.first){
                case 0:
                    if(p.second.first == 1){
                        int node = p.second.second;
                        unite(node, node+1);
                    }else{
                        int node = p.second.second;
                        unite(node, node+M);
                    }
                    break;
                case 3:
                    n1 = p.second.first;
                    n2 = p.second.second;
                    p1 = root(n1);
                    p2 = root(n2);
                    ans += (p1==p2);
                    // cout << (p1==p2) << endl;
                    break;
                case 4:
                    ans += maxSize;
                    // cout << maxSize << endl;
                    break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
