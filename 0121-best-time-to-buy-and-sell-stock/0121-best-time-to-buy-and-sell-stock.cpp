class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int i = 0, j = 1;
        int ans = 0;

        while (j < n) {
            if (prices[j] > prices[i]) {
                int curr = prices[j] - prices[i];
                ans = max(ans, curr);
            } else {
                i = j;
            }
            j++;
        }
        return ans;
    }
};