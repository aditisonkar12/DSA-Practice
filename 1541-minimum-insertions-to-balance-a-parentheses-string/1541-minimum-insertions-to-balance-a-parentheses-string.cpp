class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        stack<char> st;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else if (s[i] == ')' && i + 1 < n && s[i + 1] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    cnt++;
                }
                i++;
            } else {
                if (!st.empty()) {
                    st.pop();
                    cnt++;
                } else {
                    cnt += 2;
                }
            }
        }
        cnt += 2 * st.size();
        return cnt;
    }
};