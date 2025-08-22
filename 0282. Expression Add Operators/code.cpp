class Solution {
public:
    vector<string> ans;

    void backtrack(int ind, long long sum, long long product, string& num,
                   int target, string res) {
        if (ind == num.size()) {
            if (sum == target)
                ans.push_back(res);
            return;
        }

        for (int i = ind; i < num.size(); i++) {
            if (i != ind && num[ind] == '0')
                break;
            string curStr = num.substr(ind, i - ind + 1);
            long cur = stol(curStr);

            if (ind == 0) {
                backtrack(i + 1, cur, cur, num, target, curStr);
            } else {
                backtrack(i + 1, sum + cur, cur, num, target,
                          res + "+" + curStr);
                backtrack(i + 1, sum - cur, -cur, num, target,
                          res + "-" + curStr);
                backtrack(i + 1, sum - product + product * cur, product * cur,
                          num, target, res + "*" + curStr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        int n = num.length();
        ans.clear();
        backtrack(0, 0, 0, num, target, "");
        return ans;
    }
};
