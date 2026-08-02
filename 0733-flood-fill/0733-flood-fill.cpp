class Solution {
public:
    int n;
    int m;
    void dfs(int i, int j, int sr, int sc, int icolor,
             vector<vector<bool>>& visited, vector<vector<int>>& ans,
             vector<vector<int>>& image, int color) {
        int delrow[] = {1, 0, -1, 0};
        int delcol[] = {0, -1, 0, 1};
        ans[i][j] = color;
        visited[i][j] = true;
        for (int v = 0; v < 4; v++) {
            int nrow = i + delrow[v];
            int ncol = j + delcol[v];
            if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m)
                continue;

            if (visited[nrow][ncol])
                continue;

            if (image[nrow][ncol] != icolor)
                continue;

            dfs(nrow, ncol, sr, sc, icolor, visited, ans, image, color);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        n = image.size();
        m = image[0].size();

        vector<vector<int>> ans = image;
        int icolor = image[sr][sc];
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        dfs(sr, sc, sr, sc, icolor, visited, ans, image, color);

        return ans;
    }
};