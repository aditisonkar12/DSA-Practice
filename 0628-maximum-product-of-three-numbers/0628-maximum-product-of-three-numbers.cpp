class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if (n == 1)
            return nums[0];
        if (n == 2)
            return nums[0] * nums[1];
            
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3],
                   nums[0] * nums[1] * nums[n - 1]);
    }
};