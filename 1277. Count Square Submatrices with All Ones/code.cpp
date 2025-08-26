class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
            dp[0][j] = matrix[0][j];
        for (int i = 0; i < n; i++)
            dp[i][0] = matrix[i][0];

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = 1 + min(dp[i - 1][j],
                                       min(dp[i - 1][j - 1], dp[i][j - 1]));
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += dp[i][j];
            }
        }
        return sum;
    }
};

// memoization
//  class Solution {
//  public:
//      int solve(int i, int j, vector<vector<int>>& matrix,
//                vector<vector<int>>& dp) {
//          int n = matrix.size();
//          int m = matrix[0].size();

//         if (i < 0 || j < 0)
//             return 0;

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (matrix[i][j] == 0)
//             return dp[i][j] = 0;

//         int up = solve(i - 1, j, matrix, dp);
//         int left = solve(i, j - 1, matrix, dp);
//         int diag = solve(i - 1, j - 1, matrix, dp);

//         return dp[i][j] = 1 + min(up, min(left, diag));
//     }

//     int countSquares(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));

//         int count = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 count += solve(i, j, matrix, dp);
//             }
//         }
//         return count;
//     }
// };