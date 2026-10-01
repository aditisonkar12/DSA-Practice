class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty())
                    return false;
                char ch = st.top();
                st.pop();
                if (!(s[i] == ')' && ch == '(' || s[i] == '}' && ch == '{' ||
                    s[i] == ']' && ch == '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

// unordered_map<char, char> mapping = {{')', '('}, {'}', '{'}, {']', '['}};

// for (char c : s) {
//     if (mapping.count(c)) {
//         if (st.empty() || st.top() != mapping[c])
//             return false;
//         st.pop();
//     } else {
//         st.push(c);
//     }
// }
// return st.empty();