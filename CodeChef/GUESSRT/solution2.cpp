#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

const lli MOD	= 1e9 + 7;
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

pair<lli, lli> fract_add(pair<lli, lli> a, pair<lli, lli> b){
    pair<lli, lli> ans;

    lli denom = a.second * b.second;
    lli num = (a.first * (b.second)) + (b.first * (a.second)) ;

    lli comm = gcd(denom, num);
    ans.first = (num / comm);
    ans.second = (denom / comm);
    return ans;
}

pair<lli, lli> fract_mult(pair<lli, lli> a, pair<lli, lli> b){
    pair<lli, lli> ans;

    lli denom = a.second * b.second;
    lli num = a.first * b.first;

    lli comm = gcd(denom, num);
    ans.first = (num / comm);
    ans.second = (denom / comm);

    return ans;
}

pair<lli, lli> get_prob(lli N, lli K, lli M){
    pair<lli, lli> ans;
    if(M == 0){
        ans.first = 1;
        ans.second = N + K;
    }else if(M == 1){
        ans.first = 1;
        ans.second = N ;
    }else{
        if(N == 1){
            ans.first = 1;
            ans.second = 1;
        }else{
            pair<lli, lli> one, two;
            one.first = 1;
            one.second = N;
            two.first = N - 1;
            two.second = N;
            ans = fract_add(one, fract_mult(two, get_prob(N, K, M - 2)));
        }
    }

    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        lli N, K, M;
        cin >> N >> K >> M;

        pair<lli, lli> ans;

        ans = get_prob(N, K, M);

        lli Q_inv = mod_inverse((ans.second % MOD), MOD);
        lli fin_ans = ((ans.first % MOD) * (Q_inv % MOD)) % MOD;

        // cout << ans.first << " " << ans.second << endl;
        cout << fin_ans << endl;
    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}

