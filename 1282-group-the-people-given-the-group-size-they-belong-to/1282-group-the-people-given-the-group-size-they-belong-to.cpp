class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            int k = groupSizes[i]; // group size
            mp[k].push_back(i);    // store all indices with group size k

            if (mp[k].size() == k) {
                ans.push_back(mp[k]);
                mp[k].clear();
            }
        }
        return ans;
    }
};