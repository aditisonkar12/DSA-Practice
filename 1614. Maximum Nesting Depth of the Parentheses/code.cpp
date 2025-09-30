class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int n=s.size();
        int maxi=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                cnt++;
                maxi=max(maxi,cnt);
            }
            if(s[i]==')'|| s[i]=='}' || s[i]==']'){
                st.pop();
                cnt--;
            }
        }
        return maxi;
    }
};