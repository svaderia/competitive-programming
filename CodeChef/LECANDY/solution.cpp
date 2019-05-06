#include <iostream>

using namespace std;
int main(){
    int T, N, C;
    int it;
    cin >> T;
    for(it=0; it<T; it++){
        cin >> N >> C;
        int it2, sum = 0, temp;
        for(it2 = 0; it2 < N; it2++){
            cin >> temp;
            sum += temp;
        }
        if( sum <= C){
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }

    }
    return 0;
}