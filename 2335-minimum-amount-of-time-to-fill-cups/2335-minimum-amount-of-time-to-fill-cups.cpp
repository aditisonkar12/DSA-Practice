class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for (int a : amount) {
            pq.push(a);
        }

        int time = 0;
        while (!pq.empty()) {
            int n = pq.top();
            pq.pop();

            if (pq.empty()) { // when only one time of cup remains simply add n
                              // to the time as every sec only one type of cup
                              // can be filled
                if (n > 0) {
                    time += n;
                }
                break;
            }

            int m = pq.top();
            pq.pop();

            if (n == 0 && m == 0)
                break;
            if (n > 0)
                n--;
            if (m > 0)
                m--;

            time++;
            pq.push(n);
            pq.push(m);
        }
        return time;
    }
};