class Solution {
public:
    int n;
    int m;
    bool dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        if (grid[i][j] == 1)
            return true;
        grid[i][j] = 1;

        bool up = dfs(i, j - 1, grid);
        bool down = dfs(i, j + 1, grid);
        bool right = dfs(i + 1, j, grid);
        bool left = dfs(i - 1, j, grid);

        return up && down && left && right;
        // int delrow[] = {1, 0, -1, 0};
        // int delcol[] = {0, 1, 0, -1};
        // bool closed = true;
        // for (int v = 0; v < 4; v++) {
        //     int nrow = i + delrow[v];
        //     int ncol = j + delcol[v];

        //     if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
        //         return false;
        //     if (grid[nrow][ncol] == 1)
        //         continue;

        //     // grid[nrow][ncol] = 1;
        //     closed = dfs(nrow, ncol, grid) && closed;
        // }
        // return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(i, j, grid) == true)
                        ans++;
                }
            }
        }
        return ans;
    }
};