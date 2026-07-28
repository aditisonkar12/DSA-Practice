class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.size();
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]].push_back(i);
        }

        int cnt = 0;
        for (string word : words) {
            int prev = -1;
            bool ans = true;
            for (char ch : word) {
                auto& vis = mp[ch];
                auto it = upper_bound(vis.begin(), vis.end(), prev);

                if (it == vis.end()) {
                    ans = false;
                    break;
                }
                prev = *it;
            }
            if (ans)
                cnt++;
        }
        return cnt;
    }
};