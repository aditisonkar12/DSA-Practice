class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();     //optimal solution
        int i=0;
        for(int j=0;j<n;j++){
            if(nums[j]!=nums[i]){
                nums[i+1]=nums[j];
                i++;
            }
        }
        return (i+1);


        //brute force method
        // set<int> st;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     st.insert(nums[i]);  //inserting elements into the set one by one like in a stack
        // }
        // int index=0;
        // for(auto it:st){
        //     nums[index]=it;
        //     index++;
        // }
        // return index;
    }
};