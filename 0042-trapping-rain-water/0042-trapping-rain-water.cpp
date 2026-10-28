class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int waterTrapped = 0;
        int leftMax = 0, rightMax = 0;

        while (l < r) {
            if (height[l] <= height[r]) {
                if (leftMax < height[l]) {
                    leftMax = height[l];
                } else {
                    waterTrapped += leftMax - height[l];
                }
                l++;
            } else {
                if (rightMax < height[r]) {
                    rightMax = height[r];
                } else {
                    waterTrapped += rightMax - height[r];
                }
                r--;
            }
        }
        return waterTrapped;
    }
};