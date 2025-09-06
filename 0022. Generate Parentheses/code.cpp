class Solution {
public:
    void backtrack(int open, int close, string& res, vector<string>& ans) {
        if (open == 0 && close == 0) {
            ans.push_back(res);
            return;
        }

        if (open > 0) {
            res.push_back('(');
            backtrack(open - 1, close, res, ans);
            res.pop_back();
        }

        if (close > open) {
            res.push_back(')');
            backtrack(open, close - 1, res, ans);
            res.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string res;
        backtrack(n, n, res, ans);
        return ans;
    }
};