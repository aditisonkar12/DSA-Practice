class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = grid[i][j];
                freq[x]++;
            }
        }

        int missing = 0;
        int rep = 0;
        for (auto it : freq) {
            if (it.second > 1) {
                rep = it.first;
                break;
            }
        }

        for (int i = 1; i <= n * m; i++) {
            if (freq.find(i) == freq.end()) {
                missing = i;
                break;
            }
        }
        return {rep, missing};
    }
};