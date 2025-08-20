class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int drow = row;
        int dcol = col;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        row = drow;
        col = dcol;
        while (col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        row = drow;
        col = dcol;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        return true;
    }

    void comb(int col, vector<string>& board, vector<vector<string>>& ans,
              int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board,
                       n)) { // to check if it is safe to place a queen here
                board[row][col] = 'Q';
                comb(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.'); // declaring empty string of size n
        for (int i = 0; i < n; i++) {
            board[i] = s; // placing empty strings of size n in vector board
        }
        comb(0, board, ans, n);
        return ans;
    }
};