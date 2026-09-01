class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;

        unordered_map<char,char> s1, t1;
        for(int i=0;i<n;i++){
            char c1=s[i],c2=t[i];

            if(s1.count(c1) && s1[c1]!=c2) return false;
            if(t1.count(c2) && t1[c2]!=c1) return false;

            s1[c1]=c2;
            t1[c2]=c1;
        }
        return true;
    }
};