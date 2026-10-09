class Solution {
public:
    int mirrorDistance(int n) {
        int temp = n;
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int rev = stoi(s);
        return abs(temp - rev);
    }
};