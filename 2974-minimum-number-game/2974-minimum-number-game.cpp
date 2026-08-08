class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            pq.push(num);
        }

        while (!pq.empty()) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            arr.push_back(b);
            arr.push_back(a);
        }
        return arr;
    }
};