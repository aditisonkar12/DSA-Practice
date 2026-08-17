class Solution {
public:
    int reverseNum(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }
        return rev;
    }

    bool isSameAfterReversals(int num) {
        int temp = num;
        num = reverseNum(num);
        num = reverseNum(num);
        return temp == num;
        // if (num == 0)
        //     return true;
        // return num % 10 != 0;
    }
};