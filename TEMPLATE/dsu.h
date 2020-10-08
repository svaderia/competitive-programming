// 0-based indexing assumed

struct UnionFind {
    int n, set_size;
    vi parent, rank;

    UnionFind(int a) : n(a), set_size(n), parent(n), rank(n, 1) {
        rep(i, n) parent[i]=i;
    }

    int find(int x) {
        if (x != parent[x]) return parent[x] = find(parent[x]);
        return x;
    }

    bool merge(int x, int y) {
        int xroot = find(x), yroot = find(y);
        if(xroot == yroot) return false;
        if (rank[xroot] < rank[yroot]) swap(xroot, yroot);
        parent[yroot] = xroot;
        rank[xroot] += rank[yroot];
        set_size -= 1;
        return true;
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }

    int size() { return set_size; }
};
