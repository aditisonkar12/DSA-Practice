class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = prices[0];
        int maxi = 0;
        for (int i = 1; i < n; i++) {
            int profit = prices[i] - minPrice;
            maxi = max(maxi, profit);
            minPrice = min(minPrice, prices[i]);
        }
        return maxi;
    }
};