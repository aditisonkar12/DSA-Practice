class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long ans = LLONG_MAX;
        vector<long long> candidates = {0LL, min(need1, need2),
                                        max(need1, need2)};
        for (long long i : candidates) {
            long long cost = i * costBoth +
                             max(0LL, (long long)need1 - i) * cost1 +
                             max(0LL, (long long)need2 - i) * cost2;

            ans = min(ans, cost);
        }
        return ans;
    }
};