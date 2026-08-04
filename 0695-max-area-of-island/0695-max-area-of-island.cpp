class Solution {
public:
    int n;
    int m;
    int dfs(int i, int j, vector<vector<int>>& grid, int& cnt) {
        grid[i][j]=0;
        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int v = 0; v < 4; v++) {
            int nrow = i + delrow[v];
            int ncol = j + delcol[v];

            if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
                continue;
            if (grid[nrow][ncol] == 0)
                continue;
                
            grid[nrow][ncol] = 0;
            cnt++;
            dfs(nrow, ncol, grid, cnt);
        }
        return cnt;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 1;
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, cnt);
                    maxArea = max(maxArea, cnt);
                }
            }
        }
        return maxArea;
    }
};