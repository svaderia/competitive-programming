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


int get_weight(char c){
    int weight = 0;

    switch (c)
    {
        case 'C':
            weight = 12;
            break;

        case 'O':
            weight = 16;
            break;

        case 'H':
            weight = 1;
            break;

        default:
            weight = 0;
            break;
    }

    return weight;
}

int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    string formula ;
    cin >> formula;

    int len = formula.length();
    stack<int> s;
    s.push(0);

    int i = 0;
    while(i < len){
        if(formula[i] == '('){
            s.push(0);
        }else if(formula[i] == ')'){
            int top = s.top();
            s.pop();
            if(formula[i+1] > '1' && formula[i+1] <= '9'){
                top = top * (formula[i+1] - '0');
                i++;
            }
            int mass = s.top();
            s.pop();
            s.push(mass + top);
        }else if(formula[i] > '1' && formula[i] <= '9'){
            int top = s.top();
            s.pop();
            int weight = get_weight(formula[i-1]);
            top = top + weight * (formula[i] - '0' - 1);
            s.push(top);
        }else{
            int w = get_weight(formula[i]);
            int mass = s.top();
            s.pop();
            s.push(mass + w);
        }
        i++;
    }

    cout << s.top() << endl;
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}