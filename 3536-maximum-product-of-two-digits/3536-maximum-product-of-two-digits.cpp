class Solution {
public:
    int maxProduct(int n) {
        if (n < 10)
            return n;

        vector<int> digits;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }

        int m = digits.size();
        sort(digits.begin(), digits.end());
        return (digits[m - 1] * digits[m - 2]);
    }
};