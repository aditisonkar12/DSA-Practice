class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //here set only stores unique elements, so we return true as soon as we find a duplicate while traversing only once
        unordered_set<int> st;
        for (int i : nums) {
            if (st.find(i) != st.end()) {
                return true;
            }
            st.insert(i);
        }
        return false;

        // here we check when freq becomes greater than 1
        // unordered_map<int, int> freq;
        // for (int i : nums) {
        //     freq[i]++;
        // }

        // bool ans = false;
        // for (auto it : freq) {
        //     if (it.second > 1)
        //         ans = true;
        // }
        // return ans;
    }
};