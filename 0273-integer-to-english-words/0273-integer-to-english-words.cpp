class Solution {
public:
    vector<string> ones = {"",        "One",       "Two",      "Three",
                           "Four",    "Five",      "Six",      "Seven",
                           "Eight",   "Nine",      "Ten",      "Eleven",
                           "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                           "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    vector<string> tens = {"",      "",      "Twenty",  "Thirty", "Forty",
                           "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string solve(int n) {
        string ans = "";

        if (n >= 100) {
            ans += ones[n / 100] + " Hundred ";
            n %= 100;
        }
        if (n >= 20) {
            ans += tens[n / 10] + " ";
            n %= 10;
        }
        if (n > 0) {
            ans += ones[n] + " ";
        }
        return ans;
    }

    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        string ans = "";
        if (num >= 1000000000) {
            ans += solve(num / 1000000000) + "Billion ";
            num %= 1000000000;
        }
        if (num >= 1000000) {
            ans += solve(num / 1000000) + "Million ";
            num %= 1000000;
        }
        if (num >= 1000) {
            ans += solve(num / 1000) + "Thousand ";
            num %= 1000;
        }
        if (num > 0) {
            ans += solve(num);
        }

        while (ans.back() == ' ')
            ans.pop_back();

        return ans;
    }
};