class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){ //i starts from 1 as if it was 0 first loop would be -1 which is not possible so for the last element we hve written another if statement
                count++;
            }
        }
        if(nums[n-1]>nums[0]){ //for last and first element comparision
            count++;
        }  
        return count<=1;
    }
};