class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto it : freq) {
            pq.push({it.second, it.first});
        }

        string ans = "";
        while (pq.size() >= 2) {
            auto fir = pq.top();
            pq.pop();
            auto sec = pq.top();
            pq.pop();

            ans += fir.second;
            ans += sec.second;
            fir.first--;
            sec.first--;

            if (fir.first > 0) {
                pq.push(fir);
            }
            if (sec.first > 0) {
                pq.push(sec);
            }
        }

        if (!pq.empty()) {
            if (pq.top().first > 1)
                return "";
            ans += pq.top().second;
        }
        return ans;
    }
};