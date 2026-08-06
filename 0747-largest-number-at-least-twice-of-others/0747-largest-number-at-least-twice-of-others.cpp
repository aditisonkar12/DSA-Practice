class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = nums[i];
        }

        sort(temp.begin(), temp.end());
        int maxi = temp[n - 1];

        for (int i = 0; i < n; i++) {
            if (nums[i] == maxi)
                continue;
            if (maxi < 2 * nums[i])
                return -1;
        }
        auto it = find(nums.begin(), nums.end(), maxi);
        return it - nums.begin();
    }
};