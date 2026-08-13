class Solution {
public:

    struct Node {
        int len;
        int pref, suff, best;
        char lc, rc;

        Node() {
            len = 0;
            pref = suff = best = 0;
            lc = rc = '#';
        }
    };

    vector<Node> seg;
    string s;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        // Prefix
        res.pref = a.pref;

        if (a.pref == a.len && a.rc == b.lc) {
            res.pref = a.len + b.pref;
        }

        // Suffix
        res.suff = b.suff;

        if (b.suff == b.len && a.rc == b.lc) {
            res.suff = b.len + a.suff;
        }

        // Best answer inside left/right
        res.best = max(a.best, b.best);

        // Best substring crossing the middle
        if (a.rc == b.lc) {
            res.best = max(res.best, a.suff + b.pref);
        }

        return res;
    }

    void build(int node, int l, int r) {

        if (l == r) {
            seg[node].len = 1;
            seg[node].pref = 1;
            seg[node].suff = 1;
            seg[node].best = 1;
            seg[node].lc = s[l];
            seg[node].rc = s[l];
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {

        if (l == r) {
            seg[node].lc = c;
            seg[node].rc = c;
            seg[node].pref = 1;
            seg[node].suff = 1;
            seg[node].best = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        this->s = s;

        int n = s.size();

        seg.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int idx = queryIndices[i];
            char c = queryCharacters[i];

            s[idx] = c;

            update(1, 0, n - 1, idx, c);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};