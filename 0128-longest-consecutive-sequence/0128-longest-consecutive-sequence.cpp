class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxi = 0;

        for (int num : s) {
            if (!s.count(num - 1)) {
                int curr = num;
                int len = 1;

                while (s.count(curr + 1)) {
                    curr++;
                    len++;
                }
                maxi = max(maxi, len);
            }
        }
        return maxi;
    }
};