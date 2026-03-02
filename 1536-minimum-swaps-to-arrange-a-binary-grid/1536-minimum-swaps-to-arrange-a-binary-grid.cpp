class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> lastone(n);

        for(int i = 0; i < n; i++){
            lastone[i] = -1;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1)
                lastone[i] = j;
            }
        }
    

    int swaps = 0;
    for(int i = 0; i < n; i++){
        int j = i;
        while(j < n && lastone[j] > i)
        j++;
        if(j == n)
        return -1;
        while(j > i){
            swap(lastone[j], lastone[j - 1]);
            swaps++;
            j--;
        }
    }
    return swaps;
    }
};