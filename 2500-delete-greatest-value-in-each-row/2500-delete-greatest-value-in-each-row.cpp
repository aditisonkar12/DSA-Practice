class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<priority_queue<int>> pq(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pq[i].push(grid[i][j]);
            }
        }

        for (int j = 0; j < m; j++) {
            int maxi = 0;
            for (int i = 0; i < n; i++) {
                maxi = max(maxi, pq[i].top());
                pq[i].pop();
            }
            ans += maxi;
        }
        return ans;
    }
};