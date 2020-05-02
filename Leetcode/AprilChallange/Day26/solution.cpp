class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = (int) text1.size();
        int m = (int) text2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        dp[n][m] = 0;
        for(int i = 0; i < n; i++){
            dp[i][m] = 0;
        }
        for(int i = 0; i < m; i++){
            dp[n][i] = 0;
        }
        for(int x = n - 1; x >= 0; x--){
            for(int y = m - 1; y >= 0; y--){
                if(text1[x] == text2[y]){
                    dp[x][y] = 1 + dp[x + 1][y + 1];
                }
                dp[x][y] = max({dp[x][y], dp[x][y + 1], dp[x + 1][y]});
            }
        }
        // cout << dp[0][0] << endl;
        return dp[0][0];
    }
};