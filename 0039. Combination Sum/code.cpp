class Solution {
public:
    void combinations(int ind, int target, vector<int>& candidates,
                      vector<vector<int>>& ans, vector<int>& res) {
        if (ind == candidates.size()) {
            if (target == 0) {
                ans.push_back(res);
            }
            return;
        }

        if (candidates[ind] <= target) {
            res.push_back(candidates[ind]);
            combinations(ind, target - candidates[ind], candidates, ans, res);
            res.pop_back();
        }
        combinations(ind + 1, target, candidates, ans, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        combinations(0, target, candidates, ans, res);
        return ans;
    }
};