struct segment {
    // TODO: check if it can overflow
    int minimum;
    int data;

    // TODO: Make sure the default constructor initialises identity element.
    segment(int m = INF) : minimum(m) {}

    // TODO: Update to any associative function.
    void join(const segment &other) {
        minimum = min(minimum, other.minimum);
    }

    void join(const segment &seg0, const segment &seg1) {
        *this = seg0;
        join(seg1);
    }
};

/* string to_string(segment c) { */
/*     return to_string(c.minimum); */
/* } */

struct seg_tree{
    int n;
    vector<int> lo, hi;
    vector<segment> seg;

    void pull(int id){
        seg[id].join(seg[2 * id], seg[2 * id + 1]);
    }

    seg_tree(int nn) : n(nn), lo(4 * n), hi(4 * n), seg(4 * n) { build(1, 0, n - 1); }
    seg_tree(vector<segment> &arr) : n(sz(arr)), lo(4 * n), hi(4 * n), seg(4 * n) { build(1, 0, n - 1, arr); }

    void build(int id, int l, int r){
        lo[id] = l, hi[id] = r;
        if(l == r) return;
        int mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
    }

    void build(int id, int l, int r, vector<segment> &arr){
        lo[id] = l, hi[id] = r;
        if(l == r){
            seg[id] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id, l, mid, arr);
        build(2 * id + 1, mid + 1, r, arr);
        pull(id);
    }

    // query [l, r]
    segment query(int l, int r, int id = 1){
        // outside
        if(lo[id] > r || hi[id] < l){
            return segment();
        }

        if(l <= lo[id] && hi[id] <= r){
            return seg[id];
        }

        segment lquery = query(l, r, 2 * id);
        segment rquery = query(l, r, 2 * id + 1);
        lquery.join(rquery);
        return lquery;
    }

    void set(int p, segment val, int id = 1){
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
        pull(id);
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
};
