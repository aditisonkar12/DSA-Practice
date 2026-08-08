class Solution {
public:
    int largestInteger(int num) {
        vector<int> digits;
        int temp = num;
        if (temp == 0)
            digits.push_back(0);

        while (temp > 0) {
            digits.push_back(temp % 10);
            temp /= 10;
        }

        reverse(digits.begin(), digits.end());
        vector<int> even, odd;

        for (int d : digits) {
            if (d % 2 == 0)
                even.push_back(d);
            else
                odd.push_back(d);
        }

        sort(even.begin(), even.end(), greater<int>());
        sort(odd.begin(), odd.end(), greater<int>());

        int e = 0, o = 0;
        int ans = 0;
        for (int d : digits) {
            if (d % 2 == 0)
                ans = ans * 10 + even[e++];
            else
                ans = ans * 10 + odd[o++];
        }
        return ans;
    }
};