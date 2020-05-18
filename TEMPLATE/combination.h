template<class T>
struct Combination{
	vector<T> fact,factinv;
	Combination(int n) : fact(n + 1),factinv(n + 1){
		fact[0] = 1;
		for(int i = 1;i <= n;i++) fact[i] = fact[i - 1] * T(i);
		factinv[n] = ~fact[n];
		for(int i = n;i >= 1;i--) factinv[i - 1] = factinv[i] * T(i);
	}
	T nCr(int n,int r){
		if(r < 0 || n < r) return 0;
		return fact[n] * factinv[r] * factinv[n - r];
	}
};