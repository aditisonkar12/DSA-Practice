// memoization
class Solution {
public:
    int solve(int i, int mini, vector<int>& prices, vector<int>& dp) {
        int n = prices.size();
        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int sell = prices[i] - mini;
        int skip = solve(i + 1, min(mini, prices[i]), prices, dp);

        return dp[i] = max(sell, skip);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, -1);

        int mini = prices[0];
        return solve(1, mini, prices, dp);
    }
};

// recursion
// class Solution {
// public:
//     int solve(int i, int mini, vector<int>& prices) {
//         int n = prices.size();
//         if (i == n)
//             return 0;

//         int sell = prices[i] - mini;
//         int skip = solve(i + 1, min(mini, prices[i]), prices);

//         return max(sell, skip);
//     }

//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int mini = prices[0];
//         return solve(1, mini, prices);
//     }
// };

// greedy
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int ans = 0;
//         int mini = prices[0];

//         for (int i = 1; i < n; i++) {
//             int cost = prices[i] - mini;
//             ans = max(ans, cost);
//             mini = min(mini, prices[i]);
//         }
//         return ans;
//     }
// };

// two pointers approach
//  class Solution {
//  public:
//      int maxProfit(vector<int>& prices) {
//          int n = prices.size();
//          int left = 0, right = 1;
//          int ans = 0, maxi = 0;
//          while (right < n) {
//              if (prices[right] >= prices[left]) {
//                  ans = prices[right] - prices[left];
//                  maxi = max(maxi, ans);
//              } else {
//                  left = right;
//              }
//              right++;
//          }
//          return maxi;
//      }
//  };