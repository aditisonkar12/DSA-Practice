class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int m = banned.size();
        vector<int> remaining;
        for (int i = 1; i <= n; i++) {
            if (find(banned.begin(), banned.end(), i) == banned.end())
                remaining.push_back(i);
        }

        int prefSum = 0;
        int cnt = 0;
        for (int i = 0; i < remaining.size(); i++) {
            if (prefSum + remaining[i] <= maxSum) {
                prefSum += remaining[i];
                cnt++;
            } else {
                break;
            }
        }
        return cnt;
    }
};