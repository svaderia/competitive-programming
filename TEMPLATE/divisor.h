vector<int> get_divisors(int n){
    vector<int> d;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            if(i * i == n) d.pb(i);
            else d.pb(i), d.pb(n / i);
        }
    }
    return d;
}

vector<int> factor(int n) {
    vector<int> ret;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret.push_back(i);
            n /= i;
        }
    }
    if (n > 1) ret.push_back(n);
    return ret;
}
