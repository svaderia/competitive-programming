void get_divisors(int n, vi &d){
    int temp = int(ceil( sqrt(n)));
    for(int i = 2; i < temp; i++){
        if(n % i == 0){
            d.pb(i);
            d.pb(n / i);
        }
    }
    if(temp * temp == n){
        d.pb(temp);
    }

}
