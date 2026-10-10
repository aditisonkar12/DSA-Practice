class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int curr = nums[0];
        for (int i = 0; i < n; i++) {
            if (i == 0)
                ans.push_back(curr);
            else {
                curr += nums[i];
                ans.push_back(curr);
            }
        }
        return ans;
    }
};