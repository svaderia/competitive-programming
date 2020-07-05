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
