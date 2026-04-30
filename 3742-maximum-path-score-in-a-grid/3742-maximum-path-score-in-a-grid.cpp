class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        const int NEG = -1e9;

        vector<vector<int>> dp(n, vector<int>(k+1, NEG));

        dp[0][0] = 0; 

        for (int i = 0; i < m; i++) {

            vector<vector<int>> newdp(n, vector<int>(k+1, NEG));

            for (int j = 0; j < n; j++) {

                int val = grid[i][j];
                int cost = (val == 0 ? 0 : 1);
                int score = val;

                for (int c = 0; c <= k; c++) {

                    if (i == 0 && j == 0) {
                        if (c == 0) newdp[j][c] = 0;
                        continue;
                    }

                    int best = NEG;

                    if (i > 0 && dp[j][c] != NEG) {
                        best = max(best, dp[j][c]);
                    }

                    if (j > 0 && newdp[j-1][c] != NEG) {
                        best = max(best, newdp[j-1][c]);
                    }

                    if (best == NEG) continue;

                    int nc = c + cost;
                    if (nc <= k) {
                        newdp[j][nc] = max(newdp[j][nc], best + score);
                    }
                }
            }

            dp = newdp;
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[n-1][c]);
        }

        return ans < 0 ? -1 : ans;
    }
};