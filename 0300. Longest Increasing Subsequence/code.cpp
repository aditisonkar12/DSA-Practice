// best tabulation in 1d dp array
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxi = 1;
        for (int ind = 0; ind < n; ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (nums[prev] < nums[ind])
                    dp[ind] = max(dp[ind], 1 + dp[prev]);
            }
            maxi = max(maxi, dp[ind]);
        }
        return maxi;
    }
};

// tabulation
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

//         for (int ind = n - 1; ind >= 0; ind--) {
//             for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
//                 int notPick = 0 + dp[ind + 1][prev_ind + 1];
//                 int pick = 0;
//                 if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
//                     pick = 1 + dp[ind + 1][ind + 1];
//                 }
//                 dp[ind][prev_ind + 1] = max(pick, notPick);
//             }
//         }
//         return dp[0][-1 + 1];
//     }
// };

// memoization
//  class Solution {
//  public:
//      int solve(int ind, int prev_ind, vector<int>& nums,
//                vector<vector<int>>& dp) {
//          int n = nums.size();
//          if (ind == n)
//              return 0;

//         // did prev_ind+1 because prev_ind can be -1
//         if (dp[ind][prev_ind + 1] != -1)
//             return dp[ind][prev_ind + 1];

//         int notPick = 0 + solve(ind + 1, prev_ind, nums, dp);
//         int pick = 0;
//         if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
//             pick = 1 + solve(ind + 1, ind, nums, dp);
//         }
//         return dp[ind][prev_ind + 1] = max(pick, notPick);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//         return solve(0, -1, nums, dp);
//     }
// };