class Solution {
public:
    bool dfs(int i, vector<vector<int>>& graph, vector<bool>& visited,
             vector<bool>& inRec) {
        visited[i] = true;
        inRec[i] = true;

        for (int& v : graph[i]) {
            if (!visited[v] && dfs(v, graph, visited, inRec)) {
                return true;
            }
            if (inRec[v] == true)
                return true;
        }
        inRec[i] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> inRec(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited, inRec);
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (inRec[i] == false)
                ans.push_back(i);
        }
        return ans;
    }
};