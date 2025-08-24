class Solution {
public:
    unordered_map<string, bool> dp;

    bool solve(string& s, int l, int r) {
        string key = to_string(l) + "#" + to_string(r);
        if (dp.count(key))
            return dp[key];

        if (l == r)
            return dp[key] = (s[l] == 't');

        if (s[l] == '!') {
            return dp[key] = !solve(s, l + 2, r - 1);
        } else if (s[l] == '&' || s[l] == '|') {
            bool isAnd = (s[l] == '&');
            bool result = isAnd ? true : false;
            int start = l + 2, bal = 0;

            for (int i = l + 2; i < r; i++) {
                if (s[i] == '(')
                    bal++;
                if (s[i] == ')')
                    bal--;
                if (s[i] == ',' && bal == 0) {
                    bool val = solve(s, start, i - 1);
                    result = isAnd ? (result & val) : (result | val);
                    start = i + 1;
                }
            }
            bool val = solve(s, start, r - 1);
            result = isAnd ? (result & val) : (result | val);

            return dp[key] = result;
        }
        return false;
    }

    bool parseBoolExpr(string expression) {
        int n = expression.size();
        return solve(expression, 0, n - 1);
    }
};