class Solution {
public:
    int solve(int x, int y, vector<int>& nums) {
        if (x > y)
            return 0;
        if (x == y)
            return nums[x];

        int i = nums[x] + min(solve(x + 2, y, nums), solve(x + 1, y - 1, nums));
        int j = nums[y] + min(solve(x, y - 2, nums), solve(x + 1, y - 1, nums));

        return max(i, j);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;

        int p1 = solve(0, n - 1, nums);
        int p2 = totalSum - p1;
        return p1 >= p2;
    }
};