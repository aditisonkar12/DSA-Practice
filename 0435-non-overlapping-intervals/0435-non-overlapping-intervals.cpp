class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[1] < b[1])
            return true;
        return false;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);

        int ans = 1;
        int prev = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= prev) {
                ans++;
                prev = intervals[i][1];
            }
        }
        return n - ans;
    }
};