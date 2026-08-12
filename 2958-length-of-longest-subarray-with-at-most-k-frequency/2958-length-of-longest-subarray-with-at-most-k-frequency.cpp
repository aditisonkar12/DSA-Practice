class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int cnt = 0;
        int maxi = 0;
        int extra = 0;

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            // int val = freq[nums[i]];
            // if (val <= k) {
            //     cnt += 1;
            //     maxi = max(maxi, cnt);
            // } else {
            while (freq[nums[i]] > k) {
                freq[nums[extra]]--;
                extra++;
                cnt--;
            }
            cnt++;
            maxi = max(maxi, cnt);
            // }
        }
        return maxi;
    }
};