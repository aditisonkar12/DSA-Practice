class Solution {
public:
    int n;
    void dfs(int i, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[i] = true;
        for (int col = 0; col < n; col++) {
            if (!visited[col] && isConnected[i][col] == 1) {
                dfs(col, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool> visited(n, false);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                dfs(i, isConnected, visited);
                cnt++;
            }
        }
        return cnt;
    }
};