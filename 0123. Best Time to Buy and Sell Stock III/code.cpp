// tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // for (int i = 0; i <= 1; i++) {
        //     for (int j = 0; j <= 2; j++) {
        //         dp[n][i][j] = 0;
        //     }
        // }

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int t = 1; t <= 2; t++) {
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
        return dp[0][1][2];
    }
};

// memoization
// class Solution {
// public:
//     int solve(int ind, int buy, int t, vector<int>& a,
//               vector<vector<vector<int>>>& dp) {
//         int n = a.size();

//         if (t == 0)
//             return 0;

//         if (ind == n)
//             return 0;

//         if (dp[ind][buy][t] != -1)
//             return dp[ind][buy][t];

//         int profit = 0;
//         if (buy) {
//             int buyStock = -a[ind] + solve(ind + 1, 0, t, a, dp);
//             int notBuy = 0 + solve(ind + 1, 1, t, a, dp);
//             profit = max(buyStock, notBuy);
//         } else {
//             int sellStock = a[ind] + solve(ind + 1, 1, t - 1, a, dp);
//             int notSell = 0 + solve(ind + 1, 0, t, a, dp);
//             profit = max(sellStock, notSell);
//         }
//         return dp[ind][buy][t] = profit;
//     }

//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(
//             n, vector<vector<int>>(2, vector<int>(3, -1)));
//         int t = 2;
//         return solve(0, 1, t, prices, dp);
//     }
// };