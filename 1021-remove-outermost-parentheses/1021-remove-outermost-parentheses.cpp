class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int counter = 0;
        string ans;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (counter != 0) {
                    ans.push_back(s[i]);
                }
                counter++;
            } else if (s[i] == ')') {
                counter--;
                if (counter != 0) {
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;
    }
};