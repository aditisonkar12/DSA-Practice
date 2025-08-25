// tabulation
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;

        for (int ind = n - 1; ind >= 0; ind--) {
            int ans = INT_MIN;
            int len = 0, maxi = INT_MIN;

            for (int j = ind; j < min(n, ind + k); j++) {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = len * maxi + dp[j+1];
                ans = max(ans, sum);
            }
            dp[ind] = ans;
        }
        return dp[0];
    }
};

// memoization
//  class Solution {
//  public:
//      int solve(int ind, int k, int n, vector<int>& arr, vector<int>& dp) {
//          if (ind == n)
//              return 0;

//         if (dp[ind] != -1)
//             return dp[ind];

//         int ans = INT_MIN;
//         int len = 0, maxi = INT_MIN;

//         for (int j = ind; j < min(n, ind + k); j++) {
//             len++;
//             maxi = max(maxi, arr[j]);
//             int sum = len * maxi + solve(j + 1, k, n, arr, dp);
//             ans = max(ans, sum);
//         }
//         return dp[ind] = ans;
//     }

//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n = arr.size();
//         vector<int> dp(n, -1);
//         return solve(0, k, n, arr, dp);
//     }
// };