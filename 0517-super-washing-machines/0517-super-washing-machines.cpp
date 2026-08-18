class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int total = 0;
        for (int x : machines) {
            total += x;
        }

        if (total % n != 0)
            return -1;

        int equal = total / n;
        int remaining = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int diff = machines[i] - equal;
            remaining += diff;
            ans = max(ans, abs(remaining));
            ans = max(ans, diff);
        }
        return ans;
    }
};