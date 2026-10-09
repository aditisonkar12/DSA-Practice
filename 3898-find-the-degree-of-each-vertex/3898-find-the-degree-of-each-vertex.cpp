class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> adj(n);
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            ans[i] = adj[i].size();
        }
        return ans;
    }
};