class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long long>> dpMax(m, vector<long long>(n));
        vector<vector<long long>> dpMin(m, vector<long long>(n));

        dpMax[0][0] = dpMin[0][0] = grid[0][0];

        for(int j = 1; j < n; j++){
            dpMax[0][j] = dpMin[0][j] = dpMax[0][j-1] * grid[0][j];
        }
        for(int i = 1; i < m; i++){
            dpMax[i][0] = dpMin[i][0] = dpMax[i-1][0] * grid[i][0];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){

                long long val = grid[i][j];

                long long a = dpMax[i-1][j] * val;
                long long b = dpMin[i-1][j] * val;
                long long c = dpMax[i][j-1] * val;
                long long d = dpMin[i][j-1] * val;

                dpMax[i][j] = max({a, b, c, d});
                dpMin[i][j] = min({a, b, c, d});
            }
        }
        long long ans = dpMax[m-1][n-1];
        if(ans < 0) return -1;
        return ans % 1000000007;
    }
};