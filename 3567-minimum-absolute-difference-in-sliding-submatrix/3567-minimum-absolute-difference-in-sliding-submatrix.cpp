class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));

        for(int i = 0; i <= m - k; i++){
            for(int j = 0; j <= n - k; j++){
                vector<int> v;
                for(int x = i; x < i + k; x++){
                    for(int y = j; y < j + k; y++){
                        v.push_back(grid[x][y]);
                    }
                }
                sort(v.begin(), v.end());
                 int mini = INT_MAX;
                for(int t = 1; t < v.size(); t++){
                    if(v[t] != v[t-1])   
                           mini = min(mini, v[t] - v[t-1]);
                }
                if(mini == INT_MAX) mini = 0;
                ans[i][j] = mini;
            }
        }
        return ans;
    }
};