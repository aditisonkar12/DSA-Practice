class Solution {
public:
    bool bfs(vector<vector<int>>& graph, int currNode, vector<int>& color,
             int currColor) {
        queue<int> q;
        q.push(currNode);
        color[currNode] = currColor;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int& v : graph[u]) {
                if (color[u] == color[v])
                    return false;
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (bfs(graph, i, color, 1) == false)
                    return false;
            }
        }
        return true;
    }
};