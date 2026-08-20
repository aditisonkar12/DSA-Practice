class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }

    string toGoatLatin(string sentence) {
        int n = sentence.size();
        string ans = "";
        string word;
        int idx = 1;
        for (int i = 0; i <= n; i++) {
            if (i == n || sentence[i] == ' ') {
                if (isVowel(word[0])) {
                    ans += word;
                } else {
                    ans += word.substr(1);
                    ans += word[0];
                }

                ans += "ma";
                for (int i = 0; i < idx; i++) {
                    ans += 'a';
                }
                idx++;

                if (i != n) {
                    ans += ' ';
                }
                word = "";
            } else {
                word += sentence[i];
            }
        }
        return ans;
    }
};