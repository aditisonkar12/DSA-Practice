class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> freq;
        priority_queue<pair<int, char>> pq;

        for (char c : s){ 
            freq[c]++;
        }

        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        string ans;
        while (!pq.empty()) {
            auto c = pq.top();
            pq.pop();
            ans += string(c.first, c.second);
        }
        return ans;
    }
};