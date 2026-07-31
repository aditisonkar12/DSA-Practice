class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int cnt = 0;
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }

        sort(freq.rbegin(), freq.rend());

        for (int i = 0; i < 26; i++) {
            cnt += freq[i] * (i / 8 + 1);
        }
        return cnt;
    }
};