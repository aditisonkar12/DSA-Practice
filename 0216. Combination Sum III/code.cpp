class Solution {
public:
    void combinations(int ind, int k, int n, vector<int>& res,
                      vector<vector<int>>& ans) {
        if (res.size() == k) {
            if (n == 0) {
                ans.push_back(res);
            }
            return;
        }

        for (int i = ind; i <= 9; i++) {
            if (i > n)
                break;
            res.push_back(i);
            combinations(i + 1, k, n - i, res, ans);
            res.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> res;
        vector<vector<int>> ans;
        combinations(1, k, n, res, ans);
        return ans;
    }
};