class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({digitSum(nums[i]), nums[i]});
        }

        sort(v.begin(), v.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[v[i].second] = i;
        }

        int ans = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++) {
            if (vis[i] || mp[nums[i]] == i)
                continue;

            int j = i, cycle = 0;
            while (!vis[j]) {
                vis[j] = true;
                j = mp[nums[j]];
                cycle++;
            }
            if (cycle > 1)
                ans += cycle - 1;
        }
        return ans;
    }
};