class Solution {
public:
    int countSegments(string s) {
        int n = s.length();
        if (n == 0)
            return 0;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' '))
                cnt++;
        }
        return cnt;
    }
};