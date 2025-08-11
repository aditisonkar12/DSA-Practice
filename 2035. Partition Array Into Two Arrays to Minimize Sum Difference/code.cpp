class Solution {
public:
    int minimumDifference(vector<int>& arr) {
int n = nums.size() / 2;
vector<int> left(nums.begin(), nums.begin() + n);
vector<int> right(nums.begin() + n, nums.end());

auto getAllSubsetSums = [&](vector<int>& arr) {
    int sz = arr.size();
    vector<vector<int>> subsetSums(sz + 1);
    for (int mask = 0; mask < (1 << sz); ++mask) {
        int sum = 0, cnt = 0;
        for (int i = 0; i < sz; ++i) {
            if (mask & (1 << i)) {
                sum += arr[i];
                ++cnt;
            }
        }
        subsetSums[cnt].push_back(sum);
    }
    return subsetSums;
};

auto leftSums = getAllSubsetSums(left);
auto rightSums = getAllSubsetSums(right);

int total = accumulate(nums.begin(), nums.end(), 0);
int ans = INT_MAX;

for (int k = 0; k <= n; ++k) {
    auto& L = leftSums[k];
    auto& R = rightSums[n - k];
    sort(R.begin(), R.end());

    for (int a : L) {
        int target = total / 2 - a;
        auto it = lower_bound(R.begin(), R.end(), target);
        if (it != R.end()) {
            int sum1 = a + *it;
            int sum2 = total - sum1;
            ans = min(ans, abs(sum1 - sum2));
        }
        if (it != R.begin()) {
            --it;
            int sum1 = a + *it;
            int sum2 = total - sum1;
            ans = min(ans, abs(sum1 - sum2));
        }
    }
}
return ans;
    }
};