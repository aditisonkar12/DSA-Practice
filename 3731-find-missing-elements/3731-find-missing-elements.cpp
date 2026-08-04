class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int i = 0;

        for (int k = nums[0] + 1; k < nums[n - 1] + 1; k++) {
            while (i < n && nums[i] < k)
                i++;
            if (i == n || nums[i] != k)
                ans.push_back(k);
        }
        return ans;
    }
};