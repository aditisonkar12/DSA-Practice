class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int mini = 0;
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        for (auto it : freq) {
            int val = it.second;
            if (val == 1)
                return -1;

            mini += ceil(double(val) / 3);
        }
        return mini;
    }
};