class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> indegree(n + 1, 0);

        for (int i = 0; i < n - 1; i++) {
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }
        int maxi = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] > maxi) {
                maxi = indegree[i];
                ans = i;
            }
        }
        return ans;
    }
};