class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        int n = recipes.size();
        unordered_set<string> st(begin(supplies), end(supplies));

        // build graph
        unordered_map<string, vector<int>> adj;
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (string& edge : ingredients[i]) {
                if (!st.count(edge)) {
                    adj[edge].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<string> ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(recipes[u]);

            for (int& v : adj[recipes[u]]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        return ans;
    }
};