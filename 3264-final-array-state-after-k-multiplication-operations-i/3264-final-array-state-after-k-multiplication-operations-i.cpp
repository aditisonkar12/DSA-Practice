class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        vector<int> ans(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        while (k--) {
            int val = pq.top().first;
            int i = pq.top().second;
            pq.pop();

            val *= multiplier;
            pq.push({val, i});
        }

        while (!pq.empty()) {
            int x = pq.top().first;
            int i = pq.top().second;
            pq.pop();
            ans[i] = x;
        }
        return ans;
    }
};