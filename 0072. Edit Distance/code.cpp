//tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 0 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j - 1],
                                       min(dp[i - 1][j], dp[i - 1][j - 1]));
                }
            }
        }
        return dp[n][m];
    }
};

// memoization
// class Solution {
// public:
//     int ways(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
//         if (i < 0)
//             return j + 1;
//         if (j < 0)
//             return i + 1;

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (s[i] == t[j])
//             return dp[i][j] = 0 + ways(i - 1, j - 1, s, t, dp);

//         int insert = 1 + ways(i, j - 1, s, t, dp);
//         int deletee = 1 + ways(i - 1, j, s, t, dp);
//         int replace = 1 + ways(i - 1, j - 1, s, t, dp);

//         return dp[i][j] = min(insert, min(deletee, replace));
//     }

//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         return ways(n - 1, m - 1, word1, word2, dp);
//     }
// };