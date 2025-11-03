class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string temp = "";
        for (int i = 0; i < n; i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
                isdigit(s[i])) {
                temp.push_back(tolower(s[i]));
            }
        }

        int left = 0, right = temp.size() - 1;
        while (left < right) {
            if (temp[left] != temp[right])
                return false;
            right--;
            left++;
        }
        return true;
    }
};