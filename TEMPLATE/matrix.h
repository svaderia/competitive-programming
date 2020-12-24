struct Matrix {
    typedef vector<int> T;
    int n;
    vector<T> a;
    Matrix(int nn) : n(nn), a(n, T(n)) {}

    Matrix operator *(const Matrix& other) {
        Matrix product(n);
        rep(i,n)rep(j,n)rep(k,n) {
            product.a[i][k] += a[i][j] * other.a[j][k];
        }
        return product;
    }

};

Matrix expo_power(Matrix a, long long k) {
    int n = a.n;
    Matrix product(n);
    rep(i,n) product.a[i][i] = 1;
    while(k > 0) {
        if(k % 2) {
            product = product * a;
        }
        a = a * a;
        k /= 2;
    }
    return product;
}
