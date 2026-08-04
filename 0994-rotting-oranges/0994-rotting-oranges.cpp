class Solution {
public:
    int n;
    int m;
    int bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid, int& fresh) {
        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, 1, 0, -1};
        int t = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [i, j] = q.front();
                q.pop();

                for (int v = 0; v < 4; v++) {
                    int nrow = i + delrow[v];
                    int ncol = j + delcol[v];

                    if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
                        continue;
                    if (grid[nrow][ncol] != 1)
                        continue;
                    grid[nrow][ncol] = 2;
                    q.push({nrow, ncol});
                    fresh--;
                }
            }
            if (!q.empty())
                t++;
        }
        return t;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    fresh++;
            }
        }
        if (fresh == 0)
            return 0;

        int time = bfs(q, grid, fresh);
        if (fresh == 0)
            return time;
        return -1;
    }
};