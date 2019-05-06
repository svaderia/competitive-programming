#include <iostream>

using namespace std;

int main(){
    int T;
    int X, Y, K, N, P, C;
    int i, i2, i3;
    int truth = 0;
    cin >> T;
    for(i = 0; i < T; i++){
        truth = 0;
        cin >> X >> Y >> K >> N ;
        int need = X - Y;
        for ( i2 = 0 ; i2 < N ; i2++){
            cin >> P >> C;
            if( C <= K){
                if( P >= need){
                    truth = 1;
                }
            }
        }
        if(truth == 0){
            cout << "UnluckyChef\n";
        }else{
            cout << "LuckyChef\n";
        }
    }
    return 0;
}