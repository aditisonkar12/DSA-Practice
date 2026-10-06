class Solution {
public:
    long long minimumSteps(string s) {
        long long moves = 0;
        long long countZeros = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0') {
                moves += i - countZeros;
                countZeros++;
            }
        }
        return moves;
        // long last=0;
        // long minCount=0;
        // for(int cur=0;cur<s.length();cur++){
        //     if(s[cur]== '0'){
        //         minCount+=(cur-last);
        //         last++;
        //     }
        // }
        // return minCount;
    }
};