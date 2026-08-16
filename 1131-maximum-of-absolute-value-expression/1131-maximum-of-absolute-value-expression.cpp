class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int ans=0;

        for (int mask = 0; mask < 4; mask++) {
            int maxi = INT_MIN;
            int mini = INT_MAX;
            for (int i = 0; i < n; i++) {
                int val1 = arr1[i];
                if (mask & 1)
                    val1 = -val1;

                int val2 = arr2[i];
                if (mask & 2)
                    val2 = -val2;

                int curr = val1 + val2 + i;
                maxi = max(maxi, curr);
                mini = min(mini, curr);
            }
            ans = max(ans, maxi - mini);
        }
        return ans;
    }
};