class Solution {
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void update(int i, int val) {
            for (; i <= n; i += i & -i)
                bit[i] ^= val;
        }

        int query(int i) {
            int res = 0;
            for (; i > 0; i -= i & -i)
                res ^= bit[i];
            return res;
        }

        void rangeUpdate(int l, int r, int val) {
            update(l, val);
            update(r + 1, val);
        }
    };

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> depth(n), tin(n), tout(n), pref(n);
        int timer = 0;

        auto mask = [&](char c) {
            return 1 << (c - 'a');
        };

        vector<tuple<int, int, bool>> st;
        st.push_back({0, -1, false});

        while (!st.empty()) {
            auto [u, p, exit] = st.back();
            st.pop_back();

            if (exit) {
                tout[u] = timer;
                continue;
            }

            tin[u] = ++timer;

            if (p == -1) {
                depth[u] = 0;
                up[0][u] = u;
                pref[u] = mask(s[u]);
            } else {
                depth[u] = depth[p] + 1;
                up[0][u] = p;
                pref[u] = pref[p] ^ mask(s[u]);
            }

            for (int k = 1; k < LOG; k++)
                up[k][u] = up[k - 1][up[k - 1][u]];

            st.push_back({u, p, true});

            for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                int v = adj[u][i];
                if (v != p)
                    st.push_back({v, u, false});
            }
        }

        Fenwick fw(n);

        auto getLCA = [&](int u, int v) {
            if (depth[u] < depth[v])
                swap(u, v);

            int diff = depth[u] - depth[v];

            for (int k = 0; k < LOG; k++)
                if (diff & (1 << k))
                    u = up[k][u];

            if (u == v) return u;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }

            return up[0][u];
        };

        auto getPrefix = [&](int u) {
            return pref[u] ^ fw.query(tin[u]);
        };

        vector<bool> answer;

        for (string &q : queries) {
            string type;
            int u, v;
            char c;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                ss >> c;

                int delta = mask(s[u]) ^ mask(c);

                fw.rangeUpdate(tin[u], tout[u], delta);
                s[u] = c;
            } else {
                ss >> v;

                int lca = getLCA(u, v);

                int pathMask = getPrefix(u)
                             ^ getPrefix(v)
                             ^ mask(s[lca]);

                answer.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return answer;
    }
};