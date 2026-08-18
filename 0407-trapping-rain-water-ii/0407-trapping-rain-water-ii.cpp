class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty())
            return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int waterTrapped = 0;

        for (int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n - 1], {i, n - 1}});
            visited[i][0] = visited[i][n - 1] = true;
        }

        for (int j = 0; j < n; ++j) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m - 1][j], {m - 1, j}});
            visited[0][j] = visited[m - 1][j] = true;
        }

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int height = current.first;
            int x = current.second.first, y = current.second.second;

            for (auto& dir : directions) {
                int newX = x + dir[0], newY = y + dir[1];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                    !visited[newX][newY]) {
                    visited[newX][newY] = true;
                    waterTrapped += max(0, height - heightMap[newX][newY]);
                    pq.push({max(height, heightMap[newX][newY]), {newX, newY}});
                }
            }
        }
        return waterTrapped;
    }
};