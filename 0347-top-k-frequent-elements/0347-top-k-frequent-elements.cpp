class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for (auto it : freq) {
            int num = it.first;
            int val = it.second;
            pq.push({val, num}); //push according to the higher freq
        }

        while (k != 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};