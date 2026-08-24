class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> freq;

        for (char c : sentence) {
            freq[c]++;
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (freq[c] == 0) {
                return false;
            }
        }
        return true;
    }
};