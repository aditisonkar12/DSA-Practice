class Solution {
public:
    bool checkPossible(string& s, string& t) {
        if (s.size() != t.size() + 1)
            return false;
        int i = 0, j = 0;

        while (i < s.size()) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        if (i == s.size() && j == t.size())
            return true;
        return false;
    }

    static bool comp(const string& s, const string& t) {
        return s.size() < t.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);

        int maxi = 1;
        for (int ind = 0; ind < n; ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (checkPossible(words[ind], words[prev]))
                    dp[ind] = max(dp[ind], 1 + dp[prev]);
            }
            maxi = max(maxi, dp[ind]);
        }
        return maxi;
    }
};