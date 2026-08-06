class Solution {
public:
    int countDigitOne(int n) {
        long long ans = 0;
        for (long long factor = 1; factor <= n; factor *= 10) {
            long long left = n / (factor * 10);
            long long curr = (n / factor) % 10;
            long long right = n % factor;

            if (curr == 0) {
                ans += left * factor;
            } else if (curr == 1) {
                ans += left * factor + right + 1;
            } else {
                ans += (left + 1) * factor;
            }
        }
        return ans;
    }
};