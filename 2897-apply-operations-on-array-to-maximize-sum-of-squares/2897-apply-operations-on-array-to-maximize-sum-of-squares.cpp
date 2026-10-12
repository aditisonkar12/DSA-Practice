class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        vector<int> cnt(31, 0);

        for (int x : nums) {
            for (int i = 0; i < 31; i++) {
                if (x & (1 << i))
                    cnt[i]++;
            }
        }

        long long ans = 0;
        for (int i = 0; i < k; i++) {
            long long temp = 0;
            for (int j = 0; j < 31; j++) {
                if (cnt[j] > 0) {
                    temp |= (1LL << j);
                    cnt[j]--;
                }
            }
            ans = (ans + temp * temp) % mod;
        }
        return ans;
    }
};