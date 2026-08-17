class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int total = 100;
        int roundedAmount = 0;
        int rem = purchaseAmount % 10;
        if (rem != 0) {
            if (rem >= 5) {
                roundedAmount = purchaseAmount + (10 - purchaseAmount % 10);
            } else {
                roundedAmount = purchaseAmount - rem;
            }
        }
        else{
            roundedAmount = purchaseAmount;
        }
        return total - roundedAmount;
    }
};