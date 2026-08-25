class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = k;
        for (int x : nums) {
            if (x == ans) {
                ans += k;
            } else if (x > ans) {
                return ans;
            }
        }
        return ans;
    }
};