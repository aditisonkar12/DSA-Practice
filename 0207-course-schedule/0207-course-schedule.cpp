class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto& e : prerequisites) {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
            indegree[u]++; // arrows goes from v->u so we increase indgeree of
                           // u
        }

        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                cnt++;
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int& v : adj[u]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    q.push(v);
                    cnt++;
                }
            }
        }
        if (cnt == n)
            return true;
        return false;
    }
};