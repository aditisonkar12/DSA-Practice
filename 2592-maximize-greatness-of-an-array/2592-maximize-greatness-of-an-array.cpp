class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 0;
        int ans = 0;

        while (j < n) {
            if (nums[j] > nums[i]) {
                i++;
                ans++;
            }
            j++;
        }
        return ans;
    }
};