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