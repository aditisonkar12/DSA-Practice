// tabulation
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;

        // precompute palindromes
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len <= 2) pal[i][j] = true;
                    else pal[i][j] = pal[i+1][j-1];
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int mini = INT_MAX;

            for (int j = i; j < n; j++) {
                if (pal[i][j]) {
                    int cnt = 1 + dp[j + 1];
                    mini = min(mini, cnt);
                }
            }
            dp[i] = mini;
        }
        return dp[0] - 1;
    }
};

// memoization
//  class Solution {
//  public:
//      bool isPalindrome(int i, int j, string s) {
//          while (i < j) {
//              if (s[i] != s[j])
//                  return false;
//              i++;
//              j--;
//          }
//          return true;
//      }

//     int ways(int i, int n, string& s, vector<int>& dp) {
//         if (i == n)
//             return 0;

//         if (dp[i] != -1)
//             return dp[i];

//         int mini = INT_MAX;

//         for (int j = i; j < n; j++) {
//             if (isPalindrome(i, j, s)) {
//                 int cnt = 1 + ways(j + 1, n, s, dp);
//                 mini = min(mini, cnt);
//             }
//         }
//         return dp[i] = mini;
//     }

//     int minCut(string s) {
//         int n = s.size();
//         vector<int> dp(n, -1);
//         return ways(0, n, s, dp) - 1; // -1 bec it is counting a partition at
//         the
//                                   // end of the string which is not needed
//     }
// };