// 0-based indexing assumed

struct dsu {
    vi p;

    dsu(int _n) { p.rsz(_n, -1); }

    int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

    int sameSet(int x, int y) { return find(x) == find(y); }
    
    int size(int x){ return -p[find(x)]; }

    int unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return 0;
        if (p[y] > p[x]) swap(x, y);
        p[y] += p[x]; p[x] = y; return 1;
    }
};
