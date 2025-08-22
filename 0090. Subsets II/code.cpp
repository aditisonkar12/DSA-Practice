class Solution {
public:
    void subsets(int ind, vector<int>& nums, vector<int>& res,
                 vector<vector<int>>& ans) {
        ans.push_back(res);
        for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1])
                continue;
            res.push_back(nums[i]);
            subsets(i + 1, nums, res, ans);
            res.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        subsets(0, nums, res, ans);
        return ans;
    }
};