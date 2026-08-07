class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        // for (auto& it : freq) {
        //     pq.push({it.second, it.first});
        // }
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int x : mat[i])
                cnt += x;

            pq.push({cnt, i});
        }

        vector<int> ans;
        while (k != 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};