class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans = "";
        int cnt = 0;
        for (char c : s) {
            if (c == ' ') {
                cnt++;
                if (cnt == k)
                    break;
                ans.push_back(' ');
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};