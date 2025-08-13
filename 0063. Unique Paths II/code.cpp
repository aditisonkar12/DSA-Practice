class Solution {
public:
    int mod = (int)(2 * 1e9);
    // memoization
    //  int paths(int i, int j, vector<vector<int>>& arr, vector<vector<int>>&
    //  dp) {
    //      if (i >= 0 && j >= 0 && arr[i][j] == 1)
    //          return 0;
    //      if (i == 0 & j == 0)
    //          return 1;
    //      if (i < 0 || j < 0)
    //          return 0;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int up = paths(i - 1, j, arr, dp);
    //     int left = paths(i, j - 1, arr, dp);
    //     return dp[i][j] = (up + left) % mod;
    // }

    //memoization and tabulation code with necssary changes done in the main function for the tabulation code 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        int dp[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = (up + left) % mod;
                }
            }
        }
        // return paths(m - 1, n - 1, obstacleGrid, dp);
        return dp[m - 1][n - 1];
    }
};

