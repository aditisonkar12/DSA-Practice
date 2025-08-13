class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int j = 0; j < n; j++)
            dp[0][j] = matrix[0][j];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = matrix[i][j] + dp[i - 1][j];
                int ldiag = matrix[i][j];
                if (j - 1 >= 0)
                    ldiag += dp[i - 1][j - 1];
                else
                    ldiag += 1e9;
                int rdiag = matrix[i][j];
                if (j + 1 < n)
                    rdiag += dp[i - 1][j + 1];
                else
                    rdiag += 1e9;
                dp[i][j] = min(up, min(ldiag, rdiag));
            }
        }

        int mini = dp[n - 1][0];
        for (int j = 1; j < n; j++) {
            mini = min(mini, dp[n - 1][j]);
        }
        return mini;
    }
};

//memoization function for recursion
// int paths(int i, int j, vector<vector<int>>& matrix,
    //           vector<vector<int>>& dp) {
    //     int n = matrix.size();
    //     if (j < 0 || j >= n)
    //         return 1e8;
    //     if (i == 0)
    //         return matrix[0][j];
    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     int up = matrix[i][j] + paths(i - 1, j, matrix, dp);
    //     int ldiag = matrix[i][j] + paths(i - 1, j - 1, matrix, dp);
    //     int rdiag = matrix[i][j] + paths(i - 1, j + 1, matrix, dp);

    //     return dp[i][j] = min(up, min(ldiag, rdiag));
    // }