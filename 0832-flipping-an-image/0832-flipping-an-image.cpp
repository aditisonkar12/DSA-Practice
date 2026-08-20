class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            vector<int> temp = image[i];
            reverse(temp.begin(), temp.end());
            for (int j = 0; j < m; j++) {
                temp[j] = 1 - temp[j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};