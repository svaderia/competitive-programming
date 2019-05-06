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

class PrimeAnagrams{
    bool is_prime(int n){
        bool yeah = true;
        if( n <= 1){
            yeah = false;
        }else{
            int temp = int(ceil(sqrt(n)));
            for(int i = 2; i < temp; i++){
                if(n % i == 0){
                    yeah = false;
                    break;
                }
            }
            if( temp * temp == n){
                yeah = false;
            }
        }

        return yeah;
    }

    int get_int(string s, int start, int end){
        int sum = s[start] - '0';
        if(sum == 0){
            return -1;
        }
        for(int i = start+1; i < end; i++){
            sum *= 10;
            sum += (s[i] - '0');
        }

        return sum;
    }

    public:
     vector <int> primes(string s){
        int N = s.length();

        vector<int> ans(3);
        int min_mult = 1e8;
        sort(all(s));
        while(true){
            int x, y, z;
            int temp[3];
            int min_temp;
            for(int i = 1; i <= N/3; i++){
                x = i;
                y = i;
                z = N - 2*i;
                while(y <= z){
                    temp[0] = get_int(s, 0, x);
                    temp[1] = get_int(s, x, x+y);
                    temp[2] = get_int(s, x+y, x+y+z);
                    
                    // cout << temp[0] << " " << temp[1] << " " << temp[2] << endl;
                    // cout << x << " " << y << " " << z << endl;
                    // cout << endl;
                    if(is_prime(temp[0]) && is_prime(temp[1]) && is_prime(temp[2])){
                        min_temp = temp[0] * temp[1] * temp[2];
                        if(min_temp < min_mult){
                            min_mult = min_temp;
                            ans[0] = temp[0];
                            ans[1] = temp[1];
                            ans[2] = temp[2];
                        }
                    }
                    y++; z--;
                }

            }

            bool has_more = next_permutation(all(s));
            if(!has_more)
                break;
        }
        if(ans[0] == 0)
            ans.clear();
        // cout<<"Execution time : "<<tick()<<"\n";
        return ans;
    }
};
