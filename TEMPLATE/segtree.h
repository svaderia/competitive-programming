struct node{
    int data;
    node(int val) : data(val) {}
    node() {}
}typedef node;

string to_string(node c) {
    return to_string(c.data);
}

struct SegTree{
    typedef node T;

public:
    SegTree(int nn, T def) : n(nn), lo(4 * n), hi(4 * n), seg(4 * n, def) { build(1, 0, n - 1); }
    SegTree(int nn) : n(nn), lo(4 * n), hi(4 * n), seg(4 * n, unit) { build(1, 0, n - 1); }
    SegTree(vi &arr) : n(sz(arr)), lo(4 * n), hi(4 * n), seg(4 * n) { build(1, 0, n - 1, arr); }

    void build(int id, int l, int r){
        lo[id] = l, hi[id] = r;
        if(l == r) return;
        int mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
    }

    void build(int id, int l, int r, vi &arr){
        lo[id] = l, hi[id] = r;
        if(l == r){
            seg[id] = T(arr[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id, l, mid, arr);
        build(2 * id + 1, mid + 1, r, arr);
        update(id);
    }

    T query(int l, int r, int id = 1){
        // outside
        if(lo[id] > r || hi[id] < l){
            return unit;
        }

        if(l <= lo[id] && hi[id] <= r){
            return seg[id];
        }

        T leftQuery = query(l, r, 2 * id);
        T rightQuery = query(l, r, 2 * id + 1);

        return  merge(leftQuery, rightQuery);
    }

    void set(int p, int val, int id = 1){
        // No overlap
        if(p < lo[id] || p > hi[id]){
            return;
        }

        if(lo[id] == hi[id]){
            seg[id] = val;
            return;
        }

        set(p, val, 2 * id);
        set(p, val, 2 * id + 1);
        update(id);
    }

    int right_bound(int l, int val, int id = 1){
        // No overlap
        if(l > hi[id] || seg[id].data < val){
            return 0;
        }

        if(lo[id] == hi[id]){
            return lo[id];
        }

        if(seg[2*id].data >= val)
            return right_bound(l, val, 2 * id);
        else
            return right_bound(l, val, 2 * id + 1);

    }

private :
    T unit = T(-INF);

    T merge(T a, T b) {
        return T(max(a.data, b.data));
    } // any associatinve function

    int n;
    vi lo, hi;
    vector<T> seg;

    void update(int idx){
        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1]);
    }
};
