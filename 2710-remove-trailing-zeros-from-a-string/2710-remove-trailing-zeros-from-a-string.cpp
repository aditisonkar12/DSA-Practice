class Solution {
public:
    string removeTrailingZeros(string num) {
        int n=num.size();
        int j=n-1;
        while(j>=0 && num[j]=='0'){
            j--;
        }
        num.erase(j+1);
        return num;
    }
};