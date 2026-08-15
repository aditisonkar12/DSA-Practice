class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long currSum1 = 0;
        long long currSum2 = 0;

        long long zero1 = 0;
        long long zero2 = 0;

        for (int& num : nums1) {
            currSum1 += num;
            if (num == 0) {
                zero1++;
                currSum1++;
            }
        }

        for (int& num : nums2) {
            currSum2 += num;
            if (num == 0) {
                zero2++;
                currSum2++;
            }
        }

        if (currSum1 < currSum2 && zero1 == 0)
            return -1;
        if (currSum2 < currSum1 && zero2 == 0)
            return -1;

        return max(currSum1, currSum2);
    }
};