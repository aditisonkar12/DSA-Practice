class Solution {
public:
    int numDifferentIntegers(string word) {
        vector<string> nums;

        string num = "";
        for (char c : word) {
            if (c >= '0' && c <= '9') {
                num += c;
            } else {
                if (num != "") {
                    nums.push_back(num);
                    num = "";
                }
            }
        }

        if (num != "")
            nums.push_back(num);

        unordered_set<string> st;
        for (string s : nums) {
            int i = 0;
            while (i < s.size() - 1 && s[i] == '0')
                i++;

            s = s.substr(i);
            st.insert(s);
        }
        return st.size();
    }
};