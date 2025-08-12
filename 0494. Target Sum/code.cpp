class Solution {
public:
    int partitions(int ind, int target, vector<int>& arr,
                   vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target == 0 && arr[0] == 0)
                return 2;
            if (target == 0 || target == arr[0])
                return 1;
            return 0;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notPick = partitions(ind - 1, target, arr, dp);
        int pick = 0;
        if (arr[ind] <= target) {
            pick = partitions(ind - 1, target - arr[ind], arr, dp);
        }
        return dp[ind][target] = pick + notPick;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;

        if (totalSum - target < 0)
            return 0;
        if ((totalSum - target) % 2 == 1)
            return 0;

        int t = (totalSum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(t + 1, -1));

        return partitions(n - 1, t, nums, dp);
    }
};