struct segment_change {
    // TODO: check for overflows
    int to_add, to_set;

    // TODO: Make sure the default constructor initialises identity element.
    segment_change(int _to_add = 0, int _to_set = -INF) : to_add(_to_add), to_set(_to_set) {}

    bool has_set() const {
        return to_set != -INF;
    }

    bool has_change() const {
        return has_set() || to_add != 0;
    }

    // Return the combined result of applying this segment_change followed by `other`.
    // TODO: check for boundary values.
    segment_change combine(const segment_change &other) {
        if (other.has_set()) {
            return other;
        }

        segment_change n = segment_change(to_add + other.to_add, to_set);
        return n;
    }
};

/* string to_string(segment_change c) { */
/*     vector<int> print = {c.to_add, c.to_set}; */
/*     return to_string(print) ; */
/* } */

struct segment {
    // TODO: check if it can overflow
    int sum;
    int len;

    // TODO: Make sure the default constructor initialises identity element.
    segment(int _sum = 0, int _len = 0) : sum(_sum), len(_len) {}

    void apply(const segment_change &change) {
        if (change.has_set()) {
            sum = len * change.to_set;
        }
        sum += len * change.to_add;
    }

    // TODO: Update to any associative function.
    void join(const segment &other) {
        sum += other.sum;
        len += other.len;
    }

    void join(const segment &seg0, const segment &seg1) {
        *this = seg0;
        join(seg1);
    }
};

/* string to_string(segment c) { */
/*     vector<int> print = {c.sum, c.len}; */
/*     return to_string(print) ; */
/* } */

struct seg_tree_lazy {
    int n;
    vector<int> lo, hi;
    vector<segment> seg;
    vector<segment_change> seg_change;

    void pull(int id) {
        seg[id].join(seg[2 * id], seg[2 * id + 1]);
    }

    void apply_and_combine(int id, const segment_change &change) {
        seg[id].apply(change);
        seg_change[id] = seg_change[id].combine(change);
    }

    void push(int id) {
        if (lo[id] != hi[id] && seg_change[id].has_change()) {
            apply_and_combine(2 * id, seg_change[id]);
            apply_and_combine(2 * id + 1, seg_change[id]);
        }
        seg_change[id] = segment_change();
    }

    void build(int id, int l, int r) {
        lo[id] = l, hi[id] = r;
        if (l == r)
            return;
        int mid = (l + r) / 2;
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
    }

    void build(int id, int l, int r, vector<segment> &arr) {
        lo[id] = l, hi[id] = r;
        if (l == r) {
            seg[id] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * id, l, mid, arr);
        build(2 * id + 1, mid + 1, r, arr);
        pull(id);
    }

    // query [l, r]
    segment query(int l, int r, int id = 1) {
        // outside
        if (lo[id] > r || hi[id] < l) {
            return segment();
        }

        if (l <= lo[id] && hi[id] <= r) {
            return seg[id];
        }

        push(id);

        segment lquery = query(l, r, 2 * id);
        segment rquery = query(l, r, 2 * id + 1);
        lquery.join(rquery);
        return lquery;
    }

    void range_change(int l, int r, segment_change change, int id = 1) {
        if (l > hi[id] || r < lo[id])
            return;

        if (l <= lo[id] && hi[id] <= r) {
            apply_and_combine(id, change);
            return;
        }

        push(id);

        range_change(l, r, change, 2 * id);
        range_change(l, r, change, 2 * id + 1);

        pull(id);
    }

    void set(int p, segment val, int id = 1) {
        // No overlap
        if (p < lo[id] || p > hi[id]) {
            return;
        }

        if (lo[id] == hi[id]) {
            seg[id] = val;
            return;
        }

        push(id);

        set(p, val, 2 * id);
        set(p, val, 2 * id + 1);
        pull(id);
    }

    seg_tree_lazy(int nn) : n(nn), lo(4 * n), hi(4 * n), seg(4 * n), seg_change(4 * n) {
        build(1, 0, n - 1);
    }
    seg_tree_lazy(vector<segment> &arr) : n(sz(arr)), lo(4 * n), hi(4 * n), seg(4 * n), seg_change(4 * n) {
        build(1, 0, n - 1, arr);
    }
};
