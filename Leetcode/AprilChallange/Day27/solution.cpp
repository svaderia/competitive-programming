class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = (int) matrix.size();
        if(n == 0){
            return 0;
        }
        int m = (int) matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        for(int i = 0; i < n; i++){
            dp[i][0] = matrix[i][0] == '1';
            ans = max(ans, dp[i][0]);
        }
        for(int i = 0; i < m; i++){
            dp[0][i] = matrix[0][i] == '1';
            ans = max(ans, dp[0][i]);
        }
        
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + 1;
                    ans = max(ans, dp[i][j]);
                }else{
                    dp[i][j] = 0;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        
        
        return ans * ans;
        
    }
};