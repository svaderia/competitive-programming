class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }
        int H = (int)grid.size();
        int W = (int)grid[0].size();
        vector<vector<int>> dp(H, vector<int>(W));
        
        dp[0][0] = grid[0][0];
        for(int col = 1; col < W; col++){
            dp[0][col] += dp[0][col - 1] + grid[0][col];
        }
        for(int row = 1; row < H; row++){
            dp[row][0] += dp[row - 1][0] + grid[row][0];
        }
        
        for(int row = 1; row < H; row++){
            for(int col = 1; col < W; col++){
                dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + grid[row][col];
            }
        }
        
        return dp[H - 1][W - 1];
    }
};