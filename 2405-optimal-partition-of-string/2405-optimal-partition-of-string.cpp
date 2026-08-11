class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        vector<int> lastSeen(26, -1);
        int cnt = 0;
        int currSubstr = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (lastSeen[ch - 'a'] >= currSubstr) {
                cnt++;
                currSubstr = i;
            }
            lastSeen[ch - 'a'] = i;
        }
        return cnt + 1;
        // cnt only stores prev unique substrings and end without
        // checking the last one if index reached out of boundary
        // means last remaining substr was also unique hence we do +1
    }
};