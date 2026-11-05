class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for (int x : arr1) {
            bool check = true;
            for (int y : arr2) {
                if (abs(x - y) <= d) {
                    check = false;
                    break;
                }
            }
            if (check)
                ans++;
        }
        return ans;
    }
};