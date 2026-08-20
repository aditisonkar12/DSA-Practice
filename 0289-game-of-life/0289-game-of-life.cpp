class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> ans = board;

        int delrow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int delcol[] = {0, 1, 1, 1, 0, -1, -1, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cnt = 0;
                for (int v = 0; v < 8; v++) {
                    int nrow = i + delrow[v];
                    int ncol = j + delcol[v];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                        cnt += board[nrow][ncol];
                }
                if (cnt < 2 || cnt > 3) {
                    ans[i][j] = 0;
                } else {
                    if (cnt == 3)
                        ans[i][j] = 1;
                }
            }
        }
        board = ans;
    }
};