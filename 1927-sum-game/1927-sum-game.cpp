class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int diff = 0;
        int ans = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                ans++;
            else
                diff += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                ans--;
            else
                diff -= num[i] - '0';
        }

        if (ans == 0)
            return diff != 0;

        if (ans % 2 != 0)
            return true;

        return diff * 2 != -9 * ans;
    }
};