#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007; 
struct modint{
	long long a;
 
	modint() : a(0){}
	modint(long long t){
		a = t % mod;
		if(a < 0) a += mod;
	}
 
	operator long long() const{ return a; }
 
	bool operator==(const modint &x) const{ return a == x.a; }
	bool operator!=(const modint &x) const{ return a != x.a; }
 
	modint operator-() const{ return modint(a ? (mod - a) : 0); }
	modint operator~() const{ return pow(mod - 2); }
 
	modint operator+(const modint &x) const{ return modint(*this) += x; }
	modint operator-(const modint &x) const{ return modint(*this) -= x; }
	modint operator*(const modint &x) const{ return modint(*this) *= x; }
	modint operator/(const modint &x) const{ return modint(*this) /= x; }
 
	modint &operator+=(const modint &x){
		a += x.a;
		if(a >= mod) a -= mod;
		return *this;
	}
	modint &operator-=(const modint &x){
		a -= x.a;
		if(a < 0) a += mod;
		return *this;
	}
	modint &operator*=(const modint &x){
		a = a * x.a % mod;
		return *this;
	}
	modint &operator/=(const modint &x){
		a = a * (~x).a % mod; 
		return *this;
	}
 
	friend ostream &operator<<(ostream &os,const modint &x){
		return os << x.a;
	}
	friend istream &operator>>(istream &is,modint &x){
		long long t;
		is >> t;
		x = modint(t);
		return is;
	}
 
	modint pow(long long x) const{
		modint ret = 1,tmp = a;
		for(;x;tmp *= tmp,x >>= 1){
			if(x & 1) ret *= tmp;
		}
		return ret;
	}
};