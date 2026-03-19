class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> px(m, vector<int>(n, 0));
        vector<vector<int>> py(m, vector<int>(n, 0));
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'X') px[i][j] = 1;
                if(grid[i][j] == 'Y') py[i][j] = 1;
                if(i > 0){
                    px[i][j] += px[i-1][j];
                    py[i][j] += py[i-1][j];
                }
                if(j > 0){
                    px[i][j] += px[i][j-1];
                    py[i][j] += py[i][j-1];
                }

                if(i > 0 && j > 0){
                    px[i][j] -= px[i-1][j-1];
                    py[i][j] -= py[i-1][j-1];
                }
       if(px[i][j] == py[i][j] && px[i][j] > 0){
                    count++;
                }
            }
        }
        return count;
    }
};