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

bool table[1000][1000];
bool rev_table[1000][1000];
int tab[1000][1000];
int rev_tab[1000][1000];

void fill_table(int N, string S){
    rep(i, N){
        table[i][i] = true;
    }

    rep(i, N - 1){
        if(S[i] == S[i+1]){
            table[i][i+1] = true;
        }
    }

    repA(k, 3, N){
        rep(i, N-k+1){
            int j = i + k - 1;
            if (table[i+1][j-1] && S[i] == S[j]) {
                table[i][j] = true; 
            }
        }
    }
}

void fill_rev_table(int N, string S){

    rep(i, N){
        rev_table[i][i] = true;
    }

    rep(i, N - 1){
        if(S[i] == S[i+1]){
            rev_table[i][i+1] = true;
        }
    }

    repA(k, 3, N){
        rep(i, N-k+1){
            int j = i + k - 1;
            if (rev_table[i+1][j-1] && S[i] == S[j]) {
                rev_table[i][j] = true; 
            }
        }
    }
}


int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    string S;
    cin >> S;

    string S2 = S;
    reverse(all(S2));

    int N = S.length();
    fill(table);
    fill(rev_table);
    fill(tab);
    fill(rev_tab);


    fill_table(N, S);
    fill_rev_table(N, S2);


    rep(i, N){
        int curr = 0;
        repA(j, i, N-1){
            if(table[i][j] == 1) curr++;
            tab[i][j] = curr;
        }
    }

    rep(i, N){
        int curr = 0;
        repA(j, i, N-1){
            if(rev_table[i][j] == 1) curr++;
            rev_tab[i][j] = curr;
        }
    }
    

    // rep(i, N){
    //     rep(j, N){
    //         cout << tab[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << S << endl;

    // cout << S2 << endl;
    lli ans = 0;

    rep(i, N){
        rep(j, N-1-i){
            if(S[i] == S2[j]){
                cout << i << " " << N - 1 - j << " "; 
                int k1 = i, k2 = j;
                int temp = 0;
                while(S[k1] == S2[k2] && k1 < N && k2 < N-1-i && k1 < N-1-k2){
                    // cout << k1 << "   " << k2 << endl;
                    temp += tab[k1+1][N-1-k2-1]+1;
                    temp += rev_tab[k2+1][N-1-k1-1];
                    k1++; k2++;
                }
                cout << temp << endl;
                ans+=temp;
            }
        }
    }

    cout << ans << endl;

    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}
