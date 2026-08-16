class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost,
                          int crossCost) {
        long long a = 0;
        long long b = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                if (s[i] == '0')
                    a++;
                else
                    b++;
            }
        }

        long long ans = 0;
        long long temp = min(a, b);
        ans += temp * min(1LL * swapCost, 2LL * flipCost);

        a -= temp;
        b -= temp;
        long long remaining = a + b;
        ans +=
            (remaining / 2) * min(1LL * crossCost + swapCost, 2LL * flipCost);

        if (remaining % 2)
            ans += flipCost;

        return ans;
    }
};