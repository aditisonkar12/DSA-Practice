class Solution {
public:
    struct Node {
        char lc, rc;
        int pref, suff, mx, len;

        Node() {
            lc = rc = '#';
            pref = suff = mx = len = 0;
        }

        Node(char c) {
            lc = rc = c;
            pref = suff = mx = len = 1;
        }
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {
        if (a.len == 0)
            return b;

        if (b.len == 0)
            return a;

        Node res;
        res.lc = a.lc;
        res.rc = b.rc;
        res.len = a.len + b.len;
        res.pref = a.pref;
        res.suff = b.suff;
        res.mx = max(a.mx, b.mx);

        if (a.rc == b.lc) {
            res.mx = max(res.mx, a.suff + b.pref);
            if (a.pref == a.len)
                res.pref = a.len + b.pref;

            if (b.suff == b.len)
                res.suff = b.len + a.suff;
        }
        return res;
    }

    void build(int node, int l, int r, string& s) {
        if (l == r) {
            seg[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;
        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);
        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            seg[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node, l, mid, idx, c);
        else
            update(2 * node + 1, mid + 1, r, idx, c);

        seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        int n = s.size();
        seg.resize(4 * n);
        build(1, 0, n - 1, s);
        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {
            update(1, 0, n - 1, queryIndices[i],
                   queryCharacters[i]);

            ans.push_back(seg[1].mx);
        }
        return ans;
    }
};