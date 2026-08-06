class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }
        int duplicate=0,missing=0;
        for (int i = 1; i <= n; i++) {
            if (mp[i] == 2)
                duplicate=i;
            if (mp[i] == 0)
                missing=i;
        }
        return {duplicate,missing};
    }
};