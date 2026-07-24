class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> cur(MAXX, false), nxt(MAXX, false);
        cur[0] = true;

        for (int step = 0; step < 3; step++) {
            fill(nxt.begin(), nxt.end(), false);

            for (int x = 0; x < MAXX; x++) {
                if (!cur[x]) continue;
                for (int v : nums) {
                    nxt[x ^ v] = true;
                }
            }

            cur.swap(nxt);
        }

        int ans = 0;
        for (bool ok : cur)
            if (ok) ans++;

        return ans;
    }
};