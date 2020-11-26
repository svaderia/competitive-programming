struct node{
    lli data;
    node(lli val) : data(val) {}
}typedef node;

struct SegTree{
    typedef node T;

    T unit = T(INT_MIN);

    T merge(T a, T b) {
        return T(max(a.data, b.data));
    } // any associatinve function

    vector<T> s; int n;
    SegTree(int nn, T def) : s(2 * nn, def), n(nn) {}
    SegTree(int nn) : s(2 * nn, unit), n(nn) {}

    void build(){
        repD(pos, n - 1, 1)
            s[pos] = merge(s[2 * pos], s[2 * pos + 1]);
    }

    void update(int pos, T val){
        for(s[pos += n] = val; pos /= 2;)
            s[pos] = merge(s[2 * pos], s[2 * pos + 1]);
    }

    T query(int l, int r){ // [l, r)
        T vl = unit, vr = unit;
        for(l += n, r += n; l < r; l /= 2, r /= 2){
            if(l % 2) vl = merge(vl, s[l++]);
            if(r % 2) vr = merge(s[--r], vr);
        }
        return merge(vl, vr);
    }
};
