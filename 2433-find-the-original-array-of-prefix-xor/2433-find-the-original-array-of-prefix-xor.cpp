class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> ans;
        int prev = pref[0];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                ans.push_back(pref[i]);
            } else {
                prev = pref[i] ^ pref[i - 1];
                ans.push_back(prev);
            }
        }
        return ans;
    }
};