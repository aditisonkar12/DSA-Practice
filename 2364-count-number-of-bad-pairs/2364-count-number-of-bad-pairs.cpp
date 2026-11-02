class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long goodcount = 0;
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            goodcount += freq[key];
            freq[key]++;
        }

        long long totalcount = (1LL * n * (n - 1)) / 2;
        return totalcount - goodcount;
    }
};