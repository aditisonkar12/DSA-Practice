class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<int> ans;
        for (int num : nums) {
            if (freq[num] > 0) {
                int cnt = min(freq[num], k);
                while (cnt--) {
                    ans.push_back(num);
                }
                freq[num] = 0;
            }
        }
        return ans;
    }
};