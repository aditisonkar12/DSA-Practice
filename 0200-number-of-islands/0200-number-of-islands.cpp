class Solution {
public:
    int n;
    int m;
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int v = 0; v < 4; v++) {
            int nrow = i + delrow[v];
            int ncol = j + delcol[v];
            if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m ||
                grid[nrow][ncol] == '0')
                continue;
            if (grid[nrow][ncol] == 'v')
                continue;

            grid[nrow][ncol] = 'v';
            dfs(nrow, ncol, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};