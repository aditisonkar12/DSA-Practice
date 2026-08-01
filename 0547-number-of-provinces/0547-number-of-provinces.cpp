class Solution {
public:
    int n;
    void dfs(int i, unordered_map<int, vector<int>>& adj,
             vector<bool>& visited) {
        visited[i] = true;
        for (int& j : adj[i]) {
            if (!visited[j]) {
                dfs(j, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] == false) {
                dfs(i, adj, visited);
                cnt++;
            }
        }
        return cnt;
    }
};