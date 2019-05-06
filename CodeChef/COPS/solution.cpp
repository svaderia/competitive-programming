#include <bits/stdc++.h>
using namespace std;

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template <typename T> T lcm(T a, T b){return (a*b)/gcd(a,b); }
double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}


int main(){
    #ifndef ONLINE_JUDGE
		freopen("test", "r", stdin);
	#endif
    fastio;
    
    int T;
    cin >> T;

    while(T-- > 0){
        int M, x, y;
        cin >> M >> x >> y;
        int total = x*y;
        int boo[100] = {0};
        int cop;
        for(int i = 0; i < M; i++){
            cin >> cop;
            cop--;
            boo[cop] = 1;
            for(int j = 1; j <= total; j++ ){
                if((cop - j) >= 0){
                    boo[cop - j] = 1;
                }
                if((cop + j) < 100){
                    boo[cop + j] = 1;
                }
            }
        }
        int sum = 0;
        for(int i = 0; i < 100; i++){
            if(boo[i] == 0){
                sum++;
            }
        }

        cout << sum << "\n";
    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}