class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int val = 0;
        for (int b : nums) {
            val = (val * 2 + b) % 5;
            if (val == 0)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};