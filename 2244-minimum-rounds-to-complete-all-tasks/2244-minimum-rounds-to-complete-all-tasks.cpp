class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end());
        unordered_map<int, int> freq;
        for (int i : tasks) {
            freq[i]++;
        }

        int cnt = 0;
        for (auto& it : freq) {
            // int val = it.first;
            int c = it.second;
            if (c == 1)
                return -1;
            cnt += c / 3;
            if (c % 3 != 0) {
                cnt++;
            }
        }
        return cnt;
    }
};