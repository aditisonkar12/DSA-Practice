class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks,
                    int additionalRocks) {
        int n = capacity.size();
        vector<int> required;

        for (int i = 0; i < n; i++) {
            int curr = rocks[i];
            int cap = capacity[i];
            int req = cap - curr;
            required.push_back(req);
        }

        sort(required.begin(), required.end());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (required[i] == 0) {
                cnt++;
            } else if (additionalRocks >= required[i]) {
                additionalRocks -= required[i];
                cnt++;
            } else {
                break;
            }
        }
        return cnt;
    }
};