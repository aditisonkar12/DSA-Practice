class Solution {
public:
    void combinations(int ind, int target, vector<int>& candidates,
                      vector<int>& res, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(res);
            return;
        }

        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            res.push_back(candidates[i]);
            combinations(i + 1, target - candidates[i], candidates, res, ans);
            res.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> res;
        vector<vector<int>> ans;
        combinations(0, target, candidates, res, ans);
        return ans;
    }
};