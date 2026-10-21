class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool up = true, down = true;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1])
                up = false;
            if (nums[i] > nums[i - 1])
                down = false;
        }
        return up || down;
    }
};