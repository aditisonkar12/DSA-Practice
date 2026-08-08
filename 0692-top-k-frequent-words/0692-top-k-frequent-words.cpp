class Solution {
public:
    struct cmp {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        vector<string> ans;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        unordered_map<string, int> freq;
        for (string s : words) {
            freq[s]++;
        }

        for (auto it : freq) {
            string x = it.first;
            int f = it.second;
            pq.push({f, x});
        }

        while (k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};