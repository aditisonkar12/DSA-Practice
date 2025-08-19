class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), backtrack(n);
        for (int i = 0; i < n; i++)
            backtrack[i] = i;

        int maxi = 1;
        int lastInd = 0;
        for (int ind = 0; ind < n; ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (nums[ind] % nums[prev] == 0 && 1 + dp[prev] > dp[ind]) {
                    dp[ind] = 1 + dp[prev];
                    backtrack[ind] = prev;
                }
            }
            if (dp[ind] > maxi) {
                maxi = dp[ind];
                lastInd = ind;
            }
        }

        vector<int> ans;
        ans.push_back(nums[lastInd]);

        while (backtrack[lastInd] != lastInd) {
            lastInd = backtrack[lastInd];
            ans.push_back(nums[lastInd]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};