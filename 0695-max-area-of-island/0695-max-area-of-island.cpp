class Solution {
public:
    vector<int> parent, sz;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        parent[py] = px;
        sz[px] += sz[py];
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        parent.resize(m * n);
        sz.assign(m * n, 0);

        for (int i = 0; i < m * n; i++)
            parent[i] = i;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1)
                    sz[i * n + j] = 1;
            }
        }

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) continue;

                int id1 = i * n + j;

                for (auto &d : dir) {

                    int ni = i + d[0];
                    int nj = j + d[1];

                    if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                        grid[ni][nj] == 1) {

                        int id2 = ni * n + nj;

                        if (find(id1) != find(id2))
                            unite(id1, id2);
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < m * n; i++) {
            if (parent[i] == i)
                ans = max(ans, sz[i]);
        }

        return ans;
    }
};