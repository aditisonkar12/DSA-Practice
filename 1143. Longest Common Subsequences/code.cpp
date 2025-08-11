//tabulation approach
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int ind2 = 0; ind2 <= m; ind2++)
            dp[0][ind2] = 0;

        for (int ind1 = 0; ind1 <= n; ind1++)
            dp[ind1][0] = 0;

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (text1[ind1 - 1] == text2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else
                    dp[ind1][ind2] =
                        max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
            }
        }
        return dp[n][m];
    }
};

// memoization approach but gives tle
//  class Solution {
//  public:
//      int ways(int ind1, int ind2, string& s1, string& s2,
//               vector<vector<int>>& dp) {
//          if (ind1 == 0 || ind2 == 0)
//              return 0;

//         if (dp[ind1][ind2] != -1)
//             return dp[ind1][ind2];

//         if (s1[ind1 - 1] == s2[ind2 - 1])
//             return 1 + ways(ind1 - 1, ind2 - 1, s1, s2, dp);

//         return max(ways(ind1 - 1, ind2, s1, s2, dp),
//                    ways(ind1, ind2 - 1, s1, s2, dp));
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         int n = text1.length();
//         int m = text2.length();

//         vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//         return ways(n, m, text1, text2, dp);
//     }
// };
