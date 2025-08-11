class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int ind2 = 0; ind2 <= m; ind2++)
            dp[0][ind2] = 0;

        for (int ind1 = 0; ind1 <= n; ind1++)
            dp[ind1][0] = 0;

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (word1[ind1 - 1] == word2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else
                    dp[ind1][ind2] =
                        max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
        return n + m - (2 * dp[n][m]);
    }
};