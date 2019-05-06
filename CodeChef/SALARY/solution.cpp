#include <bits/stdc++.h>
using namespace std;

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

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

    int N;
    while(T-- > 0){
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        sort(arr, arr + N);
        int ans = 0;
        for(int i = N - 1; i > 0; i -- ){
            ans += (arr[i] - arr[i-1]) * (N - i);
        }
        cout << ans << "\n";
    }

    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}