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

