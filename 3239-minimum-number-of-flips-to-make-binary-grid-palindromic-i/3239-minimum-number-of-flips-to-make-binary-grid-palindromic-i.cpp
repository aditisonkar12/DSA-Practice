class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int row = 0, col = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                if (grid[i][j] != grid[i][m - 1 - j]) {
                    row++;
                }
            }
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n / 2; i++) {
                if (grid[i][j] != grid[n - 1 - i][j]) {
                    col++;
                }
            }
        }
        return min(row, col);
    }
};