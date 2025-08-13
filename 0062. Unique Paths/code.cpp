//dp memoization
class Solution {
public:
    int paths(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return 1;
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = paths(i - 1, j, dp);
        int left = paths(i, j - 1, dp);

        return dp[i][j] = up + left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(m - 1, n - 1, dp);
    }
};

// recursion
// int paths(int i, int j) {
//     if (i == 0 && j == 0)
//         return 1;
//     if (i < 0 || j < 0)
//         return 0;
//     int up = paths(i - 1, j);
//     int left = paths(i, j - 1);
//     return up + left;
// }

// int uniquePaths(int m, int n) { return paths(m - 1, n - 1); }