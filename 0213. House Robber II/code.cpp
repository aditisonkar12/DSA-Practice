class Solution {
public:
    int houserob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;

        for (int ind = 1; ind < n; ind++) {
            int pick = nums[ind];
            if (ind > 1)
                pick += prev2;
            int notPick = 0 + prev;

            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp1, temp2;

        if (n == 1)
            return nums[0];

        for (int i = 0; i < n; i++) {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        int ans1 = houserob(temp1);
        int ans2 = houserob(temp2);
        return max(ans1, ans2);
    }
};