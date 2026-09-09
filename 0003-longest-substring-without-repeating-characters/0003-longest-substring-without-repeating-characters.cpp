class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        // unordered_map<char, int> mp;
        // for (char c = 'a'; c <= 'z'; c++) {
        //     mp[c] = -1;
        // }
        // mp[' '] = -1;
        // int l = 0, r = 0, maxLen = 0;
        // while (r < n) {
        //     if (mp[s[r]] != -1) {
        //         if (mp[s[r]] >= l) {
        //             l = mp[s[r]] + 1;
        //         }
        //     }
        //     int len = r - l + 1;
        //     maxLen = max(len, maxLen);
        //     mp[s[r]] = r;
        //     r++;
        // }
        // return maxLen;
        unordered_map<char, int> mp;
        int l = 0, maxLen = 0;
        for (int r = 0; r < n; r++) {

            if (mp.find(s[r]) != mp.end() && mp[s[r]] >= l) {
                l = mp[s[r]] + 1;
            }

            mp[s[r]] = r;
            int len = r - l + 1;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};