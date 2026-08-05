class Solution {
public:
    bool hasCycle;
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited,
             vector<bool>& inRec, stack<int>& st) {
        visited[i] = true;
        inRec[i] = true;

        for (int& v : adj[i]) {
            if (inRec[v] == true) {
                hasCycle = true;
                return;
            }
            if (!visited[v]) {
                dfs(v, adj, visited, inRec, st);
            }
        }
        st.push(i);
        inRec[i] = false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<bool> visited(n, false);
        vector<bool> inRec(n, false);
        stack<int> st;
        vector<vector<int>> adj(n);
        hasCycle = false;
        for (auto& it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, inRec, st);
            }
        }
        if (hasCycle == true)
            return {};

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};