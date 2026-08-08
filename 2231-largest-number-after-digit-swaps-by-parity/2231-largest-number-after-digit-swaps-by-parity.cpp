class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        priority_queue<int> even;
        priority_queue<int> odd;

        for (char ch : s) { // Store digits in heaps
            int d = ch - '0';
            if (d % 2 == 0)
                even.push(d);
            else
                odd.push(d);
        }

        int ans = 0;
        for (char ch : s) { // Rebuild number
            if ((ch - '0') % 2 == 0) {
                ans = ans * 10 + even.top();
                even.pop();
            } else {
                ans = ans * 10 + odd.top();
                odd.pop();
            }
        }
        return ans;
    }
};