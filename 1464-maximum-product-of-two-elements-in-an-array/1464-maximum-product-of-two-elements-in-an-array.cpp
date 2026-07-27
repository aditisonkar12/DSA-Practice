class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        priority_queue<int> pq;

        for(int num: nums){
            pq.push(num);
        }
        
        int top=pq.top();
        pq.pop();
        int next=pq.top();
        pq.pop();
        return (top-1)*(next-1);
    }
};