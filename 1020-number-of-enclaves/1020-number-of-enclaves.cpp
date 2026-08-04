class Solution {
public:
    int n;
    int m;

    bool dfs(int i, int j, vector<vector<int>>& grid, int& cells) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        if (grid[i][j] == 0)
            return true;
        if (grid[i][j] == 2)
            return true;

        grid[i][j] = 2;
        cells++;

        bool up = dfs(i, j - 1, grid, cells);
        bool down = dfs(i, j + 1, grid, cells);
        bool right = dfs(i + 1, j, grid, cells);
        bool left = dfs(i - 1, j, grid, cells);

        return up && down && left && right;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int cells = 0;
                    if (dfs(i, j, grid, cells) == true)
                        cnt += cells;
                }
            }
        }
        return cnt;
    }
};