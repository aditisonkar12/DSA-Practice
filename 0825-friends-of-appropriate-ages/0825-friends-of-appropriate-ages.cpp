class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        sort(ages.begin(), ages.end());
        int left = 0, right = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            while (left < n && ages[left] <= 0.5 * ages[i] + 7)
                left++;

            while (right + 1 < n && ages[right + 1] <= ages[i])
                right++;

            if (right >= left)
                ans += right - left;
        }
        return ans;
        // int cnt = 0;

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (i == j)
        //             continue;
        //         if (ages[j] <= 0.5 * ages[i] + 7)
        //             continue;
        //         if (ages[j] > ages[i])
        //             continue;
        //         if (ages[j] > 100 && ages[i] < 100)
        //             continue;

        //         cnt++;
        //     }
        // }
        // return cnt;
    }
};