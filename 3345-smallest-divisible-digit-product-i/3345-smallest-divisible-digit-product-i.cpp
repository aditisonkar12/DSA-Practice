class Solution {
public:
    vector<int> dig(int num, vector<int>& digits) {
        if (num == 0)
            digits.push_back(0);
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        return digits;
    }

    int smallestNumber(int n, int t) {
        int ans = n;
        while (true) {
            vector<int> digits;
            int prod = 1;
            dig(ans, digits);
            for (int x : digits) {
                prod *= x;
            }
            if (prod % t == 0)
                break;
            else
                ans++;
        }
        return ans;
    }
};