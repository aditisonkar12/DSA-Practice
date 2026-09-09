class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int x : nums) {
            ans ^= x; 
        }
        return ans;
        // unordered_set<int> st;
        // int n = nums.size();
        // int ans = 0;

        // for (int num : nums) {
        //     if (st.find(num) != st.end())
        //         st.erase(num);
        //     else
        //         st.insert(num);
        // }
        // return *st.begin();
    }
};