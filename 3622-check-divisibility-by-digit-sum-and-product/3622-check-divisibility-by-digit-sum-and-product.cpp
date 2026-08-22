class Solution {
public:
    vector<int> digit(int num) {
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        return digits;
    }

    bool checkDivisibility(int n) {
        vector<int> dig = digit(n);
        int sum = 0;
        int prod = 1;

        for (int x : dig) {
            sum += x;
            prod *= x;
        }
        return n % (sum + prod) == 0;
    }
};