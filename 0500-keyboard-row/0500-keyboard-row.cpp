class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int n = words.size();
        unordered_map<char, int> mp;
        vector<string> ans;
        string r1 = "qwertyuiop";
        string r2 = "asdfghjkl";
        string r3 = "zxcvbnm";

        for (char ch : r1)
            mp[ch] = 1;

        for (char ch : r2)
            mp[ch] = 2;

        for (char ch : r3)
            mp[ch] = 3;

        for (string word : words) {
            int row = mp[tolower(word[0])];
            bool ok = true;

            for (char ch : word) {
                if (mp[tolower(ch)] != row) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                ans.push_back(word);
        }
        return ans;
    }
};