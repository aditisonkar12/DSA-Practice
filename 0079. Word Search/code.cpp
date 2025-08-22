class Solution {
public:
    int n, m;

    bool dfs(int row, int col, int ind, vector<vector<char>>& board,
             string& word, vector<vector<bool>>& visited) {
        if (ind == word.size())
            return true;

        if (row < 0 || col < 0 || row >= n || col >= m)
            return false;
        if (visited[row][col] || board[row][col] != word[ind])
            return false;

        visited[row][col] = true;

        bool found = dfs(row + 1, col, ind + 1, board, word, visited) ||
                     dfs(row - 1, col, ind + 1, board, word, visited) ||
                     dfs(row, col + 1, ind + 1, board, word, visited) ||
                     dfs(row, col - 1, ind + 1, board, word, visited);

        visited[row][col] = false;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dfs(i, j, 0, board, word, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};