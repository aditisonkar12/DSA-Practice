class Solution {
public:
    // tabulation and space optimization
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for (int ind = 1; ind < n; ind++) {
            int pick = nums[ind];
            if (ind > 1)
                pick += prev2;
            int notPick = 0 + prev;

            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};

// dp
//  int ways(int ind, vector<int>& nums,vector<int>& dp) {
//      if (ind == 0)
//          return nums[ind];
//      if (ind < 0)
//          return 0;
//      if(dp[ind]!= -1)
//      return dp[ind];

//     int pick = nums[ind] + ways(ind - 2, nums,dp);
//     int notPick = 0 + ways(ind-1, nums,dp);
//     return dp[ind]=max(pick, notPick);
// }

// int rob(vector<int>& nums) {
//     int n = nums.size();
//     vector<int> dp(n + 1, -1);
//     return ways(n - 1, nums,dp);
// }

// brute force
// int rob(vector<int>& nums) {
//     int n = nums.size();
//     int sumo = 0, sume = 0;
//     for (int i = 0; i < n; i++) {
//         if (i % 2 == 0) {
//             sume += nums[i];
//         } else {
//             sumo += nums[i];
//         }
//     }
//     return max(sumo, sume);
// }