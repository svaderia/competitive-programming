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

    while(T-- > 0){
        int N;
        cin >> N;
        int arr[N];
        int flag = 1;
        int boo[7] = {0};
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        if(arr[0] != 1 ){
            flag = 0;
        }
        
        for (int i = 0; i < N; i++){
            if(arr[i] != arr[N - 1 - i]){
                flag = 0;
            }
            if( arr[i] > 7 && arr[i] < 1){
                flag = 0;
            }else{
                boo[arr[i] - 1] = 1;
            }
        }
        for( int i = 1; i < N; i++){
            if( abs(arr[i] - arr[i-1]) > 1){
                flag = 0;
            }
        }
        for(int i = 0; i < 7; i++){
            if(boo[i] != 1){
                flag = 0;
            }
        }
        if(flag == 1){
            cout << "yes" << "\n";
        }else{
            cout << "no" << "\n";
        }
    }
    // cout<<"Execution time : "<<tick()<<"\n";
    return 0;
}