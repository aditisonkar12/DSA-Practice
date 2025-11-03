class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long total = 0;
        int left = 0, maxi = 0;

        for (int right = 0; right < n; right++) {
            total += nums[right];

            while ((long long)nums[right] * (right - left + 1) - total > k) {
                total -= nums[left];
                left++;
            }

            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};