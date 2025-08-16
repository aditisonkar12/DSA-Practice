class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        // for (int i = 0; i <= 1; i++) {
        //     for (int j = 0; j <= 2; j++) {
        //         dp[n][i][j] = 0;
        //     }
        // }

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int t = 1; t <= k; t++) {
                    int profit = 0;
                    if (buy) {
                        int buyStock = -prices[ind] + dp[ind + 1][0][t];
                        int notBuy = 0 + dp[ind + 1][1][t];
                        profit = max(buyStock, notBuy);
                    } else {
                        int sellStock = prices[ind] + dp[ind + 1][1][t - 1];
                        int notSell = 0 + dp[ind + 1][0][t];
                        profit = max(sellStock, notSell);
                    }
                    dp[ind][buy][t] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};