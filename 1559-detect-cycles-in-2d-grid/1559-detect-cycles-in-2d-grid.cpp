class Solution {
public:
    int n;
    int m;
    bool dfs(int i, int j, int pi, int pj, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {
        if (visited[i][j] == true)
            return true;
        visited[i][j] = true;

        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int k = 0; k < 4; k++) {
            int nrow = i + delrow[k];
            int ncol = j + delcol[k];

            if (nrow <0 || nrow >= n || ncol < 0 || ncol >= m)
                continue;
            if (grid[nrow][ncol] != grid[i][j])
                continue;
            if (nrow == pi && ncol == pj)
                continue;
            if (dfs(nrow, ncol, i, j, grid, visited))
                return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
    n = grid.size();
    m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && dfs(i, j, i, j, grid, visited))
                return true;
        }
    }
    return false;
}
}
;