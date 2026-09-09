class Solution {
public:
    bool isPalindrome(string s) {
        // string temp = "";
        // int n = s.size();

        // for (int i = 0; i < n; i++) {
        //     if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')
        //     ||
        //         isdigit(s[i])) {
        //         temp.push_back(tolower(s[i]));
        //     }
        // }

        // int left = 0, right = temp.size() - 1;
        // while (left < right) {
        //     if (temp[left] != temp[right])
        //         return false;
        //     left++;
        //     right--;
        // }
        // return true;
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left]))
                left++;
            while (left < right && !isalnum(s[right]))
                right--;
            if (tolower(s[left]) != tolower(s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
};