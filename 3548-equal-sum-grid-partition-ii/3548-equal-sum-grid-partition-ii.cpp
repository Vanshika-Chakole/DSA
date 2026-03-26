#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool canRemove(int r1, int r2, int c1, int c2, int r, int c) {
        int h = r2 - r1 + 1;
        int w = c2 - c1 + 1;

        if (h > 1 && w > 1) return true;

        if (h == 1) return (c == c1 || c == c2);
        if (w == 1) return (r == r1 || r == r2);

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        long long total = 0;
        unordered_map<int,int> right;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
                right[grid[i][j]]++;
            }
        }

        unordered_map<int,int> left;
        long long sum = 0;

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                sum += val;
                left[val]++;
                if (--right[val] == 0) right.erase(val);
            }

            long long other = total - sum;
            if (sum == other) return true;

            long long diff = abs(sum - other);

            if (sum > other) {
                if (left.count(diff)) {
                    for (int r = 0; r <= i; r++) {
                        for (int c = 0; c < n; c++) {
                            if (grid[r][c] == diff &&
                                canRemove(0, i, 0, n-1, r, c))
                                return true;
                        }
                    }
                }
            } else {
                if (right.count(diff)) {
                    for (int r = i+1; r < m; r++) {
                        for (int c = 0; c < n; c++) {
                            if (grid[r][c] == diff &&
                                canRemove(i+1, m-1, 0, n-1, r, c))
                                return true;
                        }
                    }
                }
            }
        }

        unordered_map<int,int> down;
        for (auto &row : grid)
            for (auto &x : row)
                down[x]++;

        unordered_map<int,int> up;
        sum = 0;

        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                int val = grid[i][j];
                sum += val;
                up[val]++;
                if (--down[val] == 0) down.erase(val);
            }

            long long other = total - sum;
            if (sum == other) return true;

            long long diff = abs(sum - other);

            if (sum > other) {
                if (up.count(diff)) {
                    for (int r = 0; r < m; r++) {
                        for (int c = 0; c <= j; c++) {
                            if (grid[r][c] == diff &&
                                canRemove(0, m-1, 0, j, r, c))
                                return true;
                        }
                    }
                }
            } else {
                if (down.count(diff)) {
                    for (int r = 0; r < m; r++) {
                        for (int c = j+1; c < n; c++) {
                            if (grid[r][c] == diff &&
                                canRemove(0, m-1, j+1, n-1, r, c))
                                return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};