class Solution {
    class UnionFind {
    private:
        int n, set_size, *parent, *rank;
    public:
        //Complexity: O(n)
        UnionFind(int a) {
            n = set_size = a;
            parent = new int[n+1];
            rank = new int[n+1];
            for(int i = 1; i <= n; ++i) parent[i]=i, rank[i]=1;
        }
        
        //Path Compression
        int find(int x) {
            if (x != parent[x]) return parent[x] = find(parent[x]);
            return x;
        }
        //Complexity : O(A N), where A = Inverse Ackermann function
        void unite(int x, int y) {
            int xroot = find(x), yroot = find(y);
            if (xroot != yroot) {
                if (rank[xroot] >= rank[yroot]) {
                    parent[yroot] = xroot;
                    rank[xroot] += rank[yroot];
                }
                else {
                    parent[xroot] = yroot;
                    rank[yroot] += rank[xroot];
                }
                set_size -= 1;
            }
        }
        int size() { return set_size; }
        void print() {
            for(int i = 1; i <= n; ++i)
                cout << i << " -> " << parent[i] << "\n";
        }
    };
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = (int)grid.size();
        int m = (n > 0) ? (int)grid[0].size() : 0;
        int num_zeros = 0;
        UnionFind dsu = UnionFind(n * m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int pos = i * m + j;
                pos++;
                if(grid[i][j] == '1'){
                    if(i > 0){
                        if(grid[i - 1][j] == '1'){
                             dsu.unite(pos, pos - m);
                        }
                    }
                    if(j > 0){
                        if(grid[i][j - 1] == '1'){
                            dsu.unite(pos, pos - 1);
                        }
                    }
                }else{
                    num_zeros++;
                }
            }
        }
        
        return (int)dsu.size() - num_zeros;
    }
};