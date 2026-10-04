class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if (n > m)
            return false;

        vector<int> a(26, 0), b(26, 0);
        for (char c : s1)
            a[c - 'a']++;

        int k = s1.size();
        for (int i = 0; i < m; i++) {
            b[s2[i] - 'a']++;

            if (i >= k)
                b[s2[i - k] - 'a']--;

            if (i >= k - 1 && a == b)
                return true;
        }
        return false;
    }
};