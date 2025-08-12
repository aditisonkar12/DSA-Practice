class Solution {
public:
    int ways(int ind, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if (ind == 0) {
            return (target % coins[0] == 0);
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notPick = ways(ind - 1, target, coins, dp);
        int pick = 0;
        if (coins[ind] <= target) {
            pick = ways(ind, target - coins[ind], coins, dp);
        }

        return dp[ind][target] = pick + notPick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return ways(n - 1, amount, coins, dp);
    }
};