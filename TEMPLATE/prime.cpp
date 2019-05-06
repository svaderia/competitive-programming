#include <bits/stdc++.h>
using namespace std;

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

void get_divisors(int n){
    int temp = int(ceil( sqrt(n)));
    for(int i = 2; i < temp; i++){
        if(n % i == 0){
            cout << i;
            cout << n/i;
        }
    }
    if(temp * temp == n){
        cout << temp;
    }
    
}