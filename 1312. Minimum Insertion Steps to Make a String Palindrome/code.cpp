class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());

        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int ind2 = 0; ind2 <= m; ind2++)
            dp[0][ind2] = 0;

        for (int ind1 = 0; ind1 <= n; ind1++)
            dp[ind1][0] = 0;

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (s[ind1 - 1] == t[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else
                    dp[ind1][ind2] =
                        max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
        return n - dp[n][m];
    }
};