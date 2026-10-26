class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> freq;

        for(int num:nums){
            freq[num]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto it: freq){
            int num=it.first;
            int f=it.second;
            pq.push({f,num});
        }

        vector<int> ans;
        while(k!=0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};