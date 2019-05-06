#include <bits/stdc++.h>
using namespace std;

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define lli long long int

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
        lli Max = 1000000000;
        lli X1, X2, X4;
        lli xl, yl, xu, yu;

        cout << "Q 0 0\n" << flush;
        cin >> X1;
        cout << "Q " << Max << " 0\n" << flush;
        cin >> X4;
        cout << "Q 0 " << Max << "\n" << flush;
        cin >> X2;

        // cout << X1 << " " << X2 << " " << X4 << "\n";
        lli mid = (X1 + Max - X4) / 2;
        cout << "Q " << mid << " 0\n" << flush;
        cin >> yl;

        xl = X1 - yl;
        xu = Max - X4 + yl;
        yu = Max - X2 + xl;

        cout << "A " << xl << " " << yl << " " << xu << " " << yu << "\n" << flush;
        
        int ans;
        cin >> ans;

    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}