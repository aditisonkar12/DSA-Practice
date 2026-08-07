class Solution {
public:
    int n;
    int m;
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return 1;
        if (grid[i][j] == 0)
            return 1;
        if (grid[i][j] == 2)
            return 0;

        grid[i][j] = 2;

        return dfs(i + 1, j, grid) + dfs(i - 1, j, grid) + dfs(i, j + 1, grid) +
               dfs(i, j - 1, grid);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    return dfs(i, j, grid);
                }
            }
        }
        return 0;
    }
};