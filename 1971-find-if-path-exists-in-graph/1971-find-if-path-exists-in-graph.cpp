class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adjList, int source,
             int destination, vector<bool>& visited) {
        if (source == destination)
            return true;

        if (visited[source] == true)
            return false;
        visited[source] = true;

        for (auto& node : adjList[source]) {
            if (dfs(adjList, node, destination, visited) == true)
                return true;
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        unordered_map<int, vector<int>> adjList;
        //building graph
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<bool> visited(n, false);
        return dfs(adjList, source, destination, visited);
    }
};