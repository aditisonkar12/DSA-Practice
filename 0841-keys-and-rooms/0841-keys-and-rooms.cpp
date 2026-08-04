class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int src, vector<bool>& visited) {
        visited[src] = true;
        for (int& v : rooms[src]) {
            if (!visited[v])
                dfs(rooms, v, visited);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, 0);
        // 0 is the source here from where we start our traversal
        dfs(rooms, 0, visited);
        for (bool u : visited) {
            if (u == false) //checks if any of the rooms is not visited
                return false;
        }
        return true;
    }
};