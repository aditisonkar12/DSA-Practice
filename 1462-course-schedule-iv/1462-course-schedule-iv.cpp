class Solution {
public:
    bool dfs(int src, int dest, unordered_map<int, vector<int>>& adj,
             vector<bool>& visited) {
        visited[src] = true;
        if (src == dest)
            return true;

        bool ans = false;
        for (auto& node : adj[src]) {
            if (!visited[node]) {
                ans = ans || dfs(node, dest, adj, visited);
            }
        }
        return ans;
    }

    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        int q = queries.size();
        vector<bool> result(q);
        for (int i = 0; i < q; i++) {
            vector<bool> visited(numCourses, false);
            int src = queries[i][0];
            int dest = queries[i][1];
            result[i] = dfs(src, dest, adj, visited);
        }
        return result;
    }
};