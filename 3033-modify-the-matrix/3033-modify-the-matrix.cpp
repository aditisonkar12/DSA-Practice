class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> answer = matrix;

        for (int j = 0; j < m; j++) {
            int maxi = 0;
            for (int i = 0; i < n; i++) {
                maxi = max(maxi, matrix[i][j]);
            }
            for (int i = 0; i < n; i++) {
                if (answer[i][j] == -1)
                    answer[i][j] = maxi;
            }
        }
        return answer;
    }
};