class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        int ans1 = 0, ans2 = 0;

        unordered_set<int> st1(nums1.begin(), nums1.end());
        unordered_set<int> st2(nums2.begin(), nums2.end());

        for (int x : nums1) {
            if (st2.count(x))
                ans1++;
        }

        for (int x : nums2) {
            if (st1.count(x))
                ans2++;
        }
        return {ans1, ans2};
    }
};