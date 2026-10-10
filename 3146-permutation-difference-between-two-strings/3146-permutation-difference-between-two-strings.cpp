class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int n = s.length();
        int diff = 0;
        for (int i = 0; i < n; i++) {
            int j = 0;
            while (s[i] != t[j]) {
                j++;
            }
            diff = diff + (abs(i - j));
        }
        return diff;
    }
};