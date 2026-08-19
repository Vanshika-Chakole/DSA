class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, int> rows;

        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int s = seat[1];

            rows[row] |= (1 << (s - 1));
        }

        long long ans = 2LL * (n - rows.size());

        for (auto &[row, mask] : rows) {

            bool left = true;
            bool middle = true;
            bool right = true;

            for (int s = 2; s <= 5; s++) {
                if (mask & (1 << (s - 1))) {
                    left = false;
                }
            }
            for (int s = 4; s <= 7; s++) {
                if (mask & (1 << (s - 1))) {
                    middle = false;
                }
            }
            for (int s = 6; s <= 9; s++) {
                if (mask & (1 << (s - 1))) {
                    right = false;
                }
            }

            if (left && right) {
                ans += 2;
            }
            else if (left || middle || right) {
                ans += 1;
            }
        }
        return ans;
    }
};