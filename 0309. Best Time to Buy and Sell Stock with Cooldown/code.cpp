// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy) {
                    int buyStock = -prices[ind] + dp[ind + 1][0];
                    int notBuy = 0 + dp[ind + 1][1];
                    profit = max(buyStock, notBuy);
                } else {
                    int sellStock = prices[ind] + dp[ind + 2][1];
                    int notSell = 0 + dp[ind + 1][0];
                    profit = max(sellStock, notSell);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

// memoization
//  class Solution {
//  public:
//      int solve(int ind, int buy, vector<int>& a, vector<vector<int>>& dp) {
//          int n = a.size();
//          if (ind == n)
//              return 0;

//         if (dp[ind][buy] != -1)
//             return dp[ind][buy];

//         int profit = 0;
//         if (buy) {
//             int buyStock = -a[ind] + solve(ind + 1, 0, a, dp);
//             int notBuy = 0 + solve(ind + 1, 1, a, dp);
//             profit = max(buyStock, notBuy);
//         } else {
//             int sellStock = a[ind] + solve(ind + 2, 1, a, dp);
//             int notSell = 0 + solve(ind + 1, 0, a, dp);
//             profit = max(sellStock, notSell);
//         }
//         return dp[ind][buy] = profit;
//     }

//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n + 2, vector<int>(2, -1));
//         return solve(0, 1, prices, dp);
//     }
// };