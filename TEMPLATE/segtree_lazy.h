// Improvement : Add the segment_change and segment structs from here.
// https://github.com/nealwu/competitive-programming/blob/master/seg_tree/seg_tree.cc

struct node{
    int data;
    int delta;
    bool lazyset;
    node(int val) : data(val) , delta(0), lazyset(false) {}
    node() {}
}typedef node;

string to_string(node c) {
    return to_string(c.data);
}

struct seg_tree_lazy{
    typedef node T;

private:
    int n;
    vi lo, hi;
    vector<T> seg;

    T unit = T(0); 
    T merge(T a, T b) {
        return T(a.data + b.data);
    } // any associatinve function

    inline void pull(int id){
        seg[id] = merge(seg[2 * id], seg[2 * id + 1]);
    }

    // updates node's data when lazy data is added. 
    inline void update_lazy(int id, int lval){
        seg[id].data += (hi[id] - lo[id] + 1) * lval;
    }

    // supports both range_increase and range_set together.
    // lazyset bool is used to differentiate between set and increase
    void push(int id){
        if(lo[id] != hi[id]){
            int left = 2 * id, right = left + 1;
            if(seg[id].lazyset){
                seg[left].lazyset = seg[right].lazyset = true;
                seg[left].delta = seg[right].delta = seg[left].data = seg[right].data = 0;
            }
            seg[left].delta += seg[id].delta;
            seg[right].delta += seg[id].delta;
            update_lazy(left, seg[id].delta);
            update_lazy(right, seg[id].delta);
        }
        seg[id].lazyset = false;
        seg[id].delta = 0;
    }

public:
    void build(int id, int l, int r){
        lo[id] = l, hi[id] = r;
        if(l == r) return;
        int mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id, mid + 1, r);
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
        pull(id);
    }

    T query(int l, int r, int id = 1){
        // outside
        if(lo[id] > r || hi[id] < l)
            return unit;

        push(id);

        if(l <= lo[id] && hi[id] <= r)
            return seg[id];

        T lquery = query(l, r, 2 * id);
        T rquery = query(l, r, 2 * id + 1);
        pull(id);

        return  merge(lquery, rquery);
    }

    void range_increase(int l, int r, int val, int id = 1){
        // outside
        if(lo[id] > r || hi[id] < l) return;

        if(l <= lo[id] && hi[id] <= r){
            seg[id].delta += val;
            update_lazy(id, val);
            return;
        }

        push(id);
        range_increase(l, r, val, 2 * id);
        range_increase(l, r, val, 2 * id + 1);
        pull(id);
    }

    void range_set(int l, int r, int val, int id = 1){
        // outside
        if(lo[id] > r || hi[id] < l) return;

        if(l <= lo[id] && hi[id] <= r){
            seg[id].data = 0;
            seg[id].delta = val;
            seg[id].lazyset = true;
            update_lazy(id, val);
            return;
        }

        push(id);
        range_set(l, r, val, 2 * id);
        range_set(l, r, val, 2 * id + 1);
        pull(id);
    }

    void set(int p, int val, int id = 1){
        // No overlap
        if(p < lo[id] || p > hi[id])
            return;

        if(lo[id] == hi[id]){
            seg[id] = val;
            return;
        }

        push(id);
        set(p, val, 2 * id);
        set(p, val, 2 * id + 1);
        pull(id);
    }

    seg_tree_lazy(int nn, T def) : n(nn), lo(4 * n), hi(4 * n), seg(4 * n, def) { build(1, 0, n - 1); }
    seg_tree_lazy(int nn) : n(nn), lo(4 * n), hi(4 * n), seg(4 * n)  { build(1, 0, n - 1); }
    seg_tree_lazy(vi &arr) : n(sz(arr)), lo(4 * n), hi(4 * n), seg(4 * n)  { build(1, 0, n - 1, arr); }

};
