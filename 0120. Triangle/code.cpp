class Solution {
public:
    // memoization runs good but tle in long testcases
    //  int paths(int i, int j, vector<vector<int>>& triangle,
    //            vector<vector<int>>& dp) {
    //      int n = triangle.size();
    //      if (i == n - 1)
    //          return triangle[n - 1][j];

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     int down = triangle[i][j] + paths(i + 1, j, triangle, dp);
    //     int diag = triangle[i][j] + paths(i + 1, j + 1, triangle, dp);

    //     return dp[i][j] = min(down, diag);
    // }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // since every row has different number of cols
        // for (int i = 0; i < n; i++)
        //     dp[i] = vector<int>(triangle[i].size(), -1);
        for (int j = 0; j < n; j++) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int down = triangle[i][j] + dp[i + 1][j];
                int diag = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diag);
            }
        }
        return dp[0][0];
    }
};