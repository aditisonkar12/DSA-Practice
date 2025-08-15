// tabulation
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
            dp[i][0] = false;
        for (int j = 1; j <= m; j++) {
            bool flag = true;
            for (int k = 1; k <= j; k++) {
                if (p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                else
                    dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};

// memoization
//  class Solution {
//  public:
//      bool ways(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
//          if (i < 0 && j < 0)
//              return true;
//          if (j < 0 && i >= 0)
//              return false;
//          if (i < 0 && j >= 0) {
//              for (int k = 0; k < i; k++)
//                  if (p[k] != '*')
//                      return false;
//              return true;
//          }

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (s[i] == p[j] || p[j] == '?')
//             return dp[i][j] = ways(i - 1, j - 1, s, p, dp);
//         else if (p[j] == '*')
//             return dp[i][j] =
//                        ways(i - 1, j, s, p, dp) || ways(i, j - 1, s, p, dp);
//         return false;
//     }

//     bool isMatch(string s, string p) {
//         int n = s.length();
//         int m = p.length();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         return ways(n - 1, m - 1, s, p, dp);
//     }
// };