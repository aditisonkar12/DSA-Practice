class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int curr = nums[0];
        ans.push_back(curr);
        for (int i = 1; i < n; i++) {
            curr += nums[i];
            ans.push_back(curr);
        }
        return ans;
    }
};