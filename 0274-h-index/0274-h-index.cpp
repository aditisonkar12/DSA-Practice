class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> cnt(n + 1, 0);

        for (int x : citations) {
            cnt[min(x, n)]++;
        }

        int papers = 0;
        for (int h = n; h >= 0; h--) {
            papers += cnt[h];
            if (papers >= h)
                return h;
        }
        return 0;
    }
};