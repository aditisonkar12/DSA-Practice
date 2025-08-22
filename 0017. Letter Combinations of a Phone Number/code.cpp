class Solution {
public:
    unordered_map<char, string> keys = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    void backtrack(int ind, string& digits, string& res, vector<string>& ans) {
        if (ind == digits.size()) {
            ans.push_back(res);
            return;
        }

        for (char c : keys[digits[ind]]) {
            res.push_back(c);
            backtrack(ind + 1, digits, res, ans);
            res.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        string res;
        vector<string> ans;
        backtrack(0, digits, res, ans);
        return ans;
    }
};