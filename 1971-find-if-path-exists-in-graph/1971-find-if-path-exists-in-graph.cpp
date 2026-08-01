class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        unordered_map<int, vector<int>> adjList;
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source]=true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            if (node == destination)
                return true;

            for (auto& ni : adjList[node]) {
                if (!visited[ni]) {
                    q.push(ni);
                    visited[ni] = true;
                }
            }
        }
        return false;
    }
};