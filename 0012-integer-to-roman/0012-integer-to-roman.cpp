class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string, int>> temp = {
            {"I", 1},   {"IV", 4},   {"V", 5},   {"IX", 9},  {"X", 10},
            {"XL", 40}, {"L", 50},   {"XC", 90}, {"C", 100}, {"CD", 400},
            {"D", 500}, {"CM", 900}, {"M", 1000}};

        string ans = "";
        int n = temp.size();
        for (int i = n - 1; i >= 0; --i) {
            string roman = temp[i].first;
            int integer = temp[i].second;

            if (num / integer) {
                int count = num / integer;
                for (int j = 0; j < count; ++j) {
                    ans += roman;
                }
                num %= integer;
            }
        }
        return ans;
    }
};