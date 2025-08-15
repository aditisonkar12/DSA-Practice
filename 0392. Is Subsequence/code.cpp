//tabulation
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (t[i-1] == s[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[m][n];
    }
};

//memoization
// class Solution {
// public:
//     bool f(int i, int j, string& t, string& s, vector<vector<int>>& dp) {
//         if (j < 0)
//             return true;
//         if (i < 0)
//             return false;

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (t[i] == s[j]) {
//             return dp[i][j] = f(i - 1, j - 1, t, s, dp);
//         } else {
//             return dp[i][j] = f(i - 1, j, t, s, dp);
//         }
//     }

//     bool isSubsequence(string s, string t) {
//         int n = s.length();
//         int m = t.length();

//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         return f(m - 1, n - 1, t, s, dp);
//     }
// };