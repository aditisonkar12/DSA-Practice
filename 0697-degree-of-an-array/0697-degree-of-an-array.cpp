class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> cnt, start, end;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            if (start.find(val) == start.end())
                start[val] = i;

            cnt[val]++;
            end[val] = i;
            maxi = max(maxi, cnt[val]);
        }

        int ans = nums.size();
        for (auto it : cnt) {
            int val = it.first;
            if (it.second == maxi) {
                ans = min(ans, end[val] - start[val] + 1);
            }
        }
        return ans;
    }
};